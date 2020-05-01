/*
    Controlling the actuators with a relay board
    An Arduino 4 relay board was used
*/

//wiring from the arduino board to the relay board
const int relay1 = 2;
const int relay2 = 3;
const int relay4 = 5;

void motor_setup() {
  pinMode(relay1, OUTPUT);// set pin as output for relay 1
  pinMode(relay2, OUTPUT);// set pin as output for relay 2
  pinMode(relay4, OUTPUT);// set pin as output for relay 4

  // start w/ motor off by keeping both HIGH
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);

  //starts the punch actuator in the retracted position
  digitalWrite(relay4, LOW);
}
void actuatorPush() {
  digitalWrite(relay1, LOW);// turn relay 1 ON
  digitalWrite(relay2, HIGH);// turn relay 2 OFF
}//actuatorPush()

void actuatorPull() {
  digitalWrite(relay1, HIGH);// turn relay 1 OFF
  digitalWrite(relay2, LOW);// turn relay 2 ON
}//actuatorPull()

//stopping the actuator
void actuatorOff() {
  digitalWrite(relay1, HIGH); //relay off
  digitalWrite(relay2, HIGH); //relay off
}//actuatorOff()

//making the punch actuator hit the release, then retract
void actuatorPunch() {
  digitalWrite(relay4, HIGH);// turn relay 2 ON
  delay(2 * 1000);
  digitalWrite(relay4, LOW); // return
  delay(0.5 * 1000);
}//actuatorPunch()
