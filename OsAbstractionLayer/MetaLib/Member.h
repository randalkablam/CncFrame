/* -----------------------------------------------------------------------------------------------
Member<Class, T> is a representation of a registered member
Class - a class this member belongs to
T - type of that member
Member contains pointer to data member which can be used to get / set stuff
Different getters and setters can be added via fluent interface (see addGetter/addConstGetter/addSetter)
Getters and setters are always preffered to using raw data member pointers (because why would you
set them in the other place?)
-------------------------------------------------------------------------------------------------*/

#pragma once


namespace meta
{

	template <typename Class, typename T>
	using member_ptr_t = T Class::*;

	// reference getter/setter func pointer type
	template <typename Class, typename T>
	using ref_getter_func_ptr_t = const T& (Class::*)() const;

	template <typename Class, typename T>
	using ref_setter_func_ptr_t = void (Class::*)(const T&);

	// value getter/setter func pointer type
	template <typename Class, typename T>
	using val_getter_func_ptr_t = T(Class::*)() const;

	template <typename Class, typename T>
	using val_setter_func_ptr_t = void (Class::*)(T);

	// non const reference getter
	template <typename Class, typename T>
	using nonconst_ref_getter_func_ptr_t = T & (Class::*)();

	// MemberType is Member<T, Class>
	template <typename MemberType>
	using get_member_type = typename std::decay_t<MemberType>::member_type;


	// const reference validator
	template <typename Class, typename T>
	using const_ref_validator_func_ptr_t = bool (Class::*)(const T&);

	// non const validator
	template <typename Class, typename T>
	using val_validator_func_ptr_t = bool (Class::*)(T);


	template <typename Class, typename T>
	class Member {
	public:
		using class_type = Class;
		using member_type = T;
 
		Member(const char* name, member_ptr_t<Class, T> ptr);
		Member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr);
		Member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr);

		Member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr, const_ref_validator_func_ptr_t<Class, T> validator);
		Member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr, val_validator_func_ptr_t<Class, T> validator);


		Member& addNonConstGetter(nonconst_ref_getter_func_ptr_t<Class, T> nonConstRefGetterPtr);

		// get sets methods can be used to add support
		// for getters/setters for members instead of
		// direct access to them
		const T& get(const Class& obj) const;
		T getCopy(const Class& obj) const;
		T& getRef(Class& obj) const;
		member_ptr_t<Class, T> getPtr() const;

		template <typename V,
			typename = std::enable_if_t<std::is_constructible<T, V>::value>>
			void set(Class & obj, V && value) const; // accepts lvalues and rvalues!

		const char* getName() const { return name; }
		bool hasPtr() const { return hasMemberPtr; }
		bool hasGetter() const { return refGetterPtr || valGetterPtr; }
		bool hasSetter() const { return refSetterPtr || valSetterPtr; }
		bool canGetConstRef() const { return hasMemberPtr || refGetterPtr; }
		bool canGetRef() const { return hasMemberPtr || nonConstRefGetterPtr; }

		bool isValid(Class& obj, T val) const;

	private:
		const char* name;
		member_ptr_t<Class, T> ptr;
		bool hasMemberPtr; // first member of class can be nullptr
						   // so we need this var to know if member ptr is present

		ref_getter_func_ptr_t<Class, T> refGetterPtr;
		ref_setter_func_ptr_t<Class, T> refSetterPtr;

		val_getter_func_ptr_t<Class, T> valGetterPtr;
		val_setter_func_ptr_t<Class, T> valSetterPtr;

		nonconst_ref_getter_func_ptr_t<Class, T> nonConstRefGetterPtr;


		const_ref_validator_func_ptr_t<Class, T> constRefValidatorPtr;
		val_validator_func_ptr_t<Class, T> valValidatorPtr;
	};

	// useful function similar to make_pair which is used so you don't have to write this:
	// Member<SomeClass, int>("someName", &SomeClass::someInt); and can just to this:
	// member("someName", &SomeClass::someInt);

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, T Class::* ptr);

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr);

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr);

} // end of namespace meta

#include <stdexcept>

namespace meta
{

	template <typename Class, typename T>
	Member<Class, T>::Member(const char* name, member_ptr_t<Class, T> ptr) :
		name(name),
		ptr(ptr),
		hasMemberPtr(true),
		refGetterPtr(nullptr),
		refSetterPtr(nullptr),
		valGetterPtr(nullptr),
		valSetterPtr(nullptr),
		nonConstRefGetterPtr(nullptr),
		constRefValidatorPtr(nullptr),
		valValidatorPtr(nullptr)
	{ }

	template <typename Class, typename T>
	Member<Class, T>::Member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr) :
		name(name),
		ptr(nullptr),
		hasMemberPtr(false),
		refGetterPtr(getterPtr),
		refSetterPtr(setterPtr),
		valGetterPtr(nullptr),
		valSetterPtr(nullptr),
		nonConstRefGetterPtr(nullptr),
		constRefValidatorPtr(nullptr),
		valValidatorPtr(nullptr) 
	{ }

	template <typename Class, typename T>
	Member<Class, T>::Member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr) :
		name(name),
		ptr(nullptr),
		hasMemberPtr(false),
		refGetterPtr(nullptr),
		refSetterPtr(nullptr),
		valGetterPtr(getterPtr),
		valSetterPtr(setterPtr),
		nonConstRefGetterPtr(nullptr),
		constRefValidatorPtr(nullptr),
		valValidatorPtr(nullptr) 
	{ }



	template <typename Class, typename T>
	Member<Class, T>::Member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr, const_ref_validator_func_ptr_t<Class, T> validator) :
		name(name),
		ptr(nullptr),
		hasMemberPtr(false),
		refGetterPtr(getterPtr),
		refSetterPtr(setterPtr),
		valGetterPtr(nullptr),
		valSetterPtr(nullptr),
		nonConstRefGetterPtr(nullptr),
		constRefValidatorPtr(validator),
		valValidatorPtr(nullptr) 
	{ }

	template <typename Class, typename T>
	Member<Class, T>::Member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr, val_validator_func_ptr_t<Class, T> validator) :
		name(name),
		ptr(nullptr),
		hasMemberPtr(false),
		refGetterPtr(nullptr),
		refSetterPtr(nullptr),
		valGetterPtr(getterPtr),
		valSetterPtr(setterPtr),
		nonConstRefGetterPtr(nullptr),
		constRefValidatorPtr(nullptr),
		valValidatorPtr(validator) 
	{ }


	template <typename Class, typename T>
	Member<Class, T>& Member<Class, T>::addNonConstGetter(nonconst_ref_getter_func_ptr_t<Class, T> nonConstRefGetterPtr)
	{
		this->nonConstRefGetterPtr = nonConstRefGetterPtr;
		return *this;
	}

	template <typename Class, typename T>
	const T& Member<Class, T>::get(const Class& obj) const
	{
		if (refGetterPtr) {
			return (obj.*refGetterPtr)();
		}
		else if (hasMemberPtr) {
			return obj.*ptr;
		}
		throw std::runtime_error("Cannot return const ref to member: no getter or member pointer set");
	}

	template <typename Class, typename T>
	T Member<Class, T>::getCopy(const Class& obj) const
	{
		if (refGetterPtr) {
			return (obj.*refGetterPtr)();
		}
		else if (valGetterPtr) {
			return (obj.*valGetterPtr)();
		}
		else if (hasMemberPtr) {
			return obj.*ptr;
		}
		throw std::runtime_error("Cannot return copy of member: no getter or member pointer set");
	}

	template <typename Class, typename T>
	T& Member<Class, T>::getRef(Class& obj) const
	{
		if (nonConstRefGetterPtr) {
			return (obj.*nonConstRefGetterPtr)();
		}
		else if (hasMemberPtr) {
			return obj.*ptr;
		}
		throw std::runtime_error("Cannot return ref to member: no getter or member pointer set");
	}

	template <typename Class, typename T>
	member_ptr_t<Class, T> Member<Class, T>::getPtr() const {
		if (hasPtr()) {
			return ptr;
		}
		throw std::runtime_error("Cannot get pointer to member: it wasn't set");
	}

	template<typename Class, typename T>
	template <typename V, typename>
	void Member<Class, T>::set(Class& obj, V&& value) const
	{
		// TODO: add rvalueSetter?
		if (refSetterPtr) {
			(obj.*refSetterPtr)(value);
		}
		else if (valSetterPtr) {
			(obj.*valSetterPtr)(value); // will copy value
		}
		else if (hasMemberPtr) {
			obj.*ptr = value;
		}
		else {
			throw std::runtime_error("Cannot access member: no setter or member pointer set");
		}
	}

	template<typename Class, typename T>
	bool Member<Class, T>::isValid(Class& obj, T val) const
	{
		bool ret = false;
		if (constRefValidatorPtr)
		{
			ret = (obj.*constRefValidatorPtr)(val);
		}
		else if (valValidatorPtr)
		{
			ret = (obj.*valValidatorPtr)(val);
		}
		else
		{
			// If we have no validator then any value is valid...
			ret = true;
		}
		return ret;
	}

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, T Class::* ptr)
	{
		return Member<Class, T>(name, ptr);
	}

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr)
	{
		return Member<Class, T>(name, getterPtr, setterPtr);
	}

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr)
	{
		return Member<Class, T>(name, getterPtr, setterPtr);
	}

	// Val Validator
	template <typename Class, typename T>
	Member<Class, T> member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr, val_validator_func_ptr_t<Class, T> validatorPtr)
	{
		return Member<Class, T>(name, getterPtr, setterPtr, validatorPtr);
	}

	// Ref Validator
	template <typename Class, typename T>
	Member<Class, T> member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr, const_ref_validator_func_ptr_t<Class, T> validatorPtr)
	{
		return Member<Class, T>(name, getterPtr, setterPtr, validatorPtr);
	}

	// read only
	template <typename Class, typename T>
	Member<Class, T> member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr)
	{
		return Member<Class, T>(name, getterPtr, nullptr);
	}

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr)
	{
		return Member<Class, T>(name, getterPtr, nullptr);
	}

	// set only 
	template <typename Class, typename T>
	Member<Class, T> member(const char* name, ref_setter_func_ptr_t<Class, T> setterPtr)
	{
		return Member<Class, T>(name, nullptr, setterPtr);
	}

	template <typename Class, typename T>
	Member<Class, T> member(const char* name, val_setter_func_ptr_t<Class, T> setterPtr)
	{
		return Member<Class, T>(name, nullptr, setterPtr);
	}




} // end of namespace meta