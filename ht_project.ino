#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  lcd.init();
  lcd.backlight();
  dht.begin();

  lcd.setCursor(0,0);
  lcd.print("Temp & Humidity");
  delay(2000);
  lcd.clear();
  }

  void loop(){
    float h = dht.readHumidity();
    float t= dht.readTemperature();
    if(isnan(h)||isnan(t)){
      lcd.setCursor(0,0);
      lcd.print("Sensor Error");
      return;
    }
    //display temp
    lcd.setCursor(0,0);
    lcd.print("Temp:");
    lcd.print(t);
    lcd.print((char)223);
    lcd.print("C");
    //display hdty
    lcd.setCursor(0,1);
    lcd.print("Humidity:");
    lcd.print(h);
    lcd.print("%");

    delay(2000);
  }