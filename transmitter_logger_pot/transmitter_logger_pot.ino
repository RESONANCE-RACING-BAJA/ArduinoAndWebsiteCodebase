  #include<SPI.h>
  #include<SD.h>
  #include <nRF24L01.h>             /* to handle this particular modem driver*/
  #include<RF24.h>                  /*library which helps to control radio modem*/

  RF24 radio(9, 8);                /*creating radio object (CE,CSN)*/
  const byte address[6] = "00009"; //address to which the data is transmitted


  const int chipselect = 10;
  unsigned long previoustime = 0;
  byte seconds;
  byte minutes;
  byte hours ;
  
  float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;}
   
  void setup(){   
  //serial port connection check
  Serial.begin(9600);
  radio.begin();        //activate modem
  radio.openWritingPipe(address);    //set the address of the transmitter to which program will send data

  //nrf transmitter code initalizations
  radio.stopListening();    //setting the modem in transmission mode




  //wait till you connect to serial port
  while(!Serial){;}
  pinMode(chipselect,OUTPUT);
  //when connected output
  Serial.print("Serial port connnected...!\n");
  delay(1000);
  //check for sd card 
 if(!SD.begin(chipselect)){
    Serial.println("Failed to connnect to SD card !");
    //don't do anything else
    //to keep on trying until it connects
    while(1);
    delay(100);
    }
  Serial.print("SD card connected...\n");
  delay(1000);
    }
  
  void loop(){
  //counting time
  if(millis()>=previoustime){
    previoustime = previoustime + 1000;
    seconds = seconds + 1;
    //after 60 seconds
    if(seconds==60){
      seconds = 0;
      minutes = minutes + 1;
      }
     //after 60 minutes
     if(minutes==60){
      minutes = 0;
      hours = hours + 1;
      }
      delay(1000); //this will ensure one loop per second
    } 
  //time in string
  String Time = "Time :"+String(hours)+":"+String(minutes)+":"+String(seconds);  
  int analogValue = analogRead(A0);
  float deg = floatMap(analogValue, 0, 1023, 0, 270);
 Serial.println("Angel : "+String(deg)+"  Time : "+String(hours)+":"+String(minutes)+":"+String(seconds));    
 File myfile = SD.open("6feb.txt",FILE_WRITE);
    //writing to sd card
    if(myfile){
    //write in the file using file object
    myfile.println("Angel : "+String(deg)+"  Time : "+String(hours)+":"+String(minutes)+":"+String(seconds));
    myfile.close();
    }
    //if file cannot open throw an error
    else{
      Serial.println("error opening data.txt");
      }
    //transmitting after closing file
    radio.write(&deg,sizeof(deg));
    }
