/*
Circuit:
-Flexsensor attached to A5 from 5V
-10K resistor attached to A5 from ground
*/

//Pin Number
const int FlexPin_1 = A5; // Analog Pin
const int FlexPin_2 = A4; // Analog Pin
const int FlexPin_3 = A3; // Analog Pin
const int FlexPin_4 = A2; // Analog Pin


//Constants
const int VCC = 5; //for voltage conversion, value of Arduino's volt supply
const double VoltCutoff = 3.75; //an arbratrary cut off for how hard sensor must be pressed to activate 

void setup() {
  Serial.begin(9600); //Initialize serial monitor to print
  pinMode(FlexPin_1, INPUT); //Set FlexPin_1 as an input
}

void loop() 
{
  int switch_1 = 0;
  int switch_2 = 0;
  int switch_3 = 0;
  int switch_4 = 0;
  
  // Read the ADC (analog-to-digial converter), and calculate voltage from it
  int flexADC_1 = analogRead(FlexPin_1);
  float flexV_1 = flexADC_1 * VCC / 1023.0;

  int flexADC_2 = analogRead(FlexPin_2);
  float flexV_2 = flexADC_2 * VCC / 1023.0;
  
  int flexADC_3 = analogRead(FlexPin_3);
  float flexV_3 = flexADC_3 * VCC / 1023.0;

  int flexADC_4 = analogRead(FlexPin_4);
  float flexV_4 = flexADC_4 * VCC / 1023.0;
  
if (flexV_1 >= VoltCutoff) {
  switch_1 = 1;
}
if (flexV_2 >= VoltCutoff) {
  switch_2 = 1;
}
if (flexV_3 >= VoltCutoff) {
  switch_3 = 1;
}
if (flexV_4 >= VoltCutoff) {
  switch_4 = 1;
}

float voltes[ ] = {flexV_1, flexV_2, flexV_3, flexV_4};
int switches[ ] = {switch_1, switch_2, switch_3, switch_4};

for (int i=0; i < sizeof(switches); i++) {
  if (switches[i] == 1) {
    Serial.print("Switch ");
    Serial.print(i+1);
    Serial.print(": On... ");
    Serial.println(voltes[i]);
  }
  }

Serial.println();
delay(500); 
}

