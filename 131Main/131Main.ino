
//codestart
#include <IRremote.h> //include the library
#define Button_1 0xFF30CF
#define Button_2 0xFF18E7

int receiver = 13; //initialize pin 13 as recevier pin.
uint32_t Previous; 
IRrecv irrecv(receiver); 
decode_results results;


void setup() {
 Serial.begin(9600);
 irrecv.enableIRIn(); //sets pin 12 as output
pinMode(12, OUTPUT);
}
void loop() {
 if (irrecv.decode(&results)) { //if we have received an IR signal
  if (results.value==0xFFFFFFFF) { 
      results.value=Previous;
      }

    switch(results.value) {
           case Button_1 : digitalWrite(12, HIGH); break;
           case Button_2 : digitalWrite(12, LOW); break;
           
      } 
 Serial.println (results.value, HEX); //display HEX results 
 irrecv.resume(); //next value
 }
 Previous=results.value;
 }
//codeend
