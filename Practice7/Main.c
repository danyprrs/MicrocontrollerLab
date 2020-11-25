//LIBRARIEs
#include "device_config.h"
//DIRECTIVEs SECTION
#define _XTAL_FREQ 1000000
#define DELAY_SWEEP 300 
//DATA TYPEs SECTION
enum port_dir{output, input};
enum port_DCAC{digital, analog};
enum led_state{led_OFF, led_ON};
enum button_state{pushed, no_pushed}; // Esta es la que se utiliza para el programa
enum exponent{bbase=2, limit=8};
//ISRs SECTION
__interrupt(high_priority) void high_isr (void){
    Nop(); //Consume one Instruction Cycle 
}
__interrupt(low_priority) void low_isr (void){
    Nop();//Consume one Instruction Cycle
}
//FUNCTIONs DECLARATION
void portsInit(void);//
int count = 0;
//MAIN
void main(void) {
    portsInit();
    LATB = 0;
    int a = 0x00;
    int b = 0x00;
    int c = 0x00;
    while(1){
        LATB = 0xE0; //1110            
        if(PORTBbits.RB7 == pushed) {
         b = a<<4;
         a = 0x0D;
         c = b|a;
         LATD = c;
        }
         else if (PORTBbits.RB6 == pushed){
         b = a<<4;
         a = 0x0C;
         c = b|a;
         LATD = c;   
         }
         else if (PORTBbits.RB5 == pushed){
         b = a<<4;
         a = 0x0B;
         c = b|a;
         LATD = c;   
         }
         else if (PORTBbits.RB4 == pushed){
         b = a<<4;
         a = 0x0A;
         c = b|a;
         LATD = c;   
         }             
    }
}
//FUNCTIONs
void portsInit( void ){
ANSELD = digital;
TRISD = output;
ANSELB = digital;
TRISB = 0b00001111; //Primeros cuatro bits como inputs
LATD = 0x00;
}