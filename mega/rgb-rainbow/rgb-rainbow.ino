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

static byte colours[1536][3];

void setup() {
    for (int i = 2; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }

    int j = 0;
    for (int i = 255; j <= 255; j++) {
        colours[j][0] = i;
    }
    for (int i = 255; j <= 511; j++) {
        colours[j][0] = i;
    }
    for (int i = 255; j <= 767; i--, j++) {
        colours[j][0] = i;
    }
    for (int i = 0; j <= 1023; j++) {
        colours[j][0] = i;
    }
    for (int i = 0; j <= 1279; j++) {
        colours[j][0] = i;
    }
    for (int i = 0; j <= 1535; i++, j++) {
        colours[j][0] = i;
    }

    j = 0;
    for (int i = 0; j <= 255; j++) {
        colours[j][1] = i;
    }
    for (int i = 0; j <= 511; i++, j++) {
        colours[j][1] = i;
    }
    for (int i = 255; j <= 767; j++) {
        colours[j][1] = i;
    }
    for (int i = 255; j <= 1023; j++) {
        colours[j][1] = i;
    }
    for (int i = 255; j <= 1279; i--, j++) {
        colours[j][1] = i;
    }
    for (int i = 0; j <= 1535; j++) {
        colours[j][1] = i;
    }

    j = 0;
    for (int i = 255; j <= 255; i--, j++) {
        colours[j][2] = i;
    }
    for (int i = 0; j <= 511; j++) {
        colours[j][2] = i;
    }
    for (int i = 0; j <= 767; j++) {
        colours[j][2] = i;
    }
    for (int i = 0; j <= 1023; i++, j++) {
        colours[j][2] = i;
    }
    for (int i = 255; j <= 1279; j++) {
        colours[j][2] = i;
    }
    for (int i = 255; j <= 1535; j++) {
        colours[j][2] = i;
    }
}

void rainbow_one_led(int delayTime) {
    for (int i = 255; i >= 0; i--) {
        analogWrite(BLUE_1, i);
        delay(delayTime);
    }
    for (int i = 0; i <= 255; i++) {
        analogWrite(GREEN_1, i);
        delay(delayTime);
    }
    for (int i = 255; i >= 0; i--) {
        analogWrite(RED_1, i);
        delay(delayTime);
    }
    for (int i = 0; i <= 255; i++) {
        analogWrite(BLUE_1, i);
        delay(delayTime);
    }
    for (int i = 255; i >= 0; i--) {
        analogWrite(GREEN_1, i);
        delay(delayTime);
    }
    for (int i = 0; i <= 255; i++) {
        analogWrite(RED_1, i);
        delay(delayTime);
    }
}

void loop() {
    short int ledColour[4];
    short int step = 10;
    for (int i = 0; i < 1536; i++) {
        ledColour[0] = i;
        ledColour[1] = (i + step) < 1536 ? i + 384 : i + 384 - 1536;
        ledColour[2] = (i + 2 * step) < 1536 ? i + 768 : i + 768 - 1536;
        ledColour[3] = (i + 3 * step) < 1536 ? i + 1152 : i + 1152 - 1536;
        analogWrite(RED_1, colours[ledColour[0]][0]);
        analogWrite(GREEN_1, colours[ledColour[0]][1]);
        analogWrite(BLUE_1, colours[ledColour[0]][2]);
        analogWrite(RED_2, colours[ledColour[1]][0]);
        analogWrite(GREEN_2, colours[ledColour[1]][1]);
        analogWrite(BLUE_2, colours[ledColour[1]][2]);
        analogWrite(RED_3, colours[ledColour[2]][0]);
        analogWrite(GREEN_3, colours[ledColour[2]][1]);
        analogWrite(BLUE_3, colours[ledColour[2]][2]);
        analogWrite(RED_4, colours[ledColour[3]][0]);
        analogWrite(GREEN_4, colours[ledColour[3]][1]);
        analogWrite(BLUE_4, colours[ledColour[3]][2]);
        delay(1);
    }
}