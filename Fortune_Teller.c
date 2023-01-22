#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]) {

	double res;
	if (argc > 1) {
	int check = atoi(argv[1]);
	srand(time(NULL));
	res = ceil(rand()/100000000);
	if(argc == 2 && check != 0) {
		printf("Error"); }
	else {
		printf("My answer: \n");
	if(res >= 1 && res < 3) { // 1 or 2
		printf("my sources say no\n"); }
	else if (res > 2 && res < 5 ) { // 3 or 4
	        printf("as I see it, it is certain\n"); }
	else if(res > 4 && res < 7) { //5 or 6
                printf("multiple different signs detected, answer unclear\n"); }
	else if(res > 6 && res < 9)  { // 7 or 8
		printf("it is highly unlikely\n"); }
	else if(res > 8 && res < 11) { // 9 or 10
		printf("it is decidedly so\n"); }
	else if(res > 10 && res < 13) { // 11 or 12
		printf("better not tell you know\n"); }
	else if(res > 12 && res < 15) { // 13 or 14
		printf("my sources say no\n"); }
	else if(res > 14 && res < 17) { // 15 or 16
		printf("outlook not so good\n"); }
	else if(res > 16 && res < 19) { // 17 or 18
		printf("ask again later"); }
	else { // 19 or 20
		printf("it is very likely\n"); } } 
	}
        else { 
		printf("No user input detected\n"); } }


