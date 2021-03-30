#include <IRremote.h>

IRrecv irrecv(2);     
decode_results results;

#define motorLeft1 12
#define motorLeft2 11
#define motorRight1 10
#define motorRight2 9

void halt() {
  Serial.println("Halting...");
  
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, LOW);
  
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, LOW);
}

void forward() {
  Serial.println("Going backward...");
  
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, HIGH);
  
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, HIGH);   
}

void backward() {
  Serial.println("Going forward...");
  
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void turnLeft() {
  Serial.println("Turning left...");
  
  digitalWrite(motorLeft1, LOW);
  digitalWrite(motorLeft2, HIGH);
  
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, LOW);
}

void turnRight() {
  Serial.println("Turning right...");
  
  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, LOW);
  
  digitalWrite(motorRight1, LOW);
  digitalWrite(motorRight2, HIGH);
}

void setup() {
  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  
  Serial.begin(74880);

  irrecv.enableIRIn();

  halt();
}

void loop() {
  if (irrecv.decode(&results)) {
    int sign = results.value;

    switch(sign){
      case 241307256:
        forward();
      break;
      
      case 2873260659:
        backward();
      break;

      case 951854522:
        turnLeft();
      break;

      case 4282632653:
        turnRight();
      break;

      // TV Remote Controlled IR Codes down below:
        
      case 752:
        forward();
      break;

      case 2800:
        backward();
      break;

      case 720: 
        turnLeft();
      break;
      
      case 3280 :
        turnRight();
      break;

      default:
        halt();
        Serial.println(sign);
    }
    
    irrecv.resume(); 
  } 
}
