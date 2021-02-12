#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
RF24 radio(9, 8);   //radio(CE,CSN)
const byte address[6] = "00009";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);
}

void loop() {
  radio.startListening(); //sets in reciever mode
  if(radio.available()){

    while(radio.available()){
      float deg;
      radio.read(&deg,sizeof(deg)); //read recieved message and store in the variable
      Serial.println("Angle :"+String(deg));
      delay(1000);
      }

  }
      else{
        Serial.println("Not recieving !! Check your range");
        delay(1000);
        }
    }
