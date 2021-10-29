#include <SoftwareSerial.h>

#include <Servo.h>

SoftwareSerial phone(2,3);

int indexpos = 0;
int middlepos = 0;
int ringpos = 0;
int pinkypos = 0;
int thumbpos = 0;
Servo index;
Servo thumb;
Servo middle;
Servo ring;
Servo pinky;
String command, finger;
bool commandflag = false;

#define pin1 8
#define pin2 9
#define pin3 10
#define pin4 11
#define pin5 12

void setup() {
  // put your setup code here, to run once:
  phone.begin(9600);
  phone.setTimeout(50);
  thumb.attach(pin1);
  index.attach(pin2);
  middle.attach(pin3);
  ring.attach(pin4);
  pinky.attach(pin5);
  index.write(90);
  thumb.write(90);
  middle.write(90);
  ring.write(90);
  pinky.write(90);
  thumb.detach();
  index.detach();
  middle.detach();
  ring.detach();
  pinky.detach();
}

void loop() {
  // take command from phone
  if (commandflag == false) {
    phone.println("finger - 1,2,3,4,5: 1 is thumb, 5 is pinky");
    commandflag = true;
  }
  if (phone.available() == true) {
    finger = phone.readStringUntil('\n');
    finger.trim();
    phone.println("Type a command - close, open, mid, none");
    while (phone.available() == false);
    commandflag = false;
    command = phone.readStringUntil('\n');
    command.trim();


// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


    // take thumb command
    if (finger.equals("1")){
  
      // close finger
      if (command.equals("close")) {
        if (thumbpos == 0){
          thumb.attach(pin1);
          thumb.write(180);
          delay(460);
          thumb.write(90);
          thumb.detach();
          thumbpos = 2;
        }
        else if (thumbpos == 1){
          thumb.attach(pin1);
          thumb.write(180);
          delay(230);
          thumb.write(90);
          thumb.detach();
          thumbpos = 2;
        }
        else if (thumbpos == 2){
          phone.println("ERROR - Position alrerady reached");
        }
      }
  
      // open finger
      else if (command.equals("open")) {
        if (thumbpos == 1){
          thumb.attach(pin1);
          thumb.write(0);
          delay(230);
          thumb.write(90);
          thumb.detach();
          thumbpos = 0;
        }
        else if (thumbpos == 2){
          thumb.attach(pin1);
          thumb.write(0);
          delay(460);
          thumb.write(90);
          thumb.detach();
          thumbpos = 0;
        }
        else if (thumbpos == 0){
          phone.println("ERROR - Position alrerady reached");
        }
      }
      
      // mid finger
      else if (command.equals("mid")) {
          if (thumbpos == 0){
            thumb.attach(pin1);
            thumb.write(180);
            delay(230);
            thumb.write(90);
            thumb.detach();
            thumbpos = 1;
          }
          else if (thumbpos == 2){
            thumb.attach(pin1);
            thumb.write(0);
            delay(230);
            thumb.write(90);
            thumb.detach();
            thumbpos = 1;
          }
          else if (thumbpos == 1){
            phone.println("ERROR - Position alrerady reached");
        }
        }
  
        //no movement
        else if (command.equals("none")){
          phone.println("OK");  
        }
      }
  
  
  //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
    // index command  
    if (finger.equals("2")){
      // close finger
      if (command.equals("close")) {
        if (indexpos == 0){
          index.attach(pin2);
          index.write(180);
          delay(460);
          index.write(90);
          index.detach();
          indexpos = 2;
        }
        else if (indexpos == 1){
          index.attach(pin2);
          index.write(180);
          delay(230);
          index.write(90);
          index.detach();
          indexpos = 2;
        }
        else if (indexpos == 2){
          phone.println("ERROR - Position alrerady reached");
        }
      }
  
      // open finger
      else if (command.equals("open")) {
        if (indexpos == 1){
          index.attach(pin2);
          index.write(0);
          delay(230);
          index.write(90);
          index.detach();
          indexpos = 0;
        }
        else if (indexpos == 2){
          index.attach(pin2);
          index.write(0);
          delay(460);
          index.write(90);
          index.detach();
          indexpos = 0;
        }
        else if (indexpos == 0){
          phone.println("ERROR - Position alrerady reached");
        }
      }
      
      // mid finger
      else if (command.equals("mid")) {
          if (indexpos == 0){
            index.attach(pin2);
            index.write(180);
            delay(230);
            index.write(90);
            index.detach();
            indexpos = 1;
          }
          else if (indexpos == 2){
            index.attach(pin2);
            index.write(0);
            delay(230);
            index.write(90);
            index.detach();
            indexpos = 1;
          }
          else if (indexpos == 1){
            phone.println("ERROR - Position alrerady reached");
        }
        }
  
        //no movement
        else if (command.equals("none")){
          phone.println("OK");  
        }
      }
  
  
  //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
      
      // middle finger control
        if (finger.equals("3")){
  
      // close finger
      if (command.equals("close")) {
        if (middlepos == 0){
          middle.attach(pin3);
          middle.write(180);
          delay(460);
          middle.write(90);
          middle.detach();
          middlepos = 2;
        }
        else if (middlepos == 1){
          middle.attach(pin3);
          middle.write(180);
          delay(230);
          middle.write(90);
          middle.detach();
          middlepos = 2;
        }
        else if (middlepos == 2){
          phone.println("ERROR - Position alrerady reached");
        }
      }
  
      // open finger
      else if (command.equals("open")) {
        if (middlepos == 1){
          middle.attach(pin3);
          middle.write(0);
          delay(230);
          middle.write(90);
          middle.detach();
          middlepos = 0;
        }
        else if (middlepos == 2){
          middle.attach(pin3);
          middle.write(0);
          delay(460);
          middle.write(90);
          middle.detach();
          middlepos = 0;
        }
        else if (middlepos == 0){
          phone.println("ERROR - Position alrerady reached");
        }
      }
      
      // mid finger
      else if (command.equals("mid")) {
          if (middlepos == 0){
            middle.attach(pin3);
            middle.write(180);
            delay(230);
            middle.write(90);
            middle.detach();
            middlepos = 1;
          }
          else if (middlepos == 2){
            middle.attach(pin3);
            middle.write(0);
            delay(230);
            middle.write(90);
            middle.detach();
            middlepos = 1;
          }
          else if (middlepos == 1){
            phone.println("ERROR - Position alrerady reached");
        }
        }
  
        //no movement
        else if (command.equals("none")){
          phone.println("OK");  
        }
      }
  
  
  //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
    // ring control
      if (finger.equals("4")){
      // close finger
      if (command.equals("close")) {
        if (ringpos == 0){
          ring.attach(pin4);
          ring.write(180);
          delay(460);
          ring.write(90);
          ring.detach();
          ringpos = 2;
        }
        else if (ringpos == 1){
          ring.attach(pin4);
          ring.write(180);
          delay(230);
          ring.write(90);
          ring.detach();
          ringpos = 2;
        }
        else if (ringpos == 2){
          phone.println("ERROR - Position alrerady reached");
        }
      }
  
      // open finger
      else if (command.equals("open")) {
        if (ringpos == 1){
          ring.attach(pin4);
          ring.write(0);
          delay(230);
          ring.write(90);
          ring.detach();
          ringpos = 0;
        }
        else if (ringpos == 2){
          ring.attach(pin4);
          ring.write(0);
          delay(460);
          ring.write(90);
          ring.detach();
          ringpos = 0;
        }
        else if (ringpos == 0){
          phone.println("ERROR - Position alrerady reached");
        }
      }
      
      // mid finger
      else if (command.equals("mid")) {
          if (ringpos == 0){
            ring.attach(pin4);
            ring.write(180);
            delay(230);
            ring.write(90);
            ring.detach();
            ringpos = 1;
          }
          else if (ringpos == 2){
            ring.attach(pin4);
            ring.write(0);
            delay(230);
            ring.write(90);
            ring.detach();
            ringpos = 1;
          }
          else if (ringpos == 1){
            phone.println("ERROR - Position alrerady reached");
        }
        }
  
        //no movement
        else if (command.equals("none")){
          phone.println("OK");  
        }
      }
  
  
  //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  
    // pinky control
          if (finger.equals("5")){
      // close finger
      if (command.equals("close")) {
        if (pinkypos == 0){
          pinky.attach(pin5);
          pinky.write(180);
          delay(460);
          pinky.write(90);
          pinky.detach();
          pinkypos = 2;
        }
        else if (pinkypos == 1){
          pinky.attach(pin5);
          pinky.write(180);
          delay(230);
          pinky.write(90);
          pinky.detach();
          pinkypos = 2;
        }
        else if (pinkypos == 2){
          phone.println("ERROR - Position alrerady reached");
        }
      }
  
      // open finger
      else if (command.equals("open")) {
        if (pinkypos == 1){
          pinky.attach(pin5);
          pinky.write(0);
          delay(230);
          pinky.write(90);
          pinky.detach();
          pinkypos = 0;
        }
        else if (pinkypos == 2){
          pinky.attach(pin5);
          pinky.write(0);
          delay(460);
          pinky.write(90);
          pinky.detach();
          pinkypos = 0;
        }
        else if (pinkypos == 0){
          phone.println("ERROR - Position alrerady reached");
        }
      }
      
      // mid finger
      else if (command.equals("mid")) {
          if (pinkypos == 0){
            pinky.attach(pin5);
            pinky.write(180);
            delay(230);
            pinky.write(90);
            pinky.detach();
            pinkypos = 1;
          }
          else if (pinkypos == 2){
            pinky.attach(pin5);
            pinky.write(0);
            delay(230);
            pinky.write(90);
            pinky.detach();
            pinkypos = 1;
          }
          else if (pinkypos == 1){
            phone.println("ERROR - Position alrerady reached");
        }
        }
  
        //no movement
        else if (command.equals("none")){
          phone.println("OK");  
        }
      }
      
  }
  
}
