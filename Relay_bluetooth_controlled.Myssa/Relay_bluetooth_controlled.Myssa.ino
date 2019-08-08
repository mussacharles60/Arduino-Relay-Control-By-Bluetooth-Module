/* This is simple code for controlling eight relay board with bluetooth module by using android smartphone.
 *  Written by Mussa Charles (Myssa).
 *  For more info please visit  http://www.github.com/mussacharles60 
 *  Good luck and have fun!. :)
 */
#include <SoftwareSerial.h>     // for bluetooth module by serial communitation with arduino board

SoftwareSerial bluetooth(2,3);  // create instance for bluetooth module

// define pin declaration
#define relayPin1 4 
#define relayPin2 5 
#define relayPin3 6 
#define relayPin4 7 
#define relayPin5 8 
#define relayPin6 9 
#define relayPin7 10 
#define relayPin8 11

String data = "";  //initialize variable

void setup() {
  for (int i = 4; i < 12; i++) {  // fast way to declare i/o pins
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);    // set baud rate of serial monitor for debug
  bluetooth.begin(9600); // set baud rate of the connected bluetooth module
}

void loop() {         
  while(bluetooth.available()) {  // check if the bluetooth receives something
    char c = bluetooth.read();    // add each character to obtain full String
    data += c;
    delay(10);
  }
  if (data.length() > 0) {        // check if the length of data is greater than zero
    Serial.print(F("Received data: "));
    Serial.println(data);         // Print the received data to the serial monitor
    if(data == 'A'){              
    digitalWrite(relayPin1, HIGH);// if data is equal to 'A' then turn on relay in pin 1
    }
    else if(data == 'a'){
      digitalWrite(relayPin1, LOW);// if data is equal to 'a' then turn off relay in pin 1
    }
    else if(data == 'B'){
      digitalWrite(relayPin2, HIGH);
    }
    else if(data == 'b'){
      digitalWrite(relayPin2, LOW);
    }
    else if(data == 'C'){
      digitalWrite(relayPin3, HIGH);
    }
    else if(data == 'c'){
      digitalWrite(relayPin3, LOW); 
    }
    else if(data == 'D'){
      digitalWrite(relayPin4, HIGH);
    }
    else if(data == 'd'){
      digitalWrite(relayPin4, LOW); 
    }
    else if(data == 'E'){
      digitalWrite(relayPin5, HIGH); 
    }
    else if(data == 'e'){
      digitalWrite(relayPin5, LOW);
    }
    else if(data == 'F'){
      digitalWrite(relayPin6, HIGH);
    }
    else if(data == 'f'){
      digitalWrite(relayPin6, LOW); 
    }
    else if(data == 'G'){
      digitalWrite(relayPin7, HIGH);
    }
    else if(data == 'g'){
      digitalWrite(relayPin7, LOW); 
    }
    else if(data == 'H'){
      digitalWrite(relayPin8, HIGH); 
    }
    else if(data == 'h'){
      digitalWrite(relayPin8, LOW);
    }
    else if(data == 'I'){
      digitalWrite(relayPin1, HIGH);
      digitalWrite(relayPin2, HIGH);
      digitalWrite(relayPin3, HIGH);
      digitalWrite(relayPin4, HIGH);
      digitalWrite(relayPin5, HIGH);
      digitalWrite(relayPin6, HIGH);
      digitalWrite(relayPin7, HIGH);
      digitalWrite(relayPin8, HIGH);
    }
    else if(data == 'i'){
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, LOW);
      digitalWrite(relayPin5, LOW);
      digitalWrite(relayPin6, LOW);
      digitalWrite(relayPin7, LOW);
      digitalWrite(relayPin8, LOW);
    }
    data = "";  // Everytime when you receive the data you need to clear for the next one.
  }
}


//Myssa.
