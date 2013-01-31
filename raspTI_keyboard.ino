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

Bounce wire1  = Bounce(10, 90);
Bounce wire2  = Bounce(11, 90);
Bounce wire3  = Bounce(12, 90);
Bounce wire4  = Bounce(13, 90);
Bounce wire5  = Bounce(14, 90);
Bounce wire6  = Bounce(15, 90);
Bounce wire7  = Bounce(16, 90);
Bounce wire8  = Bounce(17, 90);
Bounce wire9  = Bounce(45, 90);
Bounce wire10 = Bounce(44, 90);
Bounce wire11 = Bounce(43, 90);
Bounce wire12 = Bounce(42, 90);
Bounce wire13 = Bounce(41, 90);
Bounce wire14 = Bounce(40, 90);
Bounce wire15 = Bounce(39, 90);

boolean fctn;
boolean shft;
boolean ctrl;
boolean lock;


void setup(){
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
  
  if(wire8.risingEdge()){
   if(lock == true){ 
    Keyboard.print('P'); 
    lock = false;
   } 
   else if(shft == true){
     Keyboard.print('P'); 
     shft = false;
   }
   else if(ctrl == true) {
     Keyboard.print('"');
     ctrl = false;
   } else {
   Keyboard.print('p'); 
   } 
  }
  
  if(wire9.risingEdge()){
   Keyboard.print('y'); 
  }
  if(wire15.risingEdge()){
   Keyboard.print('u'); 
  }
  if(wire14.risingEdge()){
   Keyboard.print('i'); 
  }
  if(wire13.risingEdge()){
   Keyboard.print('o'); 
  }
  if(wire12.risingEdge()){
   Keyboard.print('\n'); 
  }  
  digitalWrite(10, LOW);
  

  // ------------------------ Wire 2 @ PIN 11
  digitalWrite(11, HIGH); 
  
  wire6.update();
  wire8.update();
  wire9.update();
  wire15.update();
  wire14.update();
  wire13.update();
  
  if(wire8.risingEdge()){
   Keyboard.print('0'); 
  }
  if(wire9.risingEdge()){
   Keyboard.print('6'); 
  }
  if(wire15.risingEdge()){
   Keyboard.print('7'); 
  }
  if(wire14.risingEdge()){
   Keyboard.print('8'); 
  }
  if(wire13.risingEdge()){
   Keyboard.print('9'); 
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
  
  if(wire8.risingEdge()){
   Keyboard.print('a'); 
  }
  if(wire9.risingEdge()){
   Keyboard.print('g'); 
  }
  if(wire15.risingEdge()){
   Keyboard.print('f'); 
  }
  if(wire14.risingEdge()){
   Keyboard.print('d'); 
  }
  if(wire13.risingEdge()){
   Keyboard.print('s'); 
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


//------------------------  MODIFIER KEYS: fctn, ctrl, shft, lock
void checkModifiers(){ 
  
    // Wire 3 @ PIN 12: shft
  digitalWrite(12, HIGH);
  wire12.update();
  if(wire12.risingEdge()){
   shft = true; 
  }
  digitalWrite(12, LOW);
  
  // Wire 7 @ PIN 16: fctn & lock
  digitalWrite(16, HIGH); 
  wire12.update();
  wire6.update(); 
  if(wire12.risingEdge()){
   fctn = true; 
  }  
  if(wire6.risingEdge()){
   lock = true; 
  }
  digitalWrite(16, LOW);
 
   
  // Wire 10 @ PIN 44: ctrl
  digitalWrite(44, HIGH);
  wire12.update();
  if(wire12.risingEdge()){
   ctrl = true; 
  }
  digitalWrite(44, LOW);
}


