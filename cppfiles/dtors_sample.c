#include<stdio.h>
#include<stdlib.h>

static void cleanup(void) __attribute__ ((destructor));
main(){
	printf("MAIN FUNCTION");
	exit(0);
}

void cleanup(void){
	printf("In the cleanup function now..\n");
}
