#pragma once



#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include "MetaLib/rapidxml_iterators.hpp"
#include "MetaLib/rapidxml_utils.hpp"
#include "MetaLib/rapidxml_ext.h"


#include "MetaLib/Meta.h"
#include "MetaLib/StringCast.h"
#include "qdialog.h"
#include "qtextedit.h"
#include "qradiobutton.h"
#include "qlistwidget.h"
#include "qboxlayout.h"
#include "qtablewidget.h"

#include "MetaLib/magic_enum.hpp"


namespace meta
{
	// Buttons are for adding to vectors or unordered maps
	// If the member is a registered member itself (and not a vector/unordered map of said type)
	// Then have that member be configured through a tab


	template <typename Class,
		typename = std::enable_if_t <meta::isRegistered<Class>()>>
		void makeDialog(Class & obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue<std::shared_ptr<QWidget>> & widgetVec, std::function<void(Class & obj)> setter, std::function<bool(Class & val)> validator);

	template <typename Class,
		typename = std::enable_if_t <!meta::isRegistered<Class>()>,
		typename = void>
		void makeDialog(Class & obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue<std::shared_ptr<QWidget>> & widgetVec, std::function<void(Class & obj)> setter, std::function<bool(Class & val)> validator);
	template<typename Class, bool isEnum>
	void makeDialog_enum(Class& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(Class& obj)> setter, std::integral_constant<bool, isEnum>);

	//template <typename Class,
	//typename = std::enable_if<std::is_enum<Class>::value>>
	//void makeDialog_basic(Class& obj, std::shared_ptr<QWidget> parent,
		//std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(Class& obj)> setter);

	template <typename Class,
		bool isEnum = std::is_enum<Class>::value>
		void makeDialog_basic(Class & obj, std::shared_ptr<QWidget> parent,
			std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>> & widgetVec, std::function<void(Class & obj)> setter, std::function<bool(Class & val)> validator);


	template <>
	void makeDialog_basic(bool& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(bool& obj)> setter, std::function<bool(bool& val)> validator);

	template <typename T>
	void makeDialog_basic(typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value>::type& obj, std::shared_ptr<QWidget> parent,
		std::shared_ptr<QBoxLayout> layout, std::queue < std::shared_ptr<QWidget>>& widgetVec, std::function<void(T& obj)> setter, std::function<bool(T& val)> validator);


	// specialization for std::vector
	template <typename T>
	void makeDialog_basic(std::vector<T>& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue<std::shared_ptr<QWidget>>& widgetVec,
		std::function<void(std::vector<T>& obj)> setter, std::function<bool(std::vector<T>& val)> validator);


	//template <typename T>
	//void makeDialog_basic(typename std::enable_if<std::is_floating_point<T>::value>::type& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout,
	//	std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(T& obj)> setter);


	// specialization for std::unodered_map
	template <typename K, typename V>
	void makeDialog_basic(std::unordered_map<K, V>& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue<std::shared_ptr<QWidget>>& widgetVec, 
		std::function<void(std::unordered_map<K, V>& obj)> setter, std::function<bool(std::unordered_map<K, V>& val)> validator);

	template <typename Class,
		typename = std::enable_if_t <meta::isRegistered<Class>() >>
		void generateDialog(Class & obj);


	template <typename T>
	void determineRange(int64_t& min,
		int64_t& max, std::function<bool(T& obj)> validator);



	template <typename Class,
		typename = std::enable_if_t <meta::isRegistered<Class>()>>
		void makeDialog(Class & obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue<std::shared_ptr<QWidget>> & widgetVec, std::function<void(Class & obj)> setter, std::function<bool(Class & val)> validator)
	{

		const uint16_t MAX_ITEM_COUNT = 5;
		const uint16_t MAX_MEMBER_COUNT = 4;

		// Want to add a slot that will populate the contents of the member associated with the new widget
		// Use the StringCast code to aid this process
		//std::shared_ptr<QWidget> widget = std::make_shared<QWidget>();

		//std::shared_ptr<QVBoxLayout> childLayout = std::make_shared<QVBoxLayout>(widget.get());
		//layout->addLayout(childLayout.get());

		std::size_t numMembers = meta::getMemberCount<Class>();

		if (layout->count() > MAX_ITEM_COUNT && numMembers > MAX_MEMBER_COUNT)
		{
			std::shared_ptr<QVBoxLayout> newLayout = std::make_shared<QVBoxLayout>();
			std::shared_ptr<QPushButton> button = std::make_shared<QPushButton>();
			layout->addWidget(button.get());
			parent->connect(button.get(), &(QRadioButton::clicked), [&button, setter, &widgetVec, &obj, newLayout, validator](bool val) {
				std::shared_ptr<QDialog> newDialog = std::make_shared<QDialog>();
				makeDialog(obj, newDialog, newLayout, widgetVec, setter, validator);
				});
			widgetVec.push(button);

		}
		else
		{

			meta::doForAllMembers<Class>(
				[&obj, &parent, &layout, &widgetVec, setter](auto& member)
				{
					std::shared_ptr<QLabel> memName = std::make_shared<QLabel>(member.getName());
					layout->addWidget(memName.get());
					widgetVec.push(memName);

					using MemberT = meta::get_member_type<decltype(member)>;
					if (member.hasGetter())
					{
						MemberT val;

						makeDialog<MemberT>(val, parent, layout, widgetVec, [member, &obj, setter](MemberT& mem) {
								if (member.isValid(obj, mem))
								{
									member.set(obj, mem);
									setter(obj);
								}
							},
							[member, &obj](MemberT& mem) -> bool {


								return member.isValid(obj, mem);

							}
							);
						// Create slot with setter ... which it has to have (since it has a getter)


					}
					else if (member.canGetConstRef())
					{
						MemberT val;
						makeDialog<MemberT>(val, parent, layout, widgetVec, [member, &obj, setter](MemberT& mem) {
								if (member.isValid(obj, mem))
								{
									member.getRef(obj) = mem;
									setter(obj);
								}
							},
							[member, &obj](MemberT& mem) -> bool {
							
							
								return member.isValid(obj, mem);
							
							});


					}



				}
			);
			//widget->setLayout(childLayout.get());
		}
	}

	template <typename Class,
		typename = std::enable_if_t <!meta::isRegistered<Class>()>,
		typename = void>
		void makeDialog(Class & obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>> & widgetVec, std::function<void(Class & obj)> setter, std::function<bool(Class & val)> validator)
	{


		makeDialog_basic(obj, parent, layout, widgetVec, setter, validator);


	}

	template <typename Class,
		bool isEnum = std::is_enum<Class>::value>
		void makeDialog_basic(Class & obj, std::shared_ptr<QWidget> parent,
			std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>> & widgetVec, std::function<void(Class & obj)> setter, std::function<bool(Class & val)> validator)
	{

		// For general case, we can only treat class as a string for data to be written to
		//std::shared_ptr<QTextEdit> textBox = std::make_shared<QTextEdit>();


		if (std::is_integral<Class>::value && !std::is_same<Class, bool>::value)
		{
			std::shared_ptr<QSpinBox> spinBox = std::make_shared<QSpinBox>();
			int64_t min;
			int64_t max;
			determineRange(min, max, validator);
			spinBox->setMinimum(min);
			spinBox->setMaximum(max);


			// Coonnect signal/slot
			layout->addWidget(spinBox.get());
			widgetVec.push(spinBox);
		}
		else if (std::is_enum<Class>::value)
		{

			makeDialog_enum<Class>(obj, parent, layout, widgetVec, setter, std::integral_constant<bool, isEnum>{});
		}
		else
		{
			std::shared_ptr<QLineEdit> textBox = std::make_shared<QLineEdit>(/*parent.get()*/);
			layout->addWidget(textBox.get());

			textBox->connect(textBox.get(), &(QLineEdit::textChanged), [setter, textBox]() {
				Class val = fromString<Class>(textBox->text().toUtf8().constData());
				setter(val);



				});

			widgetVec.push(textBox);
		}
	}




	template<typename Class>
	void makeDialog_enum(Class& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(Class& obj)> setter, std::true_type)
	{
		std::shared_ptr<QComboBox> combo = std::make_shared<QComboBox>();
		// Coonnect signal/slot

		for (const auto& enumName : magic_enum::enum_names<Class>())
		{
			combo->addItem(QString(std::string(enumName).c_str()));

			combo->connect(combo.get(), &QComboBox::currentTextChanged, [setter](const QString& text) {

				auto enumVal = magic_enum::enum_cast<Class>(text.toUtf8().constData());
				setter(enumVal.value());
				});
		}


		layout->addWidget(combo.get());
		widgetVec.push(combo);
	}

	template<typename Class>
	void makeDialog_enum(Class& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(Class& obj)> setter, std::false_type)
	{

	}


	template <>
	void makeDialog_basic(bool& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(bool& obj)> setter, std::function<bool(bool& val)> validator)
	{

		std::shared_ptr<QRadioButton> button = std::make_shared<QRadioButton>();
		layout->addWidget(button.get());
		parent->connect(button.get(), &(QRadioButton::clicked), [&button, setter](bool val) {
			setter(val);
			});
		widgetVec.push(button);
	}
	template <>
	void makeDialog_basic(double& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue< std::shared_ptr<QWidget>>& widgetVec, std::function<void(double& obj)> setter, std::function<bool(double& val)> validator)
	{


		std::shared_ptr<QDoubleSpinBox> spinBox = std::make_shared<QDoubleSpinBox>();

		int64_t min;
		int64_t max;
		
		determineRange(min, max, validator);

		spinBox->setMinimum(min);
		spinBox->setMaximum(max);


		double val = spinBox->value();
		setter(val);
		// Coonnect signal/slot
		layout->addWidget(spinBox.get());
		parent->connect(spinBox.get(), SIGNAL(QDoubleSpinBox::valueChanged(double)), spinBox.get(), SLOT([spinBox, setter](double val) {
			setter(val);

			}));
		widgetVec.push(spinBox);

	}

	template <typename T>
	void makeDialog_basic(typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value>::type& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, 
		std::queue < std::shared_ptr<QWidget>>& widgetVec, std::function<void(T& obj)> setter, std::function<bool(T& val)> validator)
	{
		std::shared_ptr<QSpinBox> spinBox = std::make_shared<QSpinBox>();
		// Coonnect signal/slot
		T min;
		T max;
		determineRange(min, max, validator);
		spinBox->setMinimum(min);
		spinBox->setMaximum(max);

		layout->addWidget(spinBox.get());
		widgetVec.push(spinBox);


	}

	// specialization for std::vector
	template <typename T>
	void makeDialog_basic(std::vector<T>& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue < std::shared_ptr<QWidget>>& widgetVec, 
		std::function<void(std::vector<T>& obj)> setter, std::function<bool(std::vector<T>& val)> validator)
	{
		//std::shared_ptr<QWidget> boxWidget = std::make_shared<QWidget>(parent.get());

		//std::shared_ptr<QVBoxLayout> vbox = std::make_shared<QVBoxLayout>(boxWidget.get());
		//layout->addLayout(vbox.get());


		std::shared_ptr<QTableWidget> tableWidget = std::make_shared<QTableWidget>();


		if (meta::isRegistered<T>())
		{
		
			tableWidget->setColumnCount(meta::getMemberCount<T>());
			uint16_t col = 0;
			meta::doForAllMembers<T>(
				[&obj, &parent, &layout, &widgetVec, setter, &tableWidget, &col](auto& member)
				{
					QString nameStr(member.getName());
					QTableWidgetItem* memName = new QTableWidgetItem(nameStr);
				
					//widgetVec.push(memName);
					QString temp = memName->text();
					tableWidget->setHorizontalHeaderItem(col, memName);
					//layout->addWidget(memName.get());
					//widgetVec.push(memName);
					col++;
				}
			);
		}






		std::shared_ptr<QPushButton> addButton = std::make_shared<QPushButton>("Add");

		std::shared_ptr<T> comp = std::make_shared<T>();
		std::shared_ptr<std::vector<T>> compVec = std::make_shared<std::vector<T>>();
		makeDialog<T>(*(comp.get()), (parent), layout, widgetVec, [comp](T& c) {
			// Add c to vector
			*(comp.get()) = c;

			}, [](T& val) -> bool {return true; });

		
		parent->connect(addButton.get(), &QPushButton::clicked, [&addButton, compVec, &parent, setter, comp, tableWidget, validator](bool val) {

			//obj.push_back(*comp);

			
			std::vector<T> tempVec = *(compVec.get());
			tempVec.push_back(*(comp.get()));
			if (validator(tempVec))
			{
				compVec->push_back(*(comp.get()));
				setter(*(compVec.get()));
				std::string str = castToString(*(comp.get()));

				int32_t row = tableWidget->rowCount();
				tableWidget->setRowCount(row + 1);
				int32_t col = 0;
				meta::doForAllMembers<T>(
					[&tableWidget, &col, &comp, row](auto& member)
					{
						// Get each member and populate it into the correct col
						using MemberT = meta::get_member_type<decltype(member)>;

						if (member.hasGetter())
						{

							T object = *(comp.get());
							MemberT val = member.getCopy(object);
							std::string valStr = castToString(val);

							QTableWidgetItem* cellWidget = new QTableWidgetItem(QString(valStr.c_str()));

							tableWidget->setItem(row, col, cellWidget);
						}
						else if (member.canGetConstRef())
						{
							T object = *(comp.get());
							MemberT val = member.getRef(object);

							std::string valStr = castToString(val);

							QTableWidgetItem* cellWidget = new QTableWidgetItem(QString(valStr.c_str()));

							tableWidget->setItem(row, col, cellWidget);
						}


						col++;

					}
				);
			}
			});

		layout->addWidget(addButton.get());
		layout->addWidget(tableWidget.get());

		parent->connect(tableWidget.get(), &QTableWidget::customContextMenuRequested, [&obj, &tableWidget](const QPoint& pnt) {


			});
		//boxWidget->setLayout(vbox.get());
		// perhaps return a view widget instead and embed add button and listwidget in that

		widgetVec.push(addButton);
		widgetVec.push(tableWidget);
	}

	// specialization for std::unodered_map
	template <typename K, typename V>
	void makeDialog_basic(std::unordered_map<K, V>& obj, std::shared_ptr<QWidget> parent, std::shared_ptr<QBoxLayout> layout, std::queue < std::shared_ptr<QWidget>>& widgetVec, 
		std::function<void(std::unordered_map<K, V>& obj)> setter, std::function<bool(std::unordered_map<K,V>& val)> validator)
	{
		//std::shared_ptr<QWidget> boxWidget = std::make_shared<QWidget>(parent.get());



		std::shared_ptr<QVBoxLayout> vbox = std::make_shared<QVBoxLayout>();

		layout->addLayout(vbox.get());

		std::shared_ptr<QListWidget> listWidget = std::make_shared<QListWidget>();
		layout->addWidget(listWidget.get());
		std::shared_ptr<K> key = std::make_shared<K>();
		makeDialog<K>(*(key.get()), (parent), layout, widgetVec, [&key](K& k) {

			}, [](K& val) -> bool {return true; });

		std::shared_ptr<V> val = std::make_shared<V>();
		makeDialog<V>(*(val.get()), (parent), layout, widgetVec, [&val](V& v) {

			}, [](V& val) -> bool {return true; });

		std::shared_ptr<QPushButton> addButton = std::make_shared<QPushButton>();
		layout->addWidget(addButton);
		boxWidget->connect(addButton.get(), &QPushButton::clicked, [&obj, &parent, &listWidget](bool val) {


			obj.insert(std::pair<K, V>(key, val));
			std::shared_ptr<QListWidgetItem> item = std::make_shared<QListWidgetItem>();
			//need a way to update listwidget after the val dialog/key Dialog are populated
				/*meta::doForAllMembers<K>(
					[&obj, &item, &parent](auto& member)
					{
						if (meta::isRegistered<K>())
						{


						}
						else
						{


						}
					};
				meta::doForAllMembers<V>(
					[&obj, &listWidget, &parent](auto& member)
					{
						if (meta::isRegistered<V>())
						{


						}
						else
						{


						}
					};*/
			});



		parent->connect(listWidget.get(), &QListWidget::customContextMenuRequested, [&obj, &listWidget](const QPoint& pnt) {


			});

		widgetVec.push(listWidget);
		widgetVec.push(addButton);
	}

	template <typename Class,
		typename = std::enable_if_t <meta::isRegistered<Class>() >>
		void generateDialog(Class & obj)

	{
		std::queue<std::shared_ptr<QWidget>> widgetVec;

		std::shared_ptr<QDialog> dialog = std::make_shared<QDialog>(nullptr);
		std::shared_ptr<QVBoxLayout> layout = std::make_shared<QVBoxLayout>();
		makeDialog<Class>(obj, std::static_pointer_cast<QWidget, QDialog>(dialog), layout, widgetVec, [](Class& obj2)
			{




			}, [](Class& obj) -> bool {
				return true;
			});
		std::shared_ptr<QPushButton> saveBtn = std::make_shared<QPushButton>("Save");
		std::shared_ptr<QPushButton> cancelBtn = std::make_shared<QPushButton>("Cancel");

		//std::vector<double> f;
		//double f;
		//makeDialog_basic<decltype(f)>(f, std::static_pointer_cast<QWidget, QDialog>(dialog), layout, widgetVec, [](decltype(f)& obj) {});

		layout->addWidget(saveBtn.get());
		layout->addWidget(cancelBtn.get());

		//layout->addWidget(widget.get());
		dialog->setLayout(layout.get());
		dialog->exec();

		layout->removeWidget(saveBtn.get());
		layout->removeWidget(cancelBtn.get());
		int g = layout->count();
		while (widgetVec.size() > 0)
		{
			std::shared_ptr<QWidget> widget = widgetVec.front();


			layout->removeWidget(widget.get());
			widget->setParent(nullptr);
			widgetVec.pop();

		}
		int f = layout->count();

	}


	template <typename T>
	void determineRange(
		int64_t& min,
		int64_t& max,
		std::function<bool(T& obj)> validator)
	{

		auto cast = [](T val) -> int64_t {
			if (val > T(std::numeric_limits<int64_t>::max()))
			{
				return std::numeric_limits<int64_t>::max();
			}
			else if (val < T(std::numeric_limits<int64_t>::min()))
			{
				return std::numeric_limits<int64_t>::min();
			}
			else
			{
				return static_cast<int64_t>(val);
			}
		};

		T typemin = std::numeric_limits<T>::lowest();
		T typemax = std::numeric_limits<T>::max();

		min = cast(typemin);
		max = cast(typemax);

		// Entire range of type is valid, so just return
		if (validator(typemin) && validator(typemax))
		{
			return;
		}


		// Determine true max value
		// Right now min is the most negative number (or 0)
		// Crossing is going from valid to not valid
		T tempMin = static_cast<T>(0);
		T tempMax = static_cast<T>(max);
		while (!validator(typemax))
		{
			T m = static_cast<T>(max);
			T mn = static_cast<T>(max - 1);
			if (!validator(m) && validator(mn))
			{
				max -= 1;
				break;
			}
			else
			{
				T m = static_cast<T>(max);
				if (!validator(m))
				{
					tempMax = static_cast<T>(max);
					max = 1 + ((max + cast(tempMin)) / 2);
				}
				else
				{
					tempMin = static_cast<T>(max);
					max = 1 + ((cast(tempMax) + cast(tempMin)) / 2);
				}
			}

		}

		tempMax = static_cast<T>(max);
		tempMin = static_cast<T>(0);
		while (!validator(typemin))
		{
			T m = static_cast<T>(min);
			T mn = static_cast<T>(min + 1);
			if (!validator(m) && validator(mn))
			{
				min += 1;
				break;
			}
			else
			{
				T m = static_cast<T>(min);

				if (!validator(m))
				{
					tempMin = static_cast<T>(min);
					min = -1 + ((min + cast(tempMax)) / 2);
				}
				else
				{
					tempMax = static_cast<T>(min);
					min = -1 + ((cast(tempMax) + cast(tempMin)) / 2);
				}
			}

		}
	
	}

}