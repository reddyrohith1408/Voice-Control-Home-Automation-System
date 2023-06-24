#include <Servo.h>
Servo myservo;
char t;
void setup() 
{    
    myservo.attach(9);    
    pinMode(5, OUTPUT);              //left motors reverse     
    pinMode(12, OUTPUT);     
    myservo.write(180);               //left motors reverse    
    Serial.begin(9600);
}
void loop()
 {  
  if (Serial.available())
    {       t = Serial.read();  
             Serial.println(t);  }
if (t == ‘light  on’) 
{  
    digitalWrite(5, HIGH); 
    delay(2000);     
    Serial.print("room light on");    
  } 
 else if (t == ‘light  off’)
 { 
    digitalWrite(5, LOW);  
    delay(2000);   
     Serial.print("room light off"); 
     } 
else if (t == ‘fan on’)
 { 
     digitalWrite(12, HIGH); 
     delay(2000); 
     Serial.print("fan turned on");    
  } 
 else if (t == ‘fan off’)
 { 
    digitalWrite(12, LOW);     
    delay(2000);    
    Serial.print("fan turned off");
      } 
 else if (t ==‘door open’)
 {
     myservo.write(180);    
     delay(200);   
     myservo.write(90); 
     Serial.print("door open"); 
     }  
else if (t == ‘door close’)
 {  
     myservo.write(0);   
     delay(2000); 
     Serial.print("door close"); 
     } 
 delay(1000);
else if (rcv == "on all") 
{
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      Serial.println("all appliances turned on");
    }
else if (rcv == "off all") 
{
      digitalWrite(5, LOW);
      digitalWrite(12, LOW);
      Serial.println(“all appliances turned off");
    }
}

