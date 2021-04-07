//INDUCTIVE PROXIMITY SENSOR SENSES ONLY METALLIC OBJECTS POINT TO BE NOTED
long millisecond;
byte second, minute ;
int rps = 0,sensorState;

void setup() {
  
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  Serial.begin(9600);
  
}

void loop() {

if(millis()>=millisecond){
millisecond += 100;

//counting rotation per second
sensorState= digitalRead(10);

if(!sensorState){
  rps += 1;
}

if(millisecond == 1000){
  millisecond = 0;
  second += 1;
  Serial.println("Rotation per Second : "+String(rps));
  rps = 0;
}

if(second == 60){
  second = 0;
  minute += 1;
}

if(minute == 60){ //code cannot calculate above one hour
  minute = 0;
}

delay(100);  //cycle of hundred millisecond each

}

}
