// Adapted from NUS CG1112 Week 6 Studio 2
// Code written by me with instructions from teaching staff

#include <avr/interrupt.h>
#include <avr/io.h>
#include <Arduino.h>

#define PIN12MASK 0b00010000
#define PIN11MASK 0b00001000

static volatile int flashWhich = 1;
static volatile unsigned char buttonVal = 1;

volatile char dataSend, dataRecv;

void setupEINT(){
    EICRA = 0b00001111;
    EIMSK = 0b00000011;
}

void setupSerial(){
    UCSR0C = 0b00100100;
    UBRR0 = 103;
    UCSR0A = 0;
    UCSR0B = 0b10011000;
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
    dataSend = '0';
    UCSR0B |= 0b00100000;
}

ISR(INT1_vect){
    dataSend = '9';
    UCSR0B |= 0b00100000;
}

ISR(USART_RX_vect){
    dataRecv = UDR0;
    if(dataRecv == 0 + '0'){
        flashWhich = 0;
    }else if(dataRecv == 9 + '0'){
        flashWhich = 1;
    }
}

ISR(USART_UDRE_vect){
    UDR0 = dataSend;
    UCSR0B &= 0b11011111;
}

void setup(){
    cli();
    setupEINT();
    setupSerial();
    DDRB = 0b00011000;
    sei();
}

void loop(){
    if(flashWhich == 0){
        flashRed();
        flashWhich = 2;
    }else if(flashWhich == 1){
        flashGreen();
        flashWhich = 2;
    }
}