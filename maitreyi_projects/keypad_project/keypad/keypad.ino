const byte cols[3]={13,12,11};
const byte rows[4]={10,9,8,7};
void setup() {
  Serial.begin(9600);
  for (int i=0; i<4; i++){
    pinMode(rows[i],INPUT_PULLUP);
    if (i<3){
      pinMode(cols[i],OUTPUT);
    }
  }
  

}
char keys[4][3]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
char getkey(){
  for (int c=0; c<3; c++){
    for (int i=0; i<3; i++){
      if (i==c){
        digitalWrite(cols[i],LOW);
      }
      else{
        digitalWrite(cols[i],HIGH);
      }
    }
    for (int r=0; r<4; r++){
      if (!digitalRead(rows[r])){
        while(!digitalRead(rows[r]));
        return keys[r][c];
      }
    }
  }
  return'\0';
}

void loop() {
  // put your main code here, to run repeatedly:
char k= getkey();
if (k!='\0'){
Serial.println(k);
}
}
