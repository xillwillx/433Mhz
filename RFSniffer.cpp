#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

RCSwitch mySwitch;

int main(int argc, char *argv[]) {

     int PIN = 2;

     if(wiringPiSetup() == -1)
       return 0;

     mySwitch = RCSwitch();
     mySwitch.enableReceive(PIN);  // Receiver on interrupt 0 => that is pin #2

     bool CODE_RECEIVED = false;
     while(!CODE_RECEIVED) {
      if (mySwitch.available()) {

        int value = mySwitch.getReceivedValue();

        if (value != 0) {
             printf("%i,%i", value, mySwitch.getReceivedDelay());
             CODE_RECEIVED = true;
        }
        mySwitch.resetAvailable();
      }
  }
  exit(0);
}
