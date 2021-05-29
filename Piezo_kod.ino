//lcd ekran aydınlatması arduino bağlı olucak (dijital) arka aydınlatma 

#include <LiquidCrystal.h>
#include "LowPower.h"
int hour=0;
int minute =0;
int sec=0;
int min_sayac=0;
int sec_sayac=0;
int kalori=0;
int kal_hour;
int kal_min;
int kal_sec;
int ekransayac=0;
//LCD ekranı açıp kapatan değişken
int lcd_control = 7;
LiquidCrystal lcd(12,11,6,5,4,3);

unsigned long time_count = 0;
unsigned int counter = 0;

void setup() {
  lcd.begin(16,3);
  pinMode(lcd_control, OUTPUT);

  
}

void loop() { 
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); //390uA
  //LowPower.idle(SLEEP_4S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF);
if (ekransayac=10){
    digitalWrite(lcd_control, HIGH);
    delay(5000);
    ekransayac=0;
}
  lcd.clear();
  
  lcd.home();
  lcd.print("Time=");
  
  lcd.setCursor(7,0);
  lcd.print(":");

  lcd.setCursor(10,0);
  lcd.print(":");
  
  lcd.setCursor(0,1);
  lcd.print("Kcal=");

  counter++;
  time_count = counter * 8;
  sec=time_count;
  while(sec>59){
    if (sec>=60){
      minute++;
      ekransayac++;
      sec=sec-60;
      
    }
    if(minute>=60){
      hour++;
      minute=minute-60;
    }
  }

  // kalori
  kal_hour = 347 * hour;
  kal_min = 6 * minute;
  kal_sec = (sec/10);
  kalori = kal_hour + kal_min + kal_sec;

  lcd.setCursor(5,0);
  lcd.print(hour);

  lcd.setCursor(8,0);
  lcd.print(minute);

  lcd.setCursor(11,0);
  lcd.print(sec);

  lcd.setCursor(5,1);
  lcd.print(kalori);

  sec = 0;
  minute = 0;
  hour = 0; 
  if(ekransayac==0){
    digitalWrite(lcd_control, LOW);
  }
}
