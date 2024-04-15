#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <Servo.h>

#define ROW_NUM     4
#define COLUMN_NUM  4
#define DS1307_ADDRESS 0x68  // Địa chỉ I2C của DS1307
#define LCD_ADDRESS 0x27     // Địa chỉ I2C của màn hình LCD
#define servo_door_pin 21 //Sua
#define servo_feed_pin 21 //Sua

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

bool feed_state[2]          = {false, false, false};
int  time_feed[2]           = {3, 9, 15};
byte pin_rows[ROW_NUM]      = {25}; //Sua
byte pin_column[COLUMN_NUM] = {19, 18}; //Sua

RTC_DS1307 rtc;
Servo servo_feed, servo_door;

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);  // Khởi tạo màn hình LCD
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );