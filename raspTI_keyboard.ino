/*
KEYMAP as found here: http://www.nouspikel.com/ti99/titechpages.htm
 
 # = wire from left to right looking at keyboard from normal orientation
 
      #12  #13  #14  #15  #9  #8  #6
 #5    =    .    ,    M    N   /   
 #4  spac   L    K    J    H   ;
 #1  entr   O    I    U    Y   P
 #2         9    8    7    6   0
 #7  fctn   2    3    4    5   1  lock
 #3  shft   S    D    F    G   A
 #10 ctrl   W    E    R    T   Q
 #11        X    C    V    B   Z
 
 */

#include <Bounce.h>
const int bounceDelay = 90;

char left = KEY_LEFT_ARROW;

Bounce wire1  = Bounce(10, bounceDelay);
Bounce wire3  = Bounce(12, bounceDelay);
Bounce wire4  = Bounce(13, bounceDelay);
Bounce wire5  = Bounce(14, bounceDelay);
Bounce wire6  = Bounce(15, bounceDelay);
Bounce wire7  = Bounce(16, bounceDelay);
Bounce wire8  = Bounce(17, bounceDelay);
Bounce wire9  = Bounce(45, bounceDelay);
Bounce wire10 = Bounce(44, bounceDelay);
Bounce wire11 = Bounce(43, bounceDelay);
Bounce wire12 = Bounce(42, bounceDelay);
Bounce wire13 = Bounce(41, bounceDelay);
Bounce wire14 = Bounce(40, bounceDelay);
Bounce wire15 = Bounce(39, bounceDelay);

boolean fctn;
boolean shft;
boolean ctrl;
boolean lock;


void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT);  // 1 
  pinMode(11, OUTPUT);  // 2
  pinMode(12, OUTPUT);  // 3
  pinMode(13, OUTPUT);  // 4
  pinMode(14, OUTPUT);  // 5
  pinMode(15, INPUT );  // 6
  pinMode(16, OUTPUT);  // 7
  pinMode(17, INPUT );  // 8
  pinMode(45, INPUT );  // 9
  pinMode(44, OUTPUT);  // 10
  pinMode(43, OUTPUT);  // 11
  pinMode(42, INPUT );  // 12
  pinMode(41, INPUT );  // 13
  pinMode(40, INPUT );  // 14 
  pinMode(39, INPUT );  // 15
}


void loop(){
  // Write HIGH to each OUTPUT pin (row in matrix diagram above), one at a time.
  // Check all INPUT pins (column in matrix diagram abobve) for a signal.
  // If a signal is detected, write the character (@ the intersection of the row/column).

  checkModifiers();
  
  // ------------------------ Wire 1 @ PIN 10
  digitalWrite(10, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  wire12.update(); 
  
  // ----------------------- P
  if(wire8.risingEdge()){
   if(lock == true){ 
    Keyboard.print('P'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('P'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('"');
     fctn = false;
   } else {
   Keyboard.print('p'); 
   } 
  }
  
  // ----------------------- Y
  if(wire9.risingEdge()){
   if(lock == true){ 
    Keyboard.print('Y'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('Y'); 
     shft = false;
   }
   else {
   Keyboard.print('y'); 
   }
  }
  
  // ----------------------- U
  if(wire15.risingEdge()){
   if(lock == true){ 
    Keyboard.print('U'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('U'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('_');
     fctn = false;
   } 
   else {
   Keyboard.print('u'); 
   }
  }
  
  // ----------------------- I
  if(wire14.risingEdge()){
   if(lock == true){ 
    Keyboard.print('I'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('I'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('?');
     fctn = false;
   } else {
   Keyboard.print('i'); 
   } 
  } 
  
  // ----------------------- O
  if(wire13.risingEdge()){
   if(lock == true){ 
    Keyboard.print('O'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('O'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('\'');
     fctn = false;
   } else {
   Keyboard.print('o'); 
   }
  }
  
  // ----------------------- ENTER
  if(wire12.risingEdge()){
   Keyboard.print('\n'); 
  }  
  digitalWrite(10, LOW);
  

  // -------------------------- Wire 2 @ PIN 11
  digitalWrite(11, HIGH); 
  wire6.update();
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  // ----------------------- 0
  if(wire8.risingEdge()){
   if(shft == true){
     Keyboard.print(')'); 
     shft = false;
   } else {
   Keyboard.print('0'); 
   } 
  }
  
  // ----------------------- 6
  if(wire9.risingEdge()){
   if(shft == true){
     Keyboard.print('^'); 
     shft = false;
   } else {
   Keyboard.print('6'); 
   }
  }
  
  // ----------------------- 7
  if(wire15.risingEdge()){
   if(shft == true){
     Keyboard.print('&'); 
     shft = false;
   } else {
   Keyboard.print('7'); 
   }
  }
  
  // ----------------------- 8
  if(wire14.risingEdge()){
   if(shft == true){
     Keyboard.print('*'); 
     shft = false;
   } else {
   Keyboard.print('8'); 
   }
  }
  
  // ----------------------- 9
  if(wire13.risingEdge()){
   if(shft == true){
     Keyboard.print('('); 
     shft = false;
   } else {
   Keyboard.print('9'); 
   }
  } 
  digitalWrite(11, LOW);


  // ------------------------ Wire 3 @ PIN 12
  digitalWrite(12, HIGH); 
  wire6.update();
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  // ----------------------- A
  if(wire8.risingEdge()){
   if(lock == true){ 
    Keyboard.print('A'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('A'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print(':');
     fctn = false;
   } else {
   Keyboard.print('a'); 
   }
  }
  
  // ----------------------- G
  if(wire9.risingEdge()){
   if(lock == true){ 
    Keyboard.print('G'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('G'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('}');
     fctn = false;
   } else {
   Keyboard.print('g'); 
   }
  }
  
  // ----------------------- F
  if(wire15.risingEdge()){
   if(lock == true){ 
    Keyboard.print('F'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('F'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.print('{');
     fctn = false;
   } else {
   Keyboard.print('f'); 
   }
  }
  
  // ----------------------- D
  if(wire14.risingEdge()){
   if(lock == true){ 
    Keyboard.print('D'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('D'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.press(KEY_RIGHT_ARROW);
     Keyboard.release(KEY_RIGHT_ARROW);
     fctn = false;
   } else {
   Keyboard.print('d'); 
   }
  }
  
  // ----------------------- S
  if(wire13.risingEdge()){
   if(lock == true){ 
    Keyboard.print('S'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('S'); 
     shft = false;
   }
   else if(fctn == true) {
     Keyboard.press(KEY_LEFT_ARROW);
     Keyboard.release(KEY_LEFT_ARROW);
     fctn = false;
   } else {
   Keyboard.print('s'); 
   }
  }
  digitalWrite(12, LOW);
  
  
  // ------------------------ Wire 4 @ PIN 13
  digitalWrite(13, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  wire12.update();  
  
  if(wire8.risingEdge()){
   Keyboard.print(';'); 
  }
  if(wire9.risingEdge()){
   Keyboard.print('h'); 
  }
  if(wire15.risingEdge()){
   Keyboard.print('j'); 
  }
  if(wire14.risingEdge()){
   Keyboard.print('k'); 
  }
  if(wire13.risingEdge()){
   Keyboard.print('l'); 
  }
  if(wire12.risingEdge()){
   Keyboard.print(' '); 
  }  
  digitalWrite(13, LOW);

  
  // ------------------------ Wire 5 @ PIN 14
  digitalWrite(14, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  wire12.update();  
  
  if(wire8.risingEdge()){
   Keyboard.print('/'); 
  }
  if(wire9.risingEdge()){
   Keyboard.print('n'); 
  }
  if(wire15.risingEdge()){
   Keyboard.print('m'); 
  }
  if(wire14.risingEdge()){
   Keyboard.print(','); 
  }
  if(wire13.risingEdge()){
   Keyboard.print('.'); 
  }
  if(wire12.risingEdge()){
   Keyboard.print('='); 
  }  
  digitalWrite(14, LOW);

  
  // ------------------------ Wire 7 @ PIN 16
  digitalWrite(16, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();

  if(wire8.risingEdge()){
   Keyboard.print('1'); 
  }
  if(wire9.risingEdge()){
   Keyboard.print('5'); 
  } 
  if(wire15.risingEdge()){
   Keyboard.print('4'); 
  } 
  if(wire14.risingEdge()){
   Keyboard.print('3'); 
  }  
  if(wire13.risingEdge()){
   Keyboard.print('2'); 
  }
  digitalWrite(16, LOW);

  
  // ------------------------ Wire 10 @ PIN 44
  digitalWrite(44, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  if(wire8.risingEdge()){
   Keyboard.print('q'); 
  } 
  if(wire9.risingEdge()){
   Keyboard.print('t'); 
  }  
  if(wire15.risingEdge()){
   Keyboard.print('r'); 
  }  
  if(wire14.risingEdge()){
   Keyboard.print('e'); 
  } 
  if(wire13.risingEdge()){
   Keyboard.print('w'); 
  } 
  digitalWrite(44, LOW);

  
  // ------------------------ Wire 11 @ PIN 43
  digitalWrite(43, HIGH); 
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  if(wire8.risingEdge()){
   Keyboard.print('z'); 
  } 
  if(wire9.risingEdge()){
   Keyboard.print('b'); 
  } 
  if(wire15.risingEdge()){
   Keyboard.print('v'); 
  } 
  if(wire14.risingEdge()){
   Keyboard.print('c'); 
  } 
  if(wire13.risingEdge()){
   Keyboard.print('x'); 
  } 
  digitalWrite(43, LOW);
}


//--------------------------  MODIFIER KEYS
void checkModifiers(){ 
  
  // ------------------------ Wire 3 @ PIN 12: shft
  digitalWrite(12, HIGH);
  wire12.update();
  if(digitalRead(42) == 1){
   shft = true; 
  } else {
   shft = false; 
  }
  digitalWrite(12, LOW);
  
  // ------------------------ Wire 7 @ PIN 16: fctn & lock
  digitalWrite(16, HIGH); 
  wire12.update();
  wire6.update(); 
  if(digitalRead(42) == 1){
   fctn = true; 
  } else {
   fctn = false; 
  }
  if(digitalRead(15) == 1){
   lock = true; 
  } else {
   lock = false; 
  }
  digitalWrite(16, LOW);
 
   
  // ------------------------ Wire 10 @ PIN 44: ctrl
  digitalWrite(44, HIGH);
  wire12.update();
  if(digitalRead(42) == 1){
   ctrl = true; 
  } else {
   ctrl = false; 
  }
  digitalWrite(44, LOW);
}


