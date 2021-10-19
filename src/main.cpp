#include <Arduino.h>

#include <Variables.h>
#include <setup.h>



void loop() {

  while(1){

    digitalWrite(output_rele, HIGH);  
    digitalWrite(output_led, HIGH); 
    delay(1000);
    digitalWrite(output_rele, LOW);  
    digitalWrite(output_led, LOW); 

  
  }//end while(1)



}

