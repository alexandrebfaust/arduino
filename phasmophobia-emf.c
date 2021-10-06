// Phasmophobia - EMF Tool
// @alexandrebfaust

#include "OneButton.h" 
OneButton button(A1, true);//attach a button on pin A1 to the library

int rand = 0; 
int emfval = 0; 
const int led1 = 1;
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
const int led5 = 5;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
  
    button.attachDoubleClick(doubleclick);
    button.attachClick(singleclick);
    button.attachLongPressStop(longclick);
} 

void loop() {
    button.tick();
    delay(10);
}

void emf(led){
    switch (led){
    case 0:
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        digitalWrite(led5,LOW);
        break;

    case 1:
        digitalWrite(led1,HIGH);
        break;
    
    case 2:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        break;

    case 3:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        break;
    
    case 4:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
        break;
    
    case 5:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
        digitalWrite(led5,HIGH);
        break;
    
    default:
        break;
    }
}

void doubleclick(){  
    digitalWrite(LED_BUILTIN,HIGH);    
    delay(1000);    
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);    
    digitalWrite(LED_BUILTIN,HIGH);    
    delay(1000);    
    digitalWrite(LED_BUILTIN,LOW);
} 

void singleclick(){   
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);    
    digitalWrite(LED_BUILTIN,LOW);
}

// 1 - 15 = 1
// 16 - 30 = 2
// 31 - 40 = 3
// 41 - 46 = 4
// 47 - 50 = 5

void longclick(){
    rand = random(0,50);
    if(rand == 0){emfval=0}
    if(rand >= 1){emfval=1}
    if(rand >= 16){emfval=2}
    if(rand >= 40){emfval=3}
    if(rand >= 46){emfval=4}
    if(rand >= 50){emfval=5}
    emf(emfval);
}
