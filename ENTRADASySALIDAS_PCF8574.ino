//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//Ejemplo: Expansor de entradas y salidas I2c con PCF8574 - prof.martintorres@educ.ar - ETI Patagonia
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
#include "Arduino.h"
#include "PCF8574.h"


int botonSeleccion = 13;
int mode = 0;       

PCF8574 pcf8574(0x20);// dirección de la configuración del dispositivo
//unsigned long timeElapsed;
uint8_t PIN_P0;
uint8_t PIN_P1;     
uint8_t PIN_P2;
uint8_t PIN_P3;
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void setup()
  {
  DDRD = B11111100; // Implementamos 8 bits del puerto D
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(botonSeleccion, INPUT);
  mode = 0;
  
  pcf8574.begin();// inicializamos la comunicación entre el uc y el CI PCF8574

  pcf8574.pinMode(P0, INPUT); //se declará el pin PO del CI PCF8574 como entrada
  pcf8574.pinMode(P1, INPUT); //se declará el pin P1 del CI PCF8574 como entrada
  pcf8574.pinMode(P2, INPUT); //se declará el pin P2 del CI PCF8574 como entrada
  pcf8574.pinMode(P3, INPUT); //se declará el pin P2 del CI PCF8574 como entrada

  pcf8574.pinMode(P4, OUTPUT);//se declará el pin P5 del CI PCF8574 como salida
  pcf8574.pinMode(P5, OUTPUT);//se declará el pin P5 del CI PCF8574 como salida
  pcf8574.pinMode(P6, OUTPUT);//se declará el pin P6 del CI PCF8574 como salida 
  pcf8574.pinMode(P7, OUTPUT);//se declará el pin P7 del CI PCF8574 como salida

  //Serial.begin(115200); // inicializamos la comunicación RS232
  Serial.begin(57600); // inicializamos la comunicación RS232
  }
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void loop()
  {
 
    
  debug_1(); 
  PIN_P0 = pcf8574.digitalRead(P0);            // Lee el valor del pin P0
  PIN_P1 = pcf8574.digitalRead(P1);            // Lee el valor del pin P1     
  PIN_P2 = pcf8574.digitalRead(P2);            // Lee el valor del pin P2
  PIN_P3 = pcf8574.digitalRead(P3);            // Lee el valor del pin P2

//////////////////////////////////////////////////////////////////////////////////
  if (PIN_P0 == HIGH)
  {              // Si se presiona el boton P0,
    pcf8574.digitalWrite(P7, HIGH); //entonces que se ponga en alto el P7
  }
  else   
  {
    pcf8574.digitalWrite(P7, LOW);  //caso contrario q se ponga en bajo el P7
  }
  delay(10);
//////////////////////////////////////////////////////////////////////////////////
    if (PIN_P1 == HIGH)
    {           // Si se presiona el boton P1,
    pcf8574.digitalWrite(P6, HIGH);//entonces que se ponga en alto el P6
  }
  else   
  {
    pcf8574.digitalWrite(P6, LOW);//caso contrario q se ponga en bajo el P6
  }
  delay(10);
//////////////////////////////////////////////////////////////////////////////////
      if (PIN_P2 == HIGH)
      {         // Si se presiona el boton P2,
       pcf8574.digitalWrite(P5, HIGH);//entonces que se ponga en alto el P5
      }
     else
      {
       pcf8574.digitalWrite(P5, LOW);//caso contrario q se ponga en bajo el P5
       }
//////////////////////////////////////////////////////////////////////////////////
      if (PIN_P3 == HIGH)
         {         // Si se presiona el boton P3,
          pcf8574.digitalWrite(P4, HIGH);//entonces que se ponga en alto el P4
         }
       else
         {
          pcf8574.digitalWrite(P4, LOW);//caso contrario q se ponga en bajo el P4
         }
////////////////////////////////////////////////////////////////////////////////// 
if (digitalRead(botonSeleccion)== HIGH)
   {
    mode=mode+1;
    delay (400);
   }
if (mode == 0){PORTD = B00000000;}
if (mode == 1){PORTD = B00000100;}
if (mode == 2){PORTD = B00001000;}
if (mode == 3){PORTD = B00010000;}
if (mode == 4){PORTD = B00100000;}
if (mode == 5){PORTD = B01000000;}
if (mode == 6){PORTD = B10000000;}
if (mode == 7){mode=0;}
//////////////////////////////////////////////////////////////////////////////////
  delay(10);
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void debug_1()
        {
        Serial.println("---");
        Serial.print(" P0 ");Serial.print (PIN_P0);
        Serial.println("   ");
        Serial.print(" P1 ");Serial.print(PIN_P1);
        Serial.println("   ");
        Serial.print(" P2 "); Serial.print(PIN_P2);
        Serial.println("   ");
        Serial.print(" P3 ");Serial.print(PIN_P3);
        Serial.println("   ");
        Serial.print(" S1 ");Serial.print(P1);
        Serial.println("   ");
        Serial.print(" S2 "); Serial.print(P2);
        Serial.println("   ");
        Serial.print(" S3 ");Serial.print(P3);
        Serial.println("   ");
        Serial.print(" S4 ");Serial.print(P4);
        Serial.println("   ");
        }
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////