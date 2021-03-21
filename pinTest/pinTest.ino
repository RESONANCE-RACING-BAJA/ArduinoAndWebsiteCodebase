/*This is the digital pin read test performed for rpm sensor
Connections : Connect the board with usb upload program 
put the power jack in other DC jack of the arduino pull the positive wire from the DC jack 
Now run the program , Initally you will get 0 on the pin 10 , when you insert the wire from jack into pin 10 you start getting 1 in serial monitor
Conclusion : Pin 10 is digital pin and is capable of detecting both HIGH '1' and LOW '0' signals which makes it fit for inductive proximity sensor pnp and npn
As the proximity sensor gives digital output in 1's and 0's. */


void setup() {
  pinMode(10,INPUT);  // sets the digital pin 10 as input

}

void loop() {
  Serial.begin(9600);
  // read the input pin:
  int buttonState = digitalRead(10);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1000);        // delay in between reads for stability
}
