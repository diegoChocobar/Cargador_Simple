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

 //////////////////////CONFIGURACION DE ADS1115 ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  //ads.setGain(GAIN_ONE);constanteADS=0.125;escala =1;        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  //ads.setGain(GAIN_TWO);constanteADS=0.0625;escala =2;        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  //ads.setGain(GAIN_FOUR);constanteADS=0.03125;escala =4;       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  //ads.setGain(GAIN_EIGHT);constanteADS=0.015625;escala =8;      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  //ads.setGain(GAIN_SIXTEEN);constanteADS=0.0078125;escala =16;    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

  //ads.setDataRate(RATE_ADS1115_8SPS);
  ads.setDataRate(RATE_ADS1115_64SPS);//8;16;32;64;128;250;475;860
  ads.begin();
///////////////////////////////////////////////////////////////////////////////////////////////////////////

    SaludoInicial();

}


void SaludoInicial(){

    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("***CDC Elctronics***");
    lcd.print("*Cargador Bat- v1.2*");
    lcd.print("INICIO DE MEDICIONES");
    lcd.print("********************");

    delay(2000);


}