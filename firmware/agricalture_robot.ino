#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C.h>
//......................................lcd
LiquidCrystal_I2C lcd(0x27,16,2);
//......................................encoder
 #define outputA 12  
 #define outputB 13
 #define outputc 11
 #define puls1 3
 #define dir1 4
 #define puls2 5
 #define dir2 6
 #define motor1 7
 #define motor2 8
 #define motor3 9
 #define motor4 10
 #define sw 2
 
 long counter1 =0; 
 long counter2 =0; 
 long x=0;
 int aState;
 int aLastState;
float a;
float b;
 float distance=0;  
 float meter = 0;
//......................................
  
void setup() {
  pinMode (outputA,INPUT_PULLUP);  //أقطاب الأنكودر         
  pinMode (outputB,INPUT_PULLUP);
  pinMode (outputc,INPUT_PULLUP);
  aLastState = digitalRead(outputA);
  pinMode(puls1,OUTPUT);
  pinMode(puls2,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(sw,INPUT_PULLUP);
                       
//......................................
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);                      //اطبع في السطر الأول العمود الأول
  //......................................
  lcd.print(" ground lingth");       //ماهو طول الأرض
  while(digitalRead(outputc)==1){
  aState = digitalRead(outputA);
  if (aState != aLastState){     
  if (digitalRead(outputB) != aState) { 
       counter1 --;//++
  } else {
       counter1 ++;//--
     }
  lcd.setCursor(1,1);                         
  lcd.print(counter1);}
  aLastState = aState;}
//......................................  
  lcd.setCursor(0,0);
  lcd.print(" ground width  ");//عرض الأرض         
  delay(500);                   
  while(digitalRead(outputc)==1){
  aState = digitalRead(outputA);
  if (aState != aLastState){     
  if (digitalRead(outputB) != aState) { 
       counter2 --;//++
  } else {
       counter2 ++;//--
     }
  lcd.setCursor(1,1);                         
  lcd.print(counter2);}

  aLastState = aState;} 
//......................................
  lcd.setCursor(0,0);                         
  lcd.print("              ");
  lcd.setCursor(1,1);                         
  lcd.print("   ");
}

void loop() {
    digitalWrite(motor3,HIGH);// تشغيل محرك عجلة البذور 
    digitalWrite(motor4,LOW );
    digitalWrite(dir1,1);
    digitalWrite(dir2,0);
     for(int x=0;x<counter1*1500;x++){
    digitalWrite(puls1,HIGH );
    digitalWrite(puls2,HIGH );
    delayMicroseconds(3000);
    digitalWrite(puls1,LOW);
    digitalWrite(puls2,LOW);
    delayMicroseconds(3000);
    }
    digitalWrite(motor3,LOW );// اطفاء محرك عجلة البذور 
    digitalWrite(motor4,LOW );
digitalWrite(motor1,HIGH );// تشغيل محرك التوجيه    
digitalWrite(motor2,LOW );
    delay(200);
    digitalWrite(motor1,LOW );// اطفاء محرك التوجيه 
    digitalWrite(motor2,LOW );
    digitalWrite(dir1,1);
    for(int x=0;x<1000;x++){
    digitalWrite(puls1,HIGH );
    delayMicroseconds(3000);
    digitalWrite(puls1,LOW);
    delayMicroseconds(3000);
    digitalWrite(motor1,HIGH );// تشغيل محرك التوجيه    
digitalWrite(motor2,LOW );
  delay(200);
     digitalWrite(motor1,LOW );// اطفاء محرك التوجيه 
    digitalWrite(motor2,HIGH);

    }
}
