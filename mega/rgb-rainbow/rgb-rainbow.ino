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

static int colours[1536][3];

void setup(){
    for(int i = 2; i <= 13; i++){
        pinMode(i, OUTPUT);
    }

    int j = 0;
    for(int i = 255; j <= 255; j++){
        colours[j][0] = i;
    }
    for(int i = 255; j <= 512; j++){
        colours[j][0] = i;
    }
    for(int i = 255; j <= 768; i--, j++){
        colours[j][0] = i;
    }
    for(int i = 0; j <= 1024; j++){
        colours[j][0] = i;
    }
    for(int i = 0; j <= 1280; j++){
        colours[j][0] = i;
    }
    for(int i = 0; j <= 1536; i++, j++){
        colours[j][0] = i;
    }

    j = 0;
    for(int i = 0; j <= 255; j++){
        colours[j][1] = i;
    }
    for(int i = 0; j <= 512; i++, j++){
        colours[j][1] = i;
    }
    for(int i = 255; j <= 768; j++){
        colours[j][1] = i;
    }
    for(int i = 255; j <= 1024; j++){
        colours[j][1] = i;
    }
    for(int i = 255; j <= 1280; i--, j++){
        colours[j][1] = i;
    }
    for(int i = 0; j <= 1536; j++){
        colours[j][1] = i;
    }

    j = 0;
    for(int i = 255; j <= 255; i--, j++){
        colours[j][2] = i;
    }
    for(int i = 0; j <= 512; j++){
        colours[j][2] = i;
    }
    for(int i = 0; j <= 768; j++){
        colours[j][2] = i;
    }
    for(int i = 0; j <= 1024; i++, j++){
        colours[j][2] = i;
    }
    for(int i = 255; j <= 1280; j++){
        colours[j][2] = i;
    }
    for(int i = 255; j <= 1536; j++){
        colours[j][2] = i;
    }
}

void rainbow_one_led(int delayTime){
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
    for(int i = 0; i <= 255; i++){
        analogWrite(RED_1, i);
        delay(delayTime);
    }
}

void loop(){
    rainbow_one_led(10);
}