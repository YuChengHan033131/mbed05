#include "mbed.h"

InterruptIn button(SW2);
DigitalOut led(LED1);
Timer t;

void ISR1(){
    if(t.read()>1){
        led = !led;
        t.reset();
    }
}
int main(){
    led=true;
    t.start();
    
    button.rise(&ISR1);
    while(1){}
}