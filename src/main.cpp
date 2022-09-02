#include <Arduino.h>

#include <Variables.h>
#include <setup.h>
#include <PrintMsg.h>


void IniciacionCarga(void);
float LeerTension();
void IndicadorNivel(float tension);


void loop() {


  IniciacionCarga();
  delay(500);
  

  while(1){

    tension = LeerTension();
    
    if (mode == "ON"){
      digitalWrite(output_rele, HIGH); 
      PrintValue(tension, mode);
      IndicadorNivel(tension);
      delay(500);
    }
    if (mode == "OFF"){
      digitalWrite(output_rele, LOW); 
      PrintValue(tension, mode);
      IndicadorNivel(tension);
      delay(500);
    }

    
    
  
  }//end while(1)



}


void IniciacionCarga(void){

  tension = LeerTension();
  
    if(tension<=7.5){
        mode = "OFF";
        PrintError();
      }
    if(tension>7.5 && tension<=8.5){
      mode = "ON";
      PrintNivel(0);//nivel de bateria bajo
    }
    if(tension>8.5 && tension<=11.0){
      mode = "ON";
      PrintNivel(1);//nivel de bateria medio
    }
    if(tension>11){
      mode = "ON";
      PrintNivel(2);//nivel de bateria optimo
    }


}


float LeerTension(){

  float value;
  float medida=0.0;
  int iteraciones=75;
  float resolucion = 1023.0;
  float constante = 20;        //esta constante esta asociada con el divisor resistivo (13.2k/R = 5)
  float tension_diodo = 0.65;

  for (int i = 0; i < iteraciones; i++)
  {
    value = analogRead(adc_bat);

    medida = value + medida;
    delay(10);

  }
  
  medida =  (medida / iteraciones) * (1/resolucion) * constante;


  return medida;

}

void IndicadorNivel(float tension){

  
    if(tension<=7.5){
        mode = "OFF";
        lcd.setCursor(0,3);
        lcd.print("Error: Nivel VB bajo");
      }
    if(tension>7.5 && tension<=8.5){
      mode = "ON";
      lcd.setCursor(0,3);
      lcd.print(" Nivel Bateria bajo");
    }
    if(tension>8.5 && tension<=11.0){
      mode = "ON";
      lcd.print("Nivel Bateria  medio");
    }
    if(tension>11){
      mode = "ON";
      lcd.setCursor(0,3);
      lcd.print(" Nivel Bateria alto");
    }

}