#include <Arduino.h>


void PrintValue(float vbat, String mode){
    
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Cargador Bateria:");
  lcd.print(mode);//ON ; OFF

  lcd.setCursor(5,2);
  lcd.print("Vbat:");
  lcd.print(vbat,2);

  delay(50);

}

void PrintError(void){

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Cargador Bateria:");
  lcd.print(mode);//ON ; OFF

  lcd.setCursor(0,1);
  lcd.print("ERROR VOLTS BATERIA");
  lcd.setCursor(5,2);
  lcd.print(tension,2);

  delay(2500);

}

void PrintNivel(int x){

  if(x==0){

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Cargador Bateria:");
    lcd.print(mode);//ON ; OFF

    lcd.setCursor(0,1);
    lcd.print("Nivel Bajo - Bateria");
    lcd.setCursor(5,2);
    lcd.print(tension,2);

    delay(2500);
  }
  if(x==1){

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Cargador Bateria:");
    lcd.print(mode);//ON ; OFF

    lcd.setCursor(0,1);
    lcd.print("Nivel Medio Bateria");
    lcd.setCursor(5,2);
    lcd.print(tension,2);

    delay(2500);
  }

  if(x==2){

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Cargador Bateria:");
    lcd.print(mode);//ON ; OFF

    lcd.setCursor(0,1);
    lcd.print("Nivel Alto - Bateria");
    lcd.setCursor(5,2);
    lcd.print(tension,2);

    delay(2500);
  }

}