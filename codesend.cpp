#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int PIN = 0;
    int Code = atoi(argv[1]);  //Code is what you received from RFSniffer
	int Pulse = atoi(argv[2]); //Pulse is what you received from RFSniffer

    if (wiringPiSetup () == -1) return 1;
	printf("sending code:[%d] with pulse:[%d] \n", Code, Pulse);
	RCSwitch mySwitch = RCSwitch();
	mySwitch.setPulseLength(Pulse); 
	mySwitch.enableTransmit(PIN);
    	mySwitch.send(Code, 24); // length is always 24
	return 0;

     }
