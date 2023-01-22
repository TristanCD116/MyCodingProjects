#include<stdlib.h>
#include<stdio.h>

void fib(int in) {

long long int a;
long long int num = 1;
long long int preNum = 0;

if(in < 0 || in > 1000) {
	printf("error");
	exit(0);
}

else { 
	printf("\n%lld  %lld  ", preNum, num);
	//cannot be printed otherwise
	
	for(int i = 3; i <= in; i++) {
		a = num + preNum;
		preNum = num; 
		num = a; 	
		// add together number with previous number 
		// to give a, new num is now a and prenum is num
        	printf("%lld  ", num);
        }
        printf("\n");
   }
}

int main() {

int input;
	
printf("Insert Number: ");
scanf("%d", &input);
fib(input);
//User input
return 0;
}
