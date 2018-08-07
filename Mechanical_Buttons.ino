/*
Circuit:
 -Button attached to digital pin 2 from 5V
 -10K resistor attached to pin 2 from ground
 */

//Pin Number
const int ButtonPin_1 = 1; //digital pin
const int ButtonPin_2 = 2; //digital pin
const int ButtonPin_3 = 3; //digital pin
const int ButtonPin_4 = 4; //digital pin

// variables will change:
int ButtonPin_1State = 0; //intialize state
int ButtonPin_2State = 0; //intialize state
int ButtonPin_3State = 0; //intialize state
int ButtonPin_4State = 0; //intialize state

void setup() {
  Serial.begin(9600); //Initialize serial monitor to print
  pinMode(ButtonPin_1, INPUT); //initialize as an input
  pinMode(ButtonPin_2, INPUT); //initialize as an input
  pinMode(ButtonPin_3, INPUT); //initialize as an input
  pinMode(ButtonPin_4, INPUT); //initialize as an input
}

void loop() {
  //initialize switch variables to OFF (0)
  int switch_1 = 0;
  int switch_2 = 0;
  int switch_3 = 0;
  int switch_4 = 0;
  
  
  //get Button states
  ButtonPin_1State = digitalRead(ButtonPin_1);
  ButtonPin_2State = digitalRead(ButtonPin_2);
  ButtonPin_3State = digitalRead(ButtonPin_3);
  ButtonPin_4State = digitalRead(ButtonPin_4);
  
  Serial.println("Checking:");
  //if ButtonPin_1 is pressed print 'On'
  if (ButtonPin_1State == HIGH) {
    Serial.println("Button1: On");
    //switch_1 = 1;
  }
  else if (ButtonPin_2State == HIGH) {
    Serial.println("Button2: On");
    //switch_2 = 1;
  }
  else if (ButtonPin_3State == HIGH) {
    Serial.println("Button3: On");
    //switch_3 = 1;
  }
  else if (ButtonPin_4State == HIGH) {
    Serial.println("Button4: On");
    //switch_4 = 1;
  }

  
  /*
  //create an arry to hold all switch values
  int switches[ ] = {switch_1, switch_2, switch_3, switch_4};

  //loop through array of switches to check which are ON
  for (int i=0; i < sizeof(switches); i++) {
    if (switches[i] == 1) {
      Serial.print("Button ");
      Serial.print(i+1);
      Serial.print(": On");
    }
  }
    
   */
  
  Serial.println();
  delay(500); //delay before looking for new value
}
