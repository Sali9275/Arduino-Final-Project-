#include <Arduino.h>

#include <Wire.h>
#include <LiquideCrystal_I2C.h>

#define echoPin 12 // attach pin D2  Arduuin to pin Echo of HY-SRF05 //(  
#define TringPin 11 // attch pin D3  Arduin to pin Tring of HY-SRF05 //( 

#define soilWet 500 // Define Max Value we consider soil 'wet' //(הגדרה של רטיבות האדמה כמקסימום רטיבות) 
#define soilDry 750 // Define Min Value we consider soil 'dry' //(הגדרה: של יובש האדמה- עד כמה האדמה יבשה בטווח שבין 750>500)

// define variables //(הגדרת מספרים שלמים}{משתנים} שאיתם אנחנו נעבוד)
float duratino; // variables for the duration of sound wave travel //(הגדרת זמן הגל קול שפוגע במשטח וחוזר) (Distance Sensor)// float-(כדי לקבל את  תוצאה של מספרים שלמים עם נקודה עשרונית)
float distance; // variables for the distance measurement //( משתנה להגדרת מדידת המרחק)  
int MOIST; ///    (  לחות  משתנה) 

String str;
 int oldmos = -1;
  LiquidCrystal_I2C lcd(0*27, 16, 2); // if your LCD I2C address is not 0x27, you shold replace 0X27 with correct I2C address(i.e 0X3f) 

 void loo()
 { 
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT 
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT 
     Serial.begin(9600);
      pinMode(12, INPUT);
       pinMode(11, OUTPUT);
        lcd.init():
         lcd.backlight():
 }
   void loop()
  {
    int soil_mos:
    soil_mos = 1023- analogRead(AO); // get soil mositure value from A0 pin (קבלת אות אנלוגי שמציג את הערך של הלחות)
     soil_mos= map(soil_mos, 0, 1023, 0, 100); // convert mositure value in percentage format  (מציג את הלחות באחוזים)
      Serial.print("Analog Output: ");(הדפסה של האות האנלוגי המתקבל)
       Serial.println(MOSIT);(תדפיס לחות)
        delay(1000); // Take a reading every secoud for testing a day // Normally you should perhaps once or twice a day (לקיחת הקריאה כול שניה לבדיקה ביום)
         Serial.println();

      if (oldms != soil_mos) { // Dispaly the moistere on the LCD screen ( הרצה על המסך lcd)
        lcd.setCursor(0 , 0);
         lcd.print("Soil Moist:");
          lcd.print(soil_mos);
           lcd.print("%");
      //Clear the trigPin condition 
            digitalWrite(trigPin, LOW); //Set the trigPin LOW (ACTIVE) for 2 microseconds 
             delayMicroseconds(2);
              digitalWrite(trigPin, HIGH); // Sets the trigPin HIGH (ACTIVE) for 10 microseconds 
               delayMicroseconds(10);
                digitalWrite(trigPin, LOW);      

         duration = pulseIn( echoPin, HIGH); // Reads the echoPin. returns the sonds wave travel time in microseconds 

     float distance = duration/29/2;
      if(duration==0){
        Serial.println("Warning; no pulse from sensor");           
      }
      else{
        Serial.print("distance to nearest object");
         Serial.println(distance);
          Serial.println("cm");
      }
           delay(100);

            //Dispaly the distance on the Serial Monit (הדפסה של המרחק על הצג המונטרי)
             lcd.setCursor(0 , 1);
              lcd.print("Distance");(הדפסה של המרחק)
               lcd.print(distance/1000); 
                lcd.print("cm");
      }
  }