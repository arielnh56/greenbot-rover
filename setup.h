#include <Wire.h>
#include <Hercules.h>
#include <Hercules_dfs.h>
#include <seeed_pwm.h>

//define i2c addresses
#define I2C_MASTER_ADDRESS 9
#define I2C_ROVER_ADDRESS 10
#define I2C_LCD_ADDRESS 0x27
#define I2C_SONAR_ADDRESS 0x20


// gear ratio of motors
#define GEAR_RATIO 36.0

unsigned long int last_debug = 0;




