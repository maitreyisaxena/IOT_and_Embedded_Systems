
  const byte ledPin=12;
  const byte buttonPin=2;
 void setup(){ 
pinMode(ledPin,OUTPUT);
pinMode(buttonPin,INPUT_PULLUP);
}
bool state=false;
void loop() {
  
if (digitalRead(buttonPin)==0){
  digitalWrite(ledPin,1);
  while(digitalRead(buttonPin)==0); 
  state^=1;                         
}
if(state==1)
{
  digitalWrite(ledPin,1);
}
else{
  digitalWrite(ledPin,0);
}
}
