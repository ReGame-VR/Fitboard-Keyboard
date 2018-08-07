  /*
   The circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pin 2
  * ECHO connection of the sensor attached to digital pin 4
 */

//Digital Pin Numbers
const int TRIG_1 = 3;
const int TRIG_2 = 5;
const int TRIG_3 = 7;
const int TRIG_4 = 9;
const int ECHO_1 = 4;
const int ECHO_2 = 6;
const int ECHO_3 = 8;
const int ECHO_4 = 10;

//Constants
MAX_DIST = 10; //create distance activation range in cm 
MIN_DIST = 3;

void setup() {
  // initialize serial communication to pring
  Serial.begin(9600);
  //Set digital pins as outputs or inputs
  pinMode(TRIG_1, OUTPUT);
  pinMode(TRIG_2, OUTPUT);
  pinMode(TRIG_3, OUTPUT);
  pinMode(TRIG_4, OUTPUT);
  pinMode(ECHO_1, INPUT);
  pinMode(ECHO_2, INPUT);
  pinMode(ECHO_3, INPUT);
  pinMode(ECHO_4, INPUT);
}

void loop()
{
  //create variables for duration of the signal, 
  long dur_1, dur_2, dur_3, dur_4;
  // create variables for the distance:
  long dist_1, dist_2, dist_3, dist_4;
  // initialize switch positions as OFF (0)
  int switch_1 = 0;
  int switch_2 = 0;
  int switch_3 = 0;
  int switch_4 = 0;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_1, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  dur_1 = pulseIn(ECHO_1, HIGH);
  
  digitalWrite(TRIG_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_2, LOW);
  
  dur_2 = pulseIn(ECHO_2, HIGH);
    
  digitalWrite(TRIG_3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_3, LOW);
  
  dur_3 = pulseIn(ECHO_3, HIGH);
    
  digitalWrite(TRIG_4, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_4, LOW);
  
  dur_4 = pulseIn(ECHO_4, HIGH);

  // convert the time into a distance of centemeters
  dist_1 = microsecondsToCentimeters(dur_1);
  dist_2 = microsecondsToCentimeters(dur_2);
  dist_3 = microsecondsToCentimeters(dur_3);
  dist_4 = microsecondsToCentimeters(dur_4);
  
  //Test distances to be within range
  //if in range, change switch to ON (1)

  if ((dist_1 <= MAX_DIST) && (dist_1 >= MIN_DIST)) {
    switch_1 = 1;
  }
  if ((dist_2 <= MAX_DIST) && (dist_2 >= MIN_DIST)) {
    switch_2 = 1;
  }
  if ((dist_3 <= MAX_DIST) && (dist_3 >= MIN_DIST)) {
    switch_3 = 1;
  }
  if ((dist_4 <= MAX_DIST) && (dist_4 >= MIN_DIST)) {
    switch_4 = 1;
  }

  // create array to hold distances and switch conditions
  float distances[ ] = {dist_1, dist_2, dist_3, dist_4};
  int switches[ ] = {switch_1, switch_2, switch_3, switch_4}; 

  //loop through switch array to check if they are on
  for (int i=0; i < sizeof(switches) / sizeof(int); i++) {
    if (switches[i] == 1) {
      Serial.print("Switch ");
      Serial.print(i+1);
      Serial.print(": On... ");
      Serial.println(distances[i]);
    }
  }

  Serial.println();
  delay(500);
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The signal travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
