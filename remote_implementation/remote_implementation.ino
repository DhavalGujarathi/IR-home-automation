#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


int RECV_PIN = 11;

#define CODE1 0x80BFBB44
#define CODE2 0x80BF31CE 
#define CODE3 0x80BF08F7
#define CODE4 0x80BF8877

unsigned int PINONE = 2;
unsigned int PINTWO = 3;
unsigned int PINTHREE = 4;
unsigned int PINFOUR = 5;

boolean button1 = false;
boolean button2 = false;
boolean button3 = false;
boolean button4 = false;

IRrecv irrecv(RECV_PIN); 
decode_results results;


void setup()
{

Serial.begin(9600);
irrecv.enableIRIn(); 

pinMode(PINONE,OUTPUT);
pinMode(PINTWO,OUTPUT);
pinMode(PINTHREE,OUTPUT);
pinMode(PINFOUR,OUTPUT);

}

void loop() 
{
    if (irrecv.decode(&results))    
    {

          switch (results.value)
          {

                case CODE1:

                              if (button1? false : true)
                              {
                                 button1 = true;
                                 digitalWrite(PINONE,HIGH);
                               }
                               
                               else
                               {
                                  button1 = false;
                                  digitalWrite(PINONE,LOW);
                               }
                 break;

                 case CODE2:

                              if (button2? false : true)
                              {
                                 button2 = true;
                                 digitalWrite(PINTWO,HIGH);
                               }
                               
                               else
                               {
                                  button2 = false;
                                  digitalWrite(PINTWO,LOW);
                               }
                 break;

                 case CODE3:

                              if (button3? false : true)
                              {
                                 button3 = true;
                                 digitalWrite(PINTHREE,HIGH);
                               }
                               
                               else
                               {
                                  button3 = false;
                                  digitalWrite(PINTHREE,LOW);
                               }
                 break;

                 case CODE4:

                              if (button4? false : true)
                              {
                                 button4 = true;
                                 digitalWrite(PINFOUR,HIGH);
                               }
                               
                               else
                               {
                                  button4 = false;
                                  digitalWrite(PINFOUR,LOW);
                               }
                 break;

                

          }

      delay(100); 

irrecv.resume(); // Receive the next value

}

}

