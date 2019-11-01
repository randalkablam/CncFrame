#include "I2cDriver.h"
#include <fstream>

#ifdef OS_LINUX
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int32_t I2cDriver::writeByte(uint8_t dev, uint8_t reg, uint8_t val)
{
	int32_t ret = 0;

	do
	{
		int32_t fd = -1;
		ret = openDevice(fd);
		if (ret < 0)
		{
			break;
		}
		ret = configDevice(fd, dev);
		if (ret < 0)
		{
			break;
		}

		uint8_t outbuf[2];

		struct i2c_rdwr_ioctl_data packets;
		struct i2c_msg messages[1];

		messages[0].addr = dev;
		messages[0].flags = 0;
		messages[0].len = sizeof(outbuf);
		messages[0].buf = outbuf;

		/* The first byte indicates which register we'll write */
		outbuf[0] = reg;

		/*
		 * The second byte indicates the value to write.  Note that for many
		 * devices, we can write multiple, sequential registers at once by
		 * simply making outbuf bigger.
		 */
		outbuf[1] = value;

		/* Transfer the i2c packets to the kernel and verify it worked */
		packets.msgs = messages;
		packets.nmsgs = 1;
		ret = ioctl(fd, I2C_RDWR, &packets);
		if (ret < 0)
		{
			// TODO

			break;
		}
		ret = 0;
	} while (false);
	return ret;
}

int32_t I2cDriver::writeMultiByte(uint8_t dev, uint8_t reg, std::vector<uint8_t>& bytes)
{
	int32_t ret = 0;

	int32_t fd = -1;
	do
	{
		ret = openDevice(fd);
		if (ret < 0)
		{
			break;
		}
		ret = configDevice(fd, dev);
		if (ret < 0)
		{
			break;
		}


		if (bytes.size() > 0)
		{
			uint8_t outbuf[bytes.size()];
			struct i2c_rdwr_ioctl_data packets;
			struct i2c_msg messages[1];

			messages[0].addr = dev;
			messages[0].flags = 0;
			messages[0].len = sizeof(outbuf);
			messages[0].buf = outbuf;

			/* The first byte indicates which register we'll write */
			outbuf[0] = reg;
			/*
			 * The second byte indicates the value to write.  Note that for many
			 * devices, we can write multiple, sequential registers at once by
			 * simply making outbuf bigger.
			 */

			for (uint16_t i = 0; i < bytes.size(); i++)
			{
				outbuf[i + 1] = bytes.at(bytes.begin() + i);
			}




			/* Transfer the i2c packets to the kernel and verify it worked */
			packets.msgs = messages;
			packets.nmsgs = 1;
			ret = ioctl(fd, I2C_RDWR, &packets);
			if (ret < 0)
			{
				break;
			}
			ret = 0;
		}
	} while (false);
	return ret;
}

int32_t I2cDriver::readByte(uint8_t dev, uint8_t reg, uint8_t& val)
{
	int32_t ret = 0;

	do
	{

		int32_t fd = -1;

		ret = openDevice(fd);
		if (ret < 0)
		{
			break;
		}

		ret = configDevice(fd, dev);
		if (ret < 0)
		{
			break;
		}

		uint8_t inbuf;
		uint8_t outbuf;
		struct i2c_rdwr_ioctl_data packets;
		struct i2c_msg messages[2];

		/*
		 * In order to read a register, we first do a "dummy write" by writing
		 * 0 bytes to the register we want to read from.  This is similar to
		 * the packet in set_i2c_register, except it's 1 byte rather than 2.
		 */
		outbuf = reg;
		messages[0].addr = dev;
		messages[0].flags = 0;
		messages[0].len = sizeof(outbuf);
		messages[0].buf = &outbuf;

		/* The data will get returned in this structure */
		messages[1].addr = dev;
		messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
		messages[1].len = sizeof(inbuf);
		messages[1].buf = &inbuf;

		/* Send the request to the kernel and get the result back */
		packets.msgs = messages;
		packets.nmsgs = 2;
		ret = ioctl(fd, I2C_RDWR, &packets);
		if (ret < 0)
		{
			// TODO

			break;
		}
		ret = 0;
		val = inbuf;
	} while (false);
	return ret;
}



int32_t I2cDriver::openDevice(uint8_t& fd)
{
	int32_t ret = 0;
	ret = open(m_device, O_RDWR);
	if (ret < 0)
	{
		fd = -1;
		// TODO error handling
	}


	return ret;
}

int32_t I2cDriver::configDevice(uint8_t fd, uint8_t dev)
{
	int32_t ret = 0;
	ret = ioctl(fd, I2C_SLAVE, addr);
	if (ret < 0)
	{
		// TODO error handling
	}

	return ret;
}

int32_t I2cDriver::closeDevice(uint8_t fd)
{
	int32_t ret = 0;

	ret = close(fd);
	if (ret < 0)
	{
		// TODO error handling
	}

	return ret;
}
#else
int32_t I2cDriver::writeByte(uint8_t dev, uint8_t reg, uint8_t val)
{
	return int32_t();
}

int32_t I2cDriver::writeMultiByte(uint8_t dev, uint8_t reg, std::vector<uint8_t>& bytes)
{
	return int32_t();
}

int32_t I2cDriver::readByte(uint8_t dev, uint8_t reg, uint8_t& val)
{
	return int32_t();
}

int32_t I2cDriver::openDevice(uint8_t& fd)
{
	return int32_t();
}

int32_t I2cDriver::configDevice(uint8_t fd, uint8_t dev)
{
	return int32_t();
}

int32_t I2cDriver::closeDevice(uint8_t fd)
{
	return int32_t();
}
#endif

void I2cDriver::setDevice(const std::string& device)
{
	std::ifstream f(device.c_str());
	if (f.good())
	{
		m_device = device;
	}
}

const std::string& I2cDriver::getDevice() const
{
	return m_device;
}
