/*connections of the module with UNO
*module | UNO
VCC -> 3.3V
GND -> GND 
SCK -> D13
MISO -> D12
MOSI -> D11
CSN ->  D7
CE ->   D8  */



#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
RF24 radio(9, 8);   //radio(CE,CSN)
const byte address[6] = "00009";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,address);

}

void loop() {
  radio.startListening(); //sets in reciever mode
  if(radio.available()){

    while(radio.available()){
     const char recieved_message[32] ={0};
      radio.read(&recieved_message,sizeof(recieved_message)); //read recieved message and store in the variable
      Serial.print("Recieved data :"); //prints the data on serial monitor
      Serial.println(recieved_message);
      delay(1000);
      }

  }
      else{
        Serial.println("Not recieving !! Check your range");
        delay(1000);
        }
    }
