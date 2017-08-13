
//This library is for the brake servo
#include <Servo.h>

int ch1; // Here's where we'll keep our channel values
int brake_servo_pin = 9;

Servo brake_servo;
int brake_value = 60;
int unbrake_value = 150;

int servo_value;


void setup() {

  pinMode(5, INPUT); // Set our input pins as such
  brake_servo.attach(brake_servo_pin);

  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {

  ch1 = pulseIn(5, HIGH, 25000); // Read the pulse width of 

  Serial.print("Channel 1:"); // Print the value of 
  Serial.println(ch1);        // each channel
  
  if (ch1 < 1300 && ch1 > 800) {
    // Sometimes it reads zero so I dont want it to fuck up
    //we will brake! 
    Serial.println("Brake!");
    if (servo_value != brake_value) {
      brake_servo.write(brake_value);
      servo_value = brake_value;
    }
    
  } else if (ch1 > 1350 ) {
    //This means that we have throttle!
     
    if (servo_value != unbrake_value) {
      brake_servo.write(unbrake_value);
      servo_value = unbrake_value;
    }
    
  }

  delay(100); // I put this here just to make the terminal 
              // window happier+
}
