
#include <wiringPi.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>

void move_now(void){

 fprintf(stderr,"acionar agora\n");

}

int main(){

 wiringPiSetup();

 pinMode(0,INPUT);
 wiringPiISR(0,INT_EDGE_RISING, move_now);

 pthread_exit(NULL);
 return 0;

}
