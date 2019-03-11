//ECE 387 Class Project
//Alarm Design

//In this project I used a built in Arduino Time library to keep track of the time, 
//I used an external library available through Arduino's website called TimeAlarms.h
//You can find this library on the Arduino Resources website, the time library section directs you to it. 

//website: https://www.pjrc.com/teensy/td_libs_TimeAlarms.html


#include <Time.h>
#include <TimeAlarms.h>

void setup() {
  Serial.begin(9600);
  setTime(1,1,1,1,1,19);
  Alarm.alarmRepeat(7,0,0,Alarm); 
  Alarm.alarmOnce(1,1,20,ExplicitAlarm);

}

void loop() {
  digitalClockDisplay();
  Alarm.delay(1000);
}

void MorningAlarm(){
  Serial.println("Alarm");
}

void digitalClockDisplay(){
  Serial.print(hour());
  PrintDigits(minute());
  PrintDigits(second());
  Serial.println();
}

void ExplicitAlarm(){
  Serial.println("Test");
}

void PrintDigits(int digits){
  Serial.print(":");
  if(digits<10)
    Serial.print('0');
   Serial.print(digits); 
}
