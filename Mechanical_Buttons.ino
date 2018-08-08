/*
Circuit:
 -Button attached to digital pin 2 from 5V
 -10K resistor attached to pin 2 from ground

 Button 1 --> Digital Pin 2
 Button 2 --> Digital Pin 3
 Button 3 --> Digital Pin 4
 Button 4 --> Digital Pin 5
 */

//create constant to hold number of buttons to use for loops
const int noButtons = 4;

void setup() {
  Serial.begin(9600); //Initialize serial monitor to print
  //set pinModes for buttons as inputs
  for (int j=1; j <= noButtons; j++) {
    pinMode(j+1, INPUT);
  }
}

void loop() {
  //create array to hold switch values. Intialize as OFF (0)
  int switches[ ] = {0, 0, 0, 0};

  //loop through buttons to check if they are pressed
  for (int i=0; i < noButtons; i++) {
    //save current state in corresponding switches array slot
    switches[i] = digitalRead(i+2);
    Serial.print("Button ");
    Serial.print(i+1);
    //If they are pressed print ON. If they arent print OFF.
    if (switches[i] == HIGH) {
      
      Serial.println(": ON.");
    }
    else {
      Serial.println(": OFF.");
    }
  }
  
  Serial.println();
  delay(500); //delay before looking for new value
}
