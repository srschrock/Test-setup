/*
    Sensor reading
    Connect a push button from VCC to input 13
    The push button will be hit by the seat post returning to locked position. 
    A spring pushes the seat post release out to the push button sensor
*/

int in = 13;

//loop to wait for button to 
void sensorloop() {
  int once = 1;
  while (digitalRead(in) == LOW) {
    if (once == 1) {
      Serial.println("waiting for sensor to be hit...");
      once = 2;
    }
    delay(50); //slight buffer in the while loop
  }

  Serial.println("Sensor was hit, starting next cycle");
}
