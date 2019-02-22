#include "DHT.h"
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int fan = 9;
int Bulb = 7;
int LDR = A4;

#define DHTPIN 8
#define DHTTYPE DHT11
float h, t;

DHT dht(DHTPIN, DHTTYPE);
int SensorValue=0;

void setup()
{
    Serial.begin(9600);
    lcd.begin(20, 4);
    pinMode(fan, OUTPUT);
    pinMode(Bulb, OUTPUT);
    pinMode(LDR, INPUT);
}

void loop()
{
        HumidityTemp();
        Intensity();
        lcd.clear();  
        lcd.setCursor(0, 0);
        lcd.print("Humidity:");        
        lcd.print(h); 
        lcd.setCursor(11, 0); 
        lcd.print("%  ");    
        lcd.setCursor(0, 1);
        lcd.print("Temperature:");        
        lcd.print(t); 
        lcd.setCursor(14, 1); 
        lcd.print((char)223); 
        lcd.print("C  ");
        lcd.setCursor(0, 2);
        lcd.print("Intensity:");        
        lcd.print(SensorValue); 
         
}
void HumidityTemp()
{    
        h = dht.readHumidity();
        t = dht.readTemperature();                
                  
        Serial.print("Humidity: ");
        Serial.println(h);
        Serial.print(" % ");
        Serial.print("Temperature: ");
        Serial.println(t);
        Serial.print("°C ");
        delay(1000); 
        if(t>=28)
         digitalWrite(fan, HIGH);
        else
        digitalWrite(fan, LOW);
}
void Intensity()
{
           SensorValue = analogRead(LDR);
           Serial.print("Intensity: ");
           Serial.println(SensorValue);
           if ( SensorValue <=150)                
              digitalWrite(Bulb, HIGH);        
           else          
              digitalWrite(Bulb, LOW);
                    
}

