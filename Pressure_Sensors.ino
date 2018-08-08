/*
Circuit:
-Flexsensor attached to A5 from 5V
-10K resistor attached to A5 from ground

Sensor 1 --> Analog Pin 1
Sensor 2 --> Analog Pin 1
Sensor 3 --> Analog Pin 1
Sensor 4 --> Analog Pin 1
*/

//Constants
const int VCC = 5; //for voltage conversion, value of Arduino's volt supply
const double VoltCutoff = 3.75; //an arbratrary cut off for how hard sensor must be pressed to activate 

void setup() {
  Serial.begin(9600); //Initialize serial monitor to print
}

void loop() 
{
  //create array for switch (start as OFF (0) ) and voltage values
  int switches[ ] = {0, 0, 0, 0};
  //create array to hold values of voltage read from pressure sensors
  float volts[sizeof(switches)/sizeof(int)];

  //loop through the four sensors
  for (int i=0; i < sizeof(switches)/sizeof(int); i++) {
    int j = i+1; //add counter to correspond to pin the sensor is in
    volts[i] = analogRead(j) * VCC / 1023.0; //read voltage of pin
    //test if read voltage is higher than cut off voltage
    if (volts[i] >= VoltCutoff){
      switches[i] = 1; //if higher change the corresponding switch to ON (1)
    }
    //print the switch state and voltage read
    Serial.print(switches[i]);
    Serial.print("\t");
    Serial.println(volts[i]);
  }
//delay for stability
Serial.println();
delay(500); 
}
