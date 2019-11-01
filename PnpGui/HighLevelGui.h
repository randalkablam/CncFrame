#pragma once
#include <Manager.h>
#include "PnpMaster/Configuration/ConfigurationMessage.h"
class PnpGui;

class HighLevelGui :
	public Manager
{
public:

	friend class PnpGui;
	friend class AxisDialog;
	friend class ConfigSelectDialog;
	friend class PumpDialog;
	friend class ValveDialog;

	// Manager Methods
	static HighLevelGui* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	HighLevelGui();
	~HighLevelGui();

	static HighLevelGui* ms_highLevelGuiPtr;

	PnpGui* m_pnpGui;
	enum class IOType
	{
		I2C,
		GPIO
	};

	enum class SignalType
	{
		STEPPER_PUL,
		STEPPER_DIR,
		STEPPER_EN,
		DC_M_PUL,
		DC_M_DIR,
		DC_M_EN,
		GENERIC_IN,
		GENERIC_OUT


	};

	class IOParameters
	{
	public:
		IOParameters(IOType type,
			SignalType signal,
			const std::string& param1,
			uint8_t param2,
			uint8_t param3,
			uint8_t param4) :
			m_type(type),
			m_param1(param1),
			m_param2(param2),
			m_param3(param3),
			m_param4(param4),
			m_signal(signal)
		{}
		IOType m_type;
		std::string m_param1;
		uint8_t m_param2;
		uint8_t m_param3;
		uint8_t m_param4;
		SignalType m_signal;

		bool isValid() const
		{
			bool ret = false;

			if (IOType::I2C == m_type && "" != m_param1 && 0 != m_param2
				&& 0 != m_param3 && 0 != m_param4)
			{
				ret = true;
			}
			else if (IOType::GPIO == m_type && "" != m_param1 && 0 != m_param2)
			{
				ret = true;
			}
			return ret;
		}
		IOParameters& operator=(const IOParameters& rhs)
		{
			m_type = rhs.m_type;
			m_signal = rhs.m_signal;
			m_param1 = rhs.m_param1;
			m_param2 = rhs.m_param2;
			m_param3 = rhs.m_param3;
			m_param4 = rhs.m_param4;
			return *this;
		}
	};

	class AxisParams
	{
	public:
		AxisParams(): m_limitSwitch(IOType::I2C, SignalType::GENERIC_IN, "", 0, 0, 0){}
		std::vector<IOParameters> m_ioParams;
		uint8_t m_ioCnt;
		uint8_t m_stepperCnt;
		std::string m_axisName;
		double m_axisLen;
		IOParameters m_limitSwitch;
		bool isValid() const
		{
			bool ret = false;
			if (m_ioCnt == (m_stepperCnt * 3) && m_limitSwitch.isValid()
				&& m_axisLen > 0 && m_axisName != "")
			{
				ret = true;
			}
			return ret;
		}
	};

	

	bool populateAxisConfig(AxisParams& params);
	bool populateValveConfig(const std::vector<IOParameters>& params);
	bool populatePumpConfig(const std::vector<IOParameters>& params);

	ConfigurationMessage m_configMsg;
	
	void sendCmd(const std::string& cmd);
	void updateCmdDest(const std::string& cmdDest);
	std::string m_cmdDestMgr;
};

