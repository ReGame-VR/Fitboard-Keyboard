  /*
   The circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pin 2
  * ECHO connection of the sensor attached to digital pin 4
 */

//Digital Pin Numbers
const int TRIG_1 = 3;
const int ECHO_1 = 4;
const int TRIG_2 = 5;
const int ECHO_2 = 6;
const int TRIG_3 = 7;
const int ECHO_3 = 8;
const int TRIG_4 = 9;
const int ECHO_4 = 10;
//Constants
const int MAX_DIST = 10; //create distance activation range in cm 
const int MIN_DIST = 3; //create minimum distance for activation
const int noButtons = 4; //for loops


void setup() {
  // initialize serial communication to pring
  Serial.begin(9600);
  //Set digital pins as outputs / inputs
  for (int k=3; k < 3 + (2*noButtons); k=k+2) {
    pinMode(k, OUTPUT);
    pinMode(k+1, INPUT);
  }
}

void loop()
{
  int switches[ ] = {0,0,0,0}; //initialize switch array as OFF
  long dists[ ] = {0,0,0,0}; //initialize distance array

  // Loop to get distances for each sensor
  for (int i=3; i < 3 + (2*noButtons); i=i+2) {
    int n = (i-3)/2; //counter for array
    pulse_sig(i); //send signal for a sensor
    dists[n] = microsecondsToCentimeters(pulseIn(i+1, HIGH)); //hold distance in array
  }
  //test distance against max and min
  for (int s=0; s < noButtons; s++){
    //if within range, turn switch to on
    if ((dists[s] <= MAX_DIST) && (dists[s] >= MIN_DIST)) {
      switches[s] = 1;
    }
    //report
    Serial.print("Sensor ");
    Serial.print(s+1);
    if (switches[s] == 1) {
      Serial.println(" : ON.");
    }
    else {
      Serial.println(" : OFF.");
    }
  }
  
  Serial.println();
  delay(5);
}

//funtion to calculate distance from microsecond delay
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The signal travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
//function to send signal for sensor
void pulse_sig(int j)
{
  digitalWrite(j, LOW);
  delayMicroseconds(2);
  digitalWrite(j, HIGH);
  delayMicroseconds(10);
  digitalWrite(j, LOW);
}
