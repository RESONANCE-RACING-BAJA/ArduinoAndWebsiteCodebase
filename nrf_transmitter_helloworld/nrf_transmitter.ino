/*connections of the nrfl01+ with UNO
*module | UNO
VCC -> 3.3V
GND -> GND 
SCK -> D13
MISO -> D12
MOSI -> D11
CSN ->  D7
CE ->   D8  */


//adding essential libraries
#include <SPI.h>                  /* to handle the communication interface with the modem*/
#include <nRF24L01.h>             /* to handle this particular modem driver*/
#include<RF24.h>                  /*library which helps to control radio modem*/

RF24 radio(9, 8);                /*creating radio object (CE,CSN)*/
const byte address[6] = "00009"; //address to which the data is transmitted

void setup() {
  Serial.begin(9600);
  radio.begin();        //activate modem
  radio.openWritingPipe(address);    //set the address of the transmitter to which program will send data

}

void loop() {
  radio.stopListening();    //setting the modem in transmission mode
  const char message[] = "Hello this is Atul Chatane";
  radio.write(&message,sizeof(message));
  Serial.print("Transmitting : "+String(message));
  delay(1000);

}
