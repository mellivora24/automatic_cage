#include "customs_lib.h"

char get_key() {
  char key = keypad.getKey();
  if (key) return key;
  else return 'x';
}

void setTimeFeed() {
  switch (get_key()) {
    case 'B':
      //Set feed time 1
      
      break;
    case 'C':
      //Set feed time 2

      break;
    case 'D':
      //Set feed time 3
      
      break;
    case '*':
      //Done

      break;
    case '#':
      //Cancel

      break;
    default:
      break;
  }
}
void feed() {
  DateTime now = rtc.now();
  for (int i=0; i<=2; i++)
    if (now.hour() == time_feed[i] && !feed_state[i]) {
      feed_state[i] = true;
      servo_feed.attach(servo_feed_pin);
      servo_feed.write(50); //Sua
      delay(200); //Sua
      servo_feed.write(1); //Sua
      servo_feed.detach();
    }
}

void init_devices() {
  Wire.begin();
  rtc.begin();
  lcd.begin(16, 2);
}
void setup() {
  // if (!rtc.isrunning()) Serial.println("RTC is NOT running!");
  DateTime now = DateTime(__DATE__, __TIME__);
  rtc.adjust(now);
  lcd.backlight();
}