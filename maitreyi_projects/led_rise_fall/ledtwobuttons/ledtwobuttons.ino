const int currstate1=0;
const int prevstate1=0;
const int currstate2=0;
const int prevstate2=0;

void setup()
{
  pinMode(2, INPUT_PULLUP);
   pinMode(3, INPUT_PULLUP);
   pinMode(8,OUTPUT);
 
}

void loop()
{
  currstate1=digitalRead(2);
  currstate2=digitalRead(3);
  if (currstate1!==prevstate1){
    if(currstate1==HIGH){
      }
    if(currstate1==LOW){
      digitalWrite(8,HIGH);
    }
    prevstate1=currstate1;
  

   
  if (currstate2!==prevstate2){
    if(currstate2==HIGH){
      digitalWrite(8,HIGH);
      }
    if(currstate2==LOW){
      
    }
  }
}         
