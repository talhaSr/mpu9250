#include "main.h"
//#include "cmsis_os.h"
#include "mpu9250.h"

/* Sensor Handler */
MPU9250_t mpu9250;
/* I2C Handler */
I2C_HandleTypeDef hi2c1;

uint8_t isDeviceConnected = 0;


HAL_StatusTypeDef whoAmI_Check(MPU9250_t *mpu9250);

int main(void)
{
	/*
	All Init Functions
	...
	*/
	MPU9250_Init(&mpu9250, MPU9250_Device_0, ACCEL_SCALE_16G, GYRO_SCALE_2000dps, MAG_SCALE_16bit);
	
	while (1)
	{
		if (whoAmI_Check(&mpu9250) != HAL_ERROR)
			isDeviceConnected = 1;
		else
			isDeviceConnected = 0;
	}
}

HAL_StatusTypeDef whoAmI_Check(MPU9250_t *mpu9250)
{
	uint8_t data;
	/* MPU9250 Who Am I Register Check */
	if (readByte(&hi2c, mpu9250.I2C_Addr, WHO_AM_I, &data) != HAL_OK)
	{
		if (data != 0x71)
			return HAL_ERROR;
	}
	/* AK8963 Who Am I Register Check */
	if (readByte(&hi2c, mpu9250.I2C_Addr_Mag, WIA, &data) != HAL_OK)
	{
		if (data != 0x48)
			return HAL_ERROR;
	}
	return HAL_OK;
}


