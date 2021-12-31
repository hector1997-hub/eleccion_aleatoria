
#include <Arduino.h>
#include <Wire.h>
#include <DS3231.h>
bool century = false;
bool h12Flag;
bool pmFlag;
RTClib myRTC;


DS3231 clock;

int aleatorio;
const int timeThreshold = 4000;//variable retardo antirebote
const int intPin = 2;// pin de interrupcion
int counter = 0;
long startTime = 0;
const int verde=6;
const int rojo=7;
int dia;
int semana,finsemana;


//funcion de interrupcion
void debounceCount()
{
  int cont;
  cont=0;
  
  while(cont<timeThreshold){
    cont++;
    delay(1);
  }
  cont=0;
 // delay(timeThreshold);

  digitalWrite(rojo,LOW);
  digitalWrite(verde,LOW);

  //
  aleatorio=random(10);
  Serial.println(aleatorio);
 

 if (dia>=6){
   if(aleatorio>=finsemana){
     digitalWrite(rojo,HIGH);
     digitalWrite(verde,LOW);
     Serial.println("rojo");
  
    }
    else
    {
     digitalWrite(rojo,LOW);
     digitalWrite(verde,HIGH);
     Serial.println("verde");
   
    }
 }
 else{
    if(aleatorio>=semana){
     digitalWrite(rojo,HIGH);
     digitalWrite(verde,LOW);
    Serial.println("rojo");
    
    }
    else
    {
     digitalWrite(rojo,LOW);
     digitalWrite(verde,HIGH);
    Serial.println("verde");
      
    }
    
   
 }
   while(cont<10000){
    cont++;
    delay(1);
  }
  cont=0;
  digitalWrite(rojo,LOW);
  digitalWrite(verde,LOW);
  Serial.println("fin interrupcion");
}


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(intPin, INPUT_PULLUP);
  Serial.begin(9600);
  semana=7;
  finsemana=8;//proporcion de tomas entre semana

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(rojo, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(intPin), debounceCount, FALLING);
	// Start the I2C interface
	Wire.begin();
  digitalWrite(rojo,LOW);
  digitalWrite(verde,LOW);
}

// the loop function runs over and over again forever
void loop() {
   //dia=(clock.getDoW(), DEC);
  //Serial.println(dia);
    
    // 
  dia=clock.getDoW();
//Serial.println(dia);    
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);               // wait for a second

  }


