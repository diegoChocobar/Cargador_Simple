#include <Arduino.h>



void SaludoInicial(void);

void setup() {

   pinMode(output_led, OUTPUT);
   pinMode(output_rele, OUTPUT);

  ////////////////////////////////////CONFIGURACION DEL LCD ////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lcd.init();      //Inicializa o LCD
    lcd.display();         //Enciende el muestreo de las Letras
    lcd.setBacklight(1); //Enciende la luz de fondo (0:off;1:on)
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


    SaludoInicial();

}


void SaludoInicial(){

    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("***CDC Elctronics***");
    lcd.print("*Cargador Bat- v1.1*");
    lcd.print("INICIO DE MEDICIONES");
    lcd.print("********************");

    delay(2000);


}