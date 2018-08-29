/*
Circuit:
 -Button attached to digital pin 2 from 5V
 -10K resistor attached to pin 2 from ground

LED Circuit:
-Digital Pin LED # conncted to 1k Ohm Resistor
-1k Ohm Resistor connected to B Leg of Transistor
-E Leg of Transistor connected to GND Pin & Negative Battery Terminal
-C Leg of Transistor connected to Negative Leg of LED
-Positive Leg of LED connected to Positive Battery Terminal


 Button 1 --> Digital Pin 1
 Button 2 --> Digital Pin 2
 Button 3 --> Digital Pin 3
 Button 4 --> Digital Pin 4
 LED 1    --> Digital Pin 5
 LED 2    --> Digital Pin 6
 LED 3    --> Digital Pin 7
 LED 4    --> Digital Pin 8
 
 */

//create constant to hold number of buttons to use for loops
const int noButtons = 4;
const int Buttons_LEDs = noButtons*2;

void setup() {
  Serial.begin(9600); //Initialize serial monitor to print
  //set pinModes for buttons as inputs
  for (int j=1; j <= noButtons; j++) {
    pinMode(j, INPUT);
  }
  for (int k=noButtons; k < Buttons_LEDs; k++) {
   //set pinMode for LEDs as outputs
    pinMode(k+1, OUTPUT);
    Serial.println(k+1);
  }
}

void loop() {
  //create array to hold switch values. Intialize as OFF (0)
  int switches[ ] = {0, 0, 0, 0};

  //loop through buttons to check if they are pressed
  for (int i=0; i < noButtons; i++) {
    //counter for LEDs
    int s = i+1+noButtons;
    //save current state in corresponding switches array slot
    switches[i] = digitalRead(i+2);
    Serial.print("Button ");
    Serial.print(i+1);
    //If they are pressed print ON. If they arent print OFF.
    if (switches[i] == HIGH) {
      Serial.println(": ON.");
      digitalWrite(s, HIGH);
    }
    else {
      Serial.println(": OFF.");
      digitalWrite(s, LOW);
    }
  }
  
  Serial.println();
  delay(500); //delay before looking for new value
}
