
#include <Servo.h>  // add servo library

#define sw1_pin 3
#define sw2_pin 4
#define sw3_pin 2
#define sw4_pin 5
#define sw5_pin 6
#define sw6_pin 7
#define sw7_pin 8
#define sw8_pin 12
#define sw9_pin 13

Servo myservo1;  // create servo object to control a servo
Servo myservo2; 
Servo myservo3; 

volatile boolean sw1 = false;
volatile boolean sw2 = false;
volatile boolean sw3 = false;
volatile boolean sw4 = false;
volatile boolean sw5 = false;
volatile boolean sw6 = false;
volatile boolean sw7 = false;
volatile boolean sw8 = false;
volatile boolean sw9 = false;


uint8_t sw1ButtonState = 0;
uint8_t sw2ButtonState = 0;
uint8_t sw3ButtonState = 0;
uint8_t sw4ButtonState = 0;
uint8_t sw5ButtonState = 0;
uint8_t sw6ButtonState = 0;
uint8_t sw7ButtonState = 0;
uint8_t sw8ButtonState = 0;
uint8_t sw9ButtonState = 0;

uint8_t lastsw1ButtonState = 0;
uint8_t lastsw2ButtonState = 0;
uint8_t lastsw3ButtonState = 0;
uint8_t lastsw4ButtonState = 0;
uint8_t lastsw5ButtonState = 0;
uint8_t lastsw6ButtonState = 0;
uint8_t lastsw7ButtonState = 0;
uint8_t lastsw8ButtonState = 0;
uint8_t lastsw9ButtonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sw1_pin, INPUT_PULLUP);
  pinMode(sw2_pin, INPUT_PULLUP);
  pinMode(sw3_pin, INPUT_PULLUP);
  pinMode(sw4_pin, INPUT_PULLUP);
  pinMode(sw5_pin, INPUT_PULLUP);
  pinMode(sw6_pin, INPUT_PULLUP);
  pinMode(sw7_pin, INPUT_PULLUP);
  pinMode(sw8_pin, INPUT_PULLUP);
  pinMode(sw9_pin, INPUT_PULLUP);
  
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  myservo3.attach(11);
}

void loop() {
 
     checkIfSw1ButtonIsPressed();
     checkIfSw2ButtonIsPressed();
     checkIfSw3ButtonIsPressed();
     checkIfSw4ButtonIsPressed();
     checkIfSw5ButtonIsPressed();
     checkIfSw6ButtonIsPressed();
     checkIfSw7ButtonIsPressed();
     checkIfSw8ButtonIsPressed();
     checkIfSw9ButtonIsPressed();

     if( sw1){
       Serial.println("sw1");
       sw1 = false;
       myservo1.write(10);
       delay(15);
     }

     if( sw2){
      Serial.println("sw2");
       sw2 = false;
       myservo1.write(40);
       delay(15);
     }
     if( sw3){
      Serial.println("sw3");
       sw3 = false;
       myservo1.write(-80);
       delay(15);
     }

     if( sw4){
       Serial.println("sw4");
       sw4 = false;
       myservo2.write(40);
       delay(15);
     }

     if( sw5){
      Serial.println("sw5");
       sw5 = false;
       myservo2.write(10);
       delay(15);
     }
     if( sw6){
      Serial.println("sw6");
       sw6 = false;
       myservo2.write(-10);
       delay(15);
     }
     
     if( sw7){
       Serial.println("sw7");
       sw7 = false;
       myservo3.write(40);
       delay(15);
     }

     if( sw8){
      Serial.println("sw8");
       sw8 = false;
       myservo3.write(20);
       delay(15);
     }
     if( sw9){
      Serial.println("sw9");
       sw9 = false;
       myservo3.write(-40);
       delay(15);
     }
     
    
                            // waits for the servo to get there
}

void checkIfSw1ButtonIsPressed()
{
    sw1ButtonState   = digitalRead(sw1_pin);
  
    if (sw1ButtonState != lastsw1ButtonState)
  {
    if ( sw1ButtonState == 0)
    {
      sw1=true;
    }
    delay(50);
  }
   lastsw1ButtonState = sw1ButtonState;
 }

void checkIfSw2ButtonIsPressed()
{
    sw2ButtonState   = digitalRead(sw2_pin);
  
    if (sw2ButtonState != lastsw2ButtonState)
  {
    if ( sw2ButtonState == 0)
    {
      sw2=true;
    }
    delay(50);
  }
   lastsw2ButtonState = sw2ButtonState;
 }

 void checkIfSw3ButtonIsPressed()
{
    sw3ButtonState   = digitalRead(sw3_pin);
  
    if (sw3ButtonState != lastsw3ButtonState)
  {
    if ( sw3ButtonState == 0)
    {
      sw3=true;
    }
    delay(50);
  }
   lastsw3ButtonState = sw3ButtonState;
 }

 void checkIfSw4ButtonIsPressed()
{
    sw4ButtonState   = digitalRead(sw4_pin);
  
    if (sw4ButtonState != lastsw4ButtonState)
  {
    if ( sw4ButtonState == 0)
    {
      sw4=true;
    }
    delay(50);
  }
   lastsw4ButtonState = sw4ButtonState;
 }

 void checkIfSw5ButtonIsPressed()
{
    sw5ButtonState   = digitalRead(sw5_pin);
  
    if (sw5ButtonState != lastsw5ButtonState)
  {
    if ( sw5ButtonState == 0)
    {
      sw5=true;
    }
    delay(50);
  }
   lastsw5ButtonState = sw5ButtonState;
 }

 void checkIfSw6ButtonIsPressed()
{
    sw6ButtonState   = digitalRead(sw6_pin);
  
    if (sw6ButtonState != lastsw6ButtonState)
  {
    if ( sw6ButtonState == 0)
    {
      sw6=true;
    }
    delay(50);
  }
   lastsw6ButtonState = sw6ButtonState;
 }

 void checkIfSw7ButtonIsPressed()
{
    sw7ButtonState   = digitalRead(sw7_pin);
  
    if (sw7ButtonState != lastsw7ButtonState)
  {
    if ( sw7ButtonState == 0)
    {
      sw7=true;
    }
    delay(50);
  }
   lastsw7ButtonState = sw7ButtonState;
 }

 void checkIfSw8ButtonIsPressed()
{
    sw8ButtonState   = digitalRead(sw8_pin);
  
    if (sw8ButtonState != lastsw8ButtonState)
  {
    if ( sw8ButtonState == 0)
    {
      sw8=true;
    }
    delay(50);
  }
   lastsw8ButtonState = sw8ButtonState;
 }

 void checkIfSw9ButtonIsPressed()
{
    sw9ButtonState   = digitalRead(sw9_pin);
  
    if (sw9ButtonState != lastsw1ButtonState)
  {
    if ( sw9ButtonState == 0)
    {
      sw9=true;
    }
    delay(50);
  }
   lastsw9ButtonState = sw9ButtonState;
 }
