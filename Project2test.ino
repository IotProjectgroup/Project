#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

int colorR;
int colorG;
int colorB;

/*all these inputs can be changed to suite your device*/
int pirSensorEntra = 10;
int touchsensor = A2;
int pirSensorCheck = 7;

int buzzer = 5;
void setup() {
  // put your setup code here, to run once:
pinMode(pirSensorEntra, INPUT);
pinMode(pirSensorCheck, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(touchsensor, INPUT);
 Serial.begin(9600);
   lcd.begin(16,2);
      colorR = 0; colorG = 0; colorB = 0;
      lcd.setRGB(colorR, colorG, colorB);

}

void loop() {
 
  // put your main code here, to run repeatedly:
  int num = 0;int check = 0; 

 if(digitalRead(pirSensorEntra) == HIGH)
 {
  num = 1;  
 }
 if(num == 1)
 {
  lcd.begin(16,2);
      colorR = 0; colorG = 0; colorB = 255;  //sets the display colors
        lcd.setRGB(colorR, colorG, colorB);       
         lcd.print("Please sanitize before entry.");
        
    if(digitalRead(touchsensor) == HIGH)
             {
                  check = 1; 
                    lcd.begin(16,2);
                  colorR = 255; colorG = 0; colorB = 0;
                  lcd.setRGB(colorR, colorG, colorB);
                lcd.print("Keep Safe....");
                   delay(8000);
                   
             }       

}
     if((digitalRead(pirSensorCheck)==HIGH)&&(check==0)){
      for(int i = 0; check == 0; i++){
      tone(buzzer, 500);
      delay(1000);
      noTone(buzzer);
      delay(500);
      check = digitalRead(touchsensor) == HIGH;
     
      }  
       noTone(buzzer);              
       lcd.begin(16,2);
       colorR = 255; colorG = 0; colorB = 0;
       lcd.setRGB(colorR, colorG, colorB);
       lcd.print("Keep Safe! :)");
       delay(10000); 
         
          
          
     }
}   
