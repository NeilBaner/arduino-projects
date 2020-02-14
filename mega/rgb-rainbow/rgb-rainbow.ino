#define RED_1 2
#define RED_2 3
#define RED_3 4
#define RED_4 5
#define GREEN_1 6
#define GREEN_2 7
#define GREEN_3 8
#define GREEN_4 9
#define BLUE_1 10
#define BLUE_2 11
#define BLUE_3 12
#define BLUE_4 13

void setup(){
    for(int i = 2; i <= 13; i++){
        pinMode(i, OUTPUT);
    }
}

void rainbow_one_led(int delayTime){
    for(int i = 0; i <= 255; i++){
        analogWrite(RED_1, i);
        delay(delayTime);
    }
    for(int i = 255; i >= 0; i--){
        analogWrite(BLUE_1, i);
        delay(delayTime);
    }
    for(int i = 0; i <= 255; i++){
        analogWrite(GREEN_1, i);
        delay(delayTime);
    }
    for(int i = 255; i >= 0; i--){
        analogWrite(RED_1, i);
        delay(delayTime);
    }
    for(int i = 0; i <= 255; i++){
        analogWrite(BLUE_1, i);
        delay(delayTime);
    }
    for(int i = 255; i >= 0; i--){
        analogWrite(GREEN_1, i);
        delay(delayTime);
    }
}

void loop(){
    rainbow_one_led(10);
}