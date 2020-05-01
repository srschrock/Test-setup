/*
   Preliminary code to run a cyclic test
   Velovations Enterprise / Somer Schrock
   April 19, 2020
*/

int travelT = 12 * 1000; //actuation time (ms)
int endT = 0; //delay time after finishing a cycle
int cycleCount = 0; //number of cycles

void setup() {
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  Serial.println("Prepare to have your brain shattered");
  delay(200);
  Serial.println("Firing up the test...");
  motor_setup(); //defining pins, etc
  displaysetup(); //setup for display
  displayloop(); //runs once to start w/ zero while waiting for first cycle
}

void loop() {
  sensorloop(); //waiting for input from sensor

  actuatorPunch();

  actuatorPull();
  delay(travelT); //time for the actuator to complete the travel

  actuatorPush();
  delay(travelT); //time for the actuator to complete the travel

  displayloop(); //update cycle count on serial display
  cycleCount++;// adding to the cycle count for cutoff purposes

  actuatorOff();
  delay(50); //pause for dramatic effect

  while (cycleCount == 7900) {
    delay(10000000000000)
  }
}
}// loop end
