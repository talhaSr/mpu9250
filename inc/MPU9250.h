/*
 * MPU9250.c
 *
 *  	@Created on: Jan 18, 2021
 *      @Author: Talha Sari
 *      @License: GNU General Public License v3
 *      @Brief: This library is created for STM32 development environment and can be used only with STM32F series microcontrollers.
 *      @Note: Requires HAL Libraries!
 */

#ifndef INC_MPU9250_H_
#define INC_MPU9250_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Ekstra */
#define READWRITE_CMD			0x80
#define MULTIBYTE_CMD			0x40
#define DUMMY_BYTE				0x00

/* Gyro ve Acc (MPU9250) Register Map */
#define SELF_TEST_X_GYRO		0x00
#define SELF_TEST_Y_GYRO		0x01
#define SELF_TEST_Z_GYRO		0x02
#define SELF_TEST_X_ACCEL		0x0D
#define SELF_TEST_Y_ACCEL		0x0E
#define SELF_TEST_Z_ACCEL		0x0F

#define XG_OFFSET_H				0x13	/* Gyro Offset Registers */
#define XG_OFFSET_L				0x14
#define YG_OFFSET_H				0x15
#define YG_OFFSET_L				0x16
#define ZG_OFFSET_H				0x17
#define ZG_OFFSET_L				0x18

#define SMPLRT_DIV				0x19	/* Sample Rate Divider - <SAMPLE_RATE = Internal_Sample_Rate / (1 + SMPLRT_DIV)> */
#define CONFIG					0x1A
#define GYRO_CONFIG				0x1B
#define ACCEL_CONFIG			0x1C
#define ACCEL_CONFIG_2			0x1D
#define LP_ACCEL_ODR			0x1E	/* Low Power Accelerometer ODR Control */
#define WOM_THR					0x1F	/* Wake-on Motion Threshold */
#define FIFO_EN					0x23	/* FIFO Enable */

#define I2C_MST_CTRL			0x24
#define I2C_SLV0_ADDR			0x25
#define I2C_SLV0_REG			0x26
#define I2C_SLV0_CTRL			0x27
#define I2C_SLV1_ADDR			0x28
#define I2C_SLV1_REG			0x29
#define I2C_SLV1_CTRL			0x2A
#define I2C_SLV2_ADDR			0x2B
#define I2C_SLV2_REG			0x2C
#define I2C_SLV2_CTRL			0x2D
#define I2C_SLV3_ADDR			0x2E
#define I2C_SLV3_REG			0x2F
#define I2C_SLV3_CTRL			0x30
#define I2C_SLV4_ADDR			0x31
#define I2C_SLV4_REG			0x32
#define I2C_SLV4_DO				0x33
#define I2C_SLV4_CTRL			0x34
#define I2C_SLV4_DI				0x35
#define I2C_MST_STATUS			0x36

#define INT_PIN_CFG				0x37	/* INT Pin/Bypass Enable Configuration */
#define INT_ENABLE				0x38	/* Interrupt Enable */
#define INT_STATUS				0x39	/* Interrupt Status */

#define ACCEL_XOUT_H			0x3B	/* Acc X-axis H */
#define ACCEL_XOUT_L			0x3C	/* Acc X-axis L */
#define ACCEL_YOUT_H			0x3D	/* Acc Y-axis H */
#define ACCEL_YOUT_L			0x3E	/* Acc Y-axis L */
#define ACCEL_ZOUT_H			0x3F	/* Acc Z-axis H */
#define ACCEL_ZOUT_L			0x40	/* Acc Z-axis L */

#define TEMP_OUT_H				0x41	/* Temperature Measurement H */
#define TEMP_OUT_L				0x42	/* Temperature Measurement H */

#define GYRO_XOUT_H				0x43	/* Gyro X-axis H */
#define GYRO_XOUT_L				0x44	/* Gyro X-axis L */
#define GYRO_YOUT_H				0x45	/* Gyro Y-axis H */
#define GYRO_YOUT_L				0x46	/* Gyro Y-axis L */
#define GYRO_ZOUT_H				0x47	/* Gyro Z-axis H */
#define GYRO_ZOUT_L				0x48	/* Gyro Z-axis L */

#define EXT_SENS_DATA_00		0x49	/* External Sensor Data */
#define EXT_SENS_DATA_01		0x4A
#define EXT_SENS_DATA_02		0x4B
#define EXT_SENS_DATA_03		0x4C
#define EXT_SENS_DATA_04		0x4D
#define EXT_SENS_DATA_05		0x4E
#define EXT_SENS_DATA_06		0x4F
#define EXT_SENS_DATA_07		0x50
#define EXT_SENS_DATA_08		0x51
#define EXT_SENS_DATA_09		0x52
#define EXT_SENS_DATA_10		0x53
#define EXT_SENS_DATA_11		0x54
#define EXT_SENS_DATA_12		0x55
#define EXT_SENS_DATA_13		0x56
#define EXT_SENS_DATA_14		0x57
#define EXT_SENS_DATA_15		0x58
#define EXT_SENS_DATA_16		0x59
#define EXT_SENS_DATA_17		0x5A
#define EXT_SENS_DATA_18		0x5B
#define EXT_SENS_DATA_19		0x5C
#define EXT_SENS_DATA_20		0x5D
#define EXT_SENS_DATA_21		0x5E
#define EXT_SENS_DATA_22		0x5F
#define EXT_SENS_DATA_23		0x60

#define I2C_SLV0_DO				0x63
#define I2C_SLV1_DO				0x64
#define I2C_SLV2_DO				0x65
#define I2C_SLV3_DO				0x66
#define I2C_MST_DELAY_CTRL		0x67

#define SIGNAL_PATH_RESET		0x68	/* Signal Path Reset */
#define MOT_DETECT_CTRL			0x69	/* Accelerometer Interrupt Control */
#define USER_CTRL				0x6A	/* User Control */
#define PWR_MGMT_1				0x6B	/* Power Management 1 */
#define PWR_MGMT_2				0X6C	/* Power Management 2 */

#define FIFO_COUNTH				0x72	/* FIFO Count H */
#define FIFO_COUNTL				0x73	/* FIFO Count L */
#define FIFO_R_W				0x74	/* FIFO Read Write */
#define WHO_AM_I				0x75	/* Device ID - (0x71) */

#define XA_OFFSET_H				0x77	/* Accelerometer Offset Registers */
#define XA_OFFSET_L				0x78
#define YA_OFFSET_H				0x7A
#define YA_OFFSET_L				0x7B
#define ZA_OFFSET_H				0x7D
#define ZA_OFFSET_L				0x7E

/* Mag (AK8963) Register Map */
#define WIA						0x00	/* Device ID - (0x48) */
#define INFO					0x01	/* Information */
#define ST1						0x02	/* Data Status 1 */

#define HXL						0x03	/* X-axis L */
#define HXH						0x04	/* X-axis H */
#define HYL						0x05	/* Y-axis L */
#define HYH						0x06	/* Y-axis H */
#define HZL						0x07	/* Z-axis L */
#define HZH						0x08	/* Z-axis H */

#define ST2						0x09	/* Data Status 2 */
#define CNTL					0x0A	/* Control */
#define ASTC					0x0C	/* Self-test (Slave Address) */
#define I2CDIS					0x0F	/* I2C Disable */

#define ASAX					0x10	/* X-axis hassasiyet değeri */
#define ASAY					0x11	/* Y-axis hassasiyet değeri */
#define ASAZ					0x12	/* Z-axis hassasiyet değeri */

/* I2C Addresses */
#define MPU9250_I2C_ADDR		0xD0
#define MPU9250_I2C_ADDR_MAG	(0x0C << 1)

/* Structure */
typedef enum {
	MPU9250_RESULT_OK = 0x00,
	MPU9250_RESULT_ERROR,
	MPU9250_RESULT_NC
} MPU9250_Result_t;

typedef enum {
	ACCEL_SCALE_2G = 0x00,
	ACCEL_SCALE_4G = 0x08,
	ACCEL_SCALE_8G = 0x10,
	ACCEL_SCALE_16G = 0x18
} MPU9250_Accel_Scale_t;

typedef enum {
	GYRO_SCALE_250dps = 0x00,
	GYRO_SCALE_500dps = 0x08,
	GYRO_SCALE_1000dps = 0x10,
	GYRO_SCALE_2000dps = 0x18
} MPU9250_Gyro_Scale_t;

typedef enum {
	MAG_SCALE_14bit = 0x00,
	MAG_SCALE_16bit
} MPU9250_Mag_Scale_t;

typedef enum {
	MPU9250_Device_0 = 0x00,
	MPU9250_Device_1 = 0x02
} MPU9250_Device_t;

typedef struct {
	float acc[3];
	float gyro[3];
	float mag[3];
	float temp;
	int16_t acc_raw[3];
	int16_t gyro_raw[3];
	int16_t mag_raw[3];
	int16_t temp_raw;

	float accMult, gyroMult, magMult, tempMult;

	uint8_t I2C_Addr;
	uint8_t I2C_Addr_Mag;
} MPU9250_t;

/* Sensor Functions */
MPU9250_Result_t MPU9250_Init(MPU9250_t *MPU9250, MPU9250_Device_t dev, MPU9250_Accel_Scale_t accScale, MPU9250_Gyro_Scale_t gyroScale, MPU9250_Mag_Scale_t magScale);
MPU9250_Result_t MPU9250_ReadAcc(MPU9250_t *MPU9250);
MPU9250_Result_t MPU9250_ReadGyro(MPU9250_t *MPU9250);
MPU9250_Result_t MPU9250_ReadMag(MPU9250_t *MPU9250);
MPU9250_Result_t MPU9250_ReadTemperature(MPU9250_t *MPU9250);
MPU9250_Result_t MPU9250_DataReady(MPU9250_t *MPU9250);
MPU9250_Result_t isMPU9250Ready(I2C_HandleTypeDef *hi2c, uint8_t device_addr);

/* I2C R/W Functions */
HAL_StatusTypeDef writeByte(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t data);
HAL_StatusTypeDef readByte(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data);
HAL_StatusTypeDef writeMultiBytes(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data, uint16_t count);
HAL_StatusTypeDef readMultiBytes(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data, uint16_t count);



#ifdef __cplusplus
}
#endif

#endif /* INC_MPU9250_H_ */
