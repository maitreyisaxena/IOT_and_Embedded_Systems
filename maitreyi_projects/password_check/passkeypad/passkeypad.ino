#include <Keypad.h>
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

Keypad keypad = Keypad( makeKeymap(keys),rows,cols, 4,3 );

String password="1122";
String temp="";
int wrong=0;

void loop() {
  
 char k=keypad.getKey();
 if (k){
  if (wrong<3){
    if(k>=48 && k<=57){
      Serial.println(k);
      temp+=k;
     }
     else if(k=='*'){
      temp.remove(4,1);
     }
     
    else if(k=='#'){
    if (temp==password){
      temp="";
      Serial.println("correct");
    }
    else{
      wrong++;
      Serial.println("wrong");
      if(wrong==3){
        Serial.println("locked");
      }
    }
    }
  }
 }
}
