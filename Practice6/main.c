/*
 * File:   main.c
 * Author: ecaballero
 *
 * Created on 6 de octubre de 2020, 01:25 PM
 */
#include "device_config.h"
#include "practice6.h"
#include <math.h>

enum exponent{
    bbase = 2,
    limit = 8
};

void portInit(void) {
/**    
    TRISDBbits.TRISB0 = 1;
    TRISDbits.TRISB1 = 1;
    TRISDbits.TRISB2 = 1;
    TRISDbits.TRISB3 = 1;
    TRISDbits.TRISB4 = 1;
    TRISDbits.TRISB5 = 1;
    TRISDbits.TRISB6 = 1;
    TRISDbits.TRISB7 = 1;
 **/
    ANSELB = 0;
    ANSELD = 0;
    TRISD = 255; // 11111111b - 0xFF
      
}

void larsonDisplay(void){
    LATB = 1;
    for(unsigned char i = 0; i < limit; i++){
        LATB = LATB << 1;
        __delay_ms(DELAY_SWEEP);
    }
    for(unsigned char i = limit; i >=0 ; i--){
        LATB = LATB >> 1;
        __delay_ms(DELAY_SWEEP);
    }
}

void main(void) {
    portInit();
    while(1){
           //Activar de manera aleatoria un LED utilizando pow() y RAND
        LATB = 0;
        unsigned char random = rand() % limit;
        LATB |= (1 << random);
        // Me lo coloca 1 en el bit que indique random entre 0 y 7
        
        __delay_ms(500);
       
        // obtener el estado de los PushButton 
        if(PORTB == ~(LATD)){
            larsonDisplay();
        } else{
            __delay_ms(250);
            //Obtener el estatus de los PushButton
            if(PORTB == ~(LATD)){
                larsonDisplay();
            }
        }
    }
    return;
}