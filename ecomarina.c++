#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,4,5,6,7);

const int PinSensorPh= A3; 
const int PinSensorTemp=A4; 
const int pinAlarme = 10;  

float Ph, Temperatura, VoltSensorPh=0, VoltSensorTemp=0; 
float LeituraPh, LeituraTemp; 
float Phmin = 6.0, Phmax = 6.5; 
float Tempmin = 17, Tempmax = 35;
float VPhmax= (0+5)/3;

void setup(){
  lcd.begin(16,2);
  pinMode(PinSensorPh,INPUT); 
  pinMode(PinSensorTemp,INPUT); 
  pinMode(pinAlarme, OUTPUT);

  Serial.begin(9600); 
}

void loop(){
  LeituraPh = analogRead(PinSensorPh); 
  VoltSensorPh = (LeituraPh*4.877); 
  Ph = ((VoltSensorPh)/(VPhmax/Phmax));
  Ph = (Ph/2315);

  LeituraTemp = analogRead(PinSensorTemp); 
  VoltSensorTemp = (LeituraTemp*4.877);
  Temperatura = (((VoltSensorTemp)-500)/10);
     
  Serial.print("Ph do solo atual: ");
  Serial.print(Ph);
  Serial.println(" ");
  Serial.print("Temperatura atual: ");
  Serial.print(Temperatura);
  	
  if (Ph <= 5.0 and Temperatura >=33.0){
    lcd.clear();
    lcd.write("NIVEL CRITICO!");
    lcd.setCursor (0,1);
    lcd.print("CUIDADO");
    tone(pinAlarme, 1000);
    delay(2000);  
    noTone(pinAlarme);
    delay(1000);  
  }
  else if(Ph <=5.0){
    
  lcd.clear();
  lcd.write("Temperatura:");
  lcd.print(Temperatura);
  lcd.setCursor (0,1);
  lcd.print("Ph: ");
  lcd.print(Ph);
  lcd.print(" !!!");
  lcd.write(B10110010);
  noTone(pinAlarme);
  }
  
  else if (Temperatura >=33.0){
    
  lcd.clear();
  lcd.write("Temp.:");
  lcd.print(Temperatura);
  lcd.print(" !!!");
  lcd.setCursor (0,1);
  lcd.print("Ph: ");
  lcd.print(Ph);
  lcd.write(B10110010);
  noTone(pinAlarme);
  }
    
  else{
  lcd.clear();
  lcd.write("Temperatura:");
  lcd.print(Temperatura);
  lcd.setCursor (0,1);
  lcd.print("Ph: ");
  lcd.print(Ph);
  lcd.write(B10110010);
  noTone(pinAlarme);
  }
  delay(5000);
}
    
    
    
    
    
    
    
