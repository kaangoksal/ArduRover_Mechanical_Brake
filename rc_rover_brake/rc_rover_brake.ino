
//This library is for the brake servo
#include <Servo.h>



//pin of the brake servo
int brake_servo_pin = 9;
//pin of the esc throttle pin
int esc_throttle_pin = 5;

int brake_value = 60;
int unbrake_value = 150;

//The servo which is attached to the brakes
Servo brake_servo;
//we store the servo value to make sure that we dont update the servo too frequently
int servo_value;
//the esc_throttle value is stored in this variable
int ch1;

void setup() {

  pinMode(5esc_throttle_pin, INPUT); // Set our input pins as such
  brake_servo.attach(brake_servo_pin);

  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {

  ch1 = pulseIn(esc_throttle_pin, HIGH, 25000); // Read the pulse width of

  Serial.print("Channel 1:");
  Serial.println(ch1);

  if (ch1 < 1300 && ch1 > 800) {
    // Sometimes it reads zero so I dont want it to fuck up
    //we will brake!
    Serial.println("Brake!");
    if (servo_value != brake_value) {
      brake_servo.write(brake_value);
      servo_value = brake_value;
    }

  } else if (ch1 > 1350) {
    //This means that we have throttle!

    if (servo_value != unbrake_value) {
      brake_servo.write(unbrake_value);
      servo_value = unbrake_value;
    }

  }

  delay(100);
}
