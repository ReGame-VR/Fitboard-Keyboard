#include <Keyboard.h>
//#define KEYPAD_Up 'w'  //to use WASD
//#define KEYPAD_Down 's'
//#define KEYPAD_Left 'a'
//#define KEYPAD_Right 'd'

#define KEYPAD_Up 0xDA  //to use arrow keys    
#define KEYPAD_Down 0xD9
#define KEYPAD_Left 0xD8
#define KEYPAD_Right 0xD7

#define PIN_1 12  //Digital Pins
#define PIN_2 8
#define PIN_3 7
#define PIN_4 4


int button_up_state = 0;  //set default state to 0
int button_down_state = 0;
int button_left_state = 0;
int button_right_state = 0;

void setup() {
  pinMode(PIN_1, INPUT);  //define Pins as input
  pinMode(PIN_2, INPUT);
  pinMode(PIN_3, INPUT);
  pinMode(PIN_4, INPUT);
  Keyboard.begin();
}

void loop() {
  ReadPin_1();
  ReadPin_2();
  ReadPin_3();
  ReadPin_4();
  
}

void ReadPin_1(){
  button_up_state = digitalRead(PIN_1);
  if (button_up_state == 1){
    Keyboard.write(KEYPAD_Up);
    delay(150);
    while(button_up_state == 1){ //to prevent long press, or introduce long press delay
      button_up_state = digitalRead(PIN_1);
      //Keyboard.write(KEYPAD_Up);
      //delay(50);
    }
  }
}
void ReadPin_2(){
  button_down_state = digitalRead(PIN_2);
  if (button_down_state == 1){
    Keyboard.write(KEYPAD_Down);
    delay(150);
        while(button_down_state == 1){ //to prevent long press, or introduce long press delay
        button_down_state = digitalRead(PIN_2);  
        //Keyboard.write(KEYPAD_Down);
        //delay(50);
    }
  }
}
void ReadPin_3(){
  button_left_state = digitalRead(PIN_3);
  if (button_left_state == 1){
    Keyboard.write(KEYPAD_Left);
    delay(150);
    while(button_left_state == 1){ //to prevent long press, or introduce long press delay
      button_left_state = digitalRead(PIN_3);
      //Keyboard.write(KEYPAD_Left);
      //delay(50);  
    }
  }
}
void ReadPin_4(){
  button_right_state = digitalRead(PIN_4);
  if (button_right_state == 1){
    Keyboard.write(KEYPAD_Right);
    delay(150);
    while(button_right_state == 1){ //to prevent long press, or introduce long press delay
      button_right_state = digitalRead(PIN_4);
      //Keyboard.write(KEYPAD_Right);
      //delay(50);
    }
  }
}




