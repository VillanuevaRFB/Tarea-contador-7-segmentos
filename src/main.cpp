#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD|=0xF0;//Pines del 4 al 7
    int unidades=0;

    while (1) {
        PORTD=(PORTD&0x0F)|((unidades<<4)&0xF0);//mantiene el uso de D4 a D7
        _delay_ms(1000);
        unidades++;
        if (unidades>9){
            unidades=0;//incrementa y reinicia al pasar 9
        }
    }
}