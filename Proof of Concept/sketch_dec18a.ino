#include <Servo.h>

Servo LA;
Servo claws;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);
  LA.attach(9);  // attaches the servo on pin 9 to the servo object
  claws.attach(10);
  claws.write(45);
}

void openC(){
  claws.write(0);
}
void closeC(){
  claws.write(45);  
}


void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                Serial.println(incomingByte);
                // say what you got:
                Serial.println("received: ");
                Serial.println (incomingByte);
                if(incomingByte == 108){
                 Serial.println(" sent 0 Rotaing CW "); 
                 LA.write(0); 
                }else if(incomingByte == 114){
                  Serial.println(" sent 180 Rotaing CCW "); 
                  LA.write(180); 
                }else if(incomingByte == 115){
                  Serial.println(" sent Stopped "); 
                  LA.write(90); 
                }else if (incomingByte == 49){
                  Serial.println("claws 0deg");
                  claws.write(0);
                }else if (incomingByte == 50){
                  Serial.println("claws 45deg");
                  claws.write(45);
                 }else if (incomingByte == 51){
                  Serial.println("claws 90deg");
                  claws.write(90);
                 }else if(incomingByte==100){
                  Serial.println("sent Demo");
                  openC();
                  delay(200);
                  LA.write(0);
                  delay(1400);
                  LA.write(90);
                  delay(500);
                  closeC();
                  delay(200);
                  LA.write(180);
                  delay(1400);
                  LA.write(90);
                  delay(500);
                  openC();
                  delay(800);
                  closeC();
                  
                  }
                }else{Serial.println("broke");
             
                  
                 
        }

  
} 
