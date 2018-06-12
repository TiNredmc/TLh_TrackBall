/**************************************************************************
  SparkFun BlackBerry Trackballer Breakout Demo
  Toni Klopfenstein @ SparkFun Electronics
  March 2015
  https://github.com/sparkfun/Blackberry_Trackballer_Breakout
  This demo shows all the basic functionality of the SparkFun BlackBerry Trackballer Breakout (https://www.sparkfun.com/products/13169).
  Development environment specifics:
  Developed in Arduino 1.6.0
  This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!
  Distributed as-is; no warranty is given.
***************************************************************************/
#include <USBHID.h>

const uint8_t reportDescription[] = {
  HID_ABS_MOUSE_REPORT_DESCRIPTOR(HID_MOUSE_REPORT_ID)
};

HIDAbsMouse mouse;
//Define Trackballer Breakout pin connections to Arduino
#define Btn 0
#define Lft 1
#define Rht 2
#define Up 4
#define Dwn 3
#define WHT_LED 8
#define GRN_LED 9
#define RED_LED 10
#define BLU_LED 11

//Define variables used in sketch
int buttonClick = 0;
int mouse_Lft = 0;
int mouse_Rht = 0;
int mouse_Up  = 0;
int mouse_Dwn = 0;
int x_position;
int y_position;

/*********************Setup Loop*************************/
void setup() {

  //Define pin functionality on the Arduino
  pinMode(Btn, INPUT);
  pinMode(Lft, INPUT);
  pinMode(Rht, INPUT);
  pinMode(Up, INPUT);
  pinMode(Dwn, INPUT);
  pinMode(WHT_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLU_LED, OUTPUT);

  //Pull LED pins low to prevent flickering
  digitalWrite(WHT_LED, LOW);
  digitalWrite(GRN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLU_LED, LOW);

  //Start Serial port for debugging.
  USBHID_begin_with_serial(reportDescription, sizeof(reportDescription));
}


/*********************Main Loop*************************/
void loop() {
  if (mouse_Lft != digitalRead(Lft))
  {
    x_position--;
    mouse_Lft = !mouse_Lft;
    //  mouse.move(x_position * 10 ,y_position * 10);

  }
  if (mouse_Rht != digitalRead(Rht))
  {
    x_position++;
    mouse_Rht = !mouse_Rht;
    //  mouse.move(x_position * 10 ,y_position * 10);

  }
  if (mouse_Up != digitalRead(Up))
  {
    y_position++;
    mouse_Up = !mouse_Up;
    // mouse.move(x_position * 10 ,y_position * 10);

  }
  if (mouse_Dwn != digitalRead(Dwn))
  {
    y_position--;
    mouse_Dwn = !mouse_Dwn;
    //mouse.move(x_position * 10 ,y_position * 10);

  }


  mouse.move(x_position * 700 , y_position * 700);
  //Check for button click. If present, print to Serial monitor.
  buttonClick = digitalRead(Btn);
  if (buttonClick == LOW)
  {
    mouse.press(MOUSE_LEFT);
  } else {
    mouse.release(MOUSE_LEFT);
  }
}
