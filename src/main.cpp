#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void){
    DDRD=0xFF;
    int unidades=0;
    int decenas=0;
    while(1){
        PORTD=((unidades<<4)&0xF0)|(decenas&0x0F); //definir 0 al 3 para decenas y del 4 al 7 como unidades
        _delay_ms(500);
        unidades++;
        if(unidades>9){
            unidades=0;
            decenas++; //incrementa las decenas si pas del 9
            if(decenas>9){
                decenas=0; //reiniciar al pasar de 99
            }
        }
    }
}