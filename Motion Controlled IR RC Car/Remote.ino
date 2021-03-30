#include <IRremote.h>
#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;

int16_t x, y, z;
int16_t gx, gy, gz;

#define OUTPUT_READABLE_ACCELGYRO

IRsend IrSender;

#define goForward 22
#define goBackward 11
#define goRight 21
#define goLeft 12
#define halt 33

void setup(){
 #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.begin(74880);

    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}
void loop(){
  accelgyro.getMotion6(&x, &y, &z, &gx, &gy, &gz);
   
  Serial.print("AngleX= ");
  Serial.println(x);
   
  Serial.print("AngleY= ");
  Serial.println(y);
   
  Serial.print("AngleZ= ");
  Serial.println(z);
  Serial.println("-----------------------------------------");

    if(y > 4000) {
      // Go Left 
       Serial.println("Go Left"); 
       IrSender.sendNEC(goLeft, 12);
    }
  
    else if(y < -8000) {
      // Go Right  
       Serial.println("Go Right");
       IrSender.sendNEC(goRight, 12);
    }
    
    else if(x < -3500){
      // Go Front
       Serial.println("Go Front");
       IrSender.sendNEC(goForward, 12);
    }
    
    else if( x > 5000){
      // Go Back
       Serial.println("Go Back");
       IrSender.sendNEC(goBackward, 12);
    }
  
    else{
      Serial.println("Halt");
      IrSender.sendNEC(halt, 12);
    }
  
  delay(100);
}
