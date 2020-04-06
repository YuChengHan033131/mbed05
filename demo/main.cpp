#include "mbed.h"
InterruptIn s2(SW2);
InterruptIn s3(SW3);
Serial pc( USBTX, USBRX );
DigitalOut B(LED_BLUE);
DigitalOut R(LED_RED);
void BLed(){
    B=!B;
}
void RLed(){
    R=!R;
}
EventQueue lowE,highE;
Thread lowT (osPriorityLow);
Thread highT(osPriorityHigh);
Timer t;
int main(){
    t.start();
    B=1;
    R=1;
    lowT.start(callback(&lowE,&EventQueue::dispatch_forever));
    highT.start(callback(&highE,&EventQueue::dispatch_forever));
    lowE.call_every(500,&BLed);
    s2.fall(highE.event(RLed));



}