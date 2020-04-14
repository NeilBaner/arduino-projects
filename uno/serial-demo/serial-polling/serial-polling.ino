// Adapted from NUS CG1112 Week 6 Studio 2
// Code written by me with instructions from teaching staff

#include <avr/interrupt.h>
#include <avr/io.h>
#include <Arduino.h>

#define PIN12MASK 0b00010000
#define PIN11MASK 0b00001000

static volatile int flashWhich = 1;
static volatile unsigned char buttonVal = 1;

void setupEINT(){
    EICRA = 0b00001111;
    EIMSK = 0b00000011;
}

void setupSerial(){
    UCSR0C = 0b00000110;
    UBRR0 = 103;
    UCSR0A = 0;
    UCSR0B = 0b00011000;
}

void sendData(unsigned char data){
    while(UCSR0A & 0b00100000 == 0);
    UDR0 = (unsigned char)data;
}

char receiveData(){
    while((UCSR0A & 0b10000000) == 0);
    unsigned char data = UDR0;
    return data;
}

void flashRed(){
    PORTB = PIN11MASK;
    delay(500);
    PORTB = !PIN11MASK;
    delay(500);
}

void flashGreen(){
    PORTB = PIN12MASK;
    delay(500);
    PORTB = !PIN12MASK;
    delay(500);
}

ISR(INT0_vect){
    sendData(0 + '0');
}

ISR(INT1_vect){
    sendData(1 + '0');
}


void setup(){
    cli();
    setupEINT();
    setupSerial();
    DDRB = 0b00011000;
    sei();
}

void loop(){
    flashWhich = receiveData() - '0';
    if(flashWhich == 1){
        flashRed();
    }else{
        flashGreen();
    }
}