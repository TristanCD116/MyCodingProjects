#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void board(char array[10]) { 
system("clear");
printf("   TIC TAC TOE\n\n"); 
printf("     |     |     \n");
printf("  %c  |  %c  |  %c  \n", array[0], array[1], array[2]);
printf("-----|-----|-----\n");
printf("     |     |     \n");
printf("  %c  |  %c  |  %c  \n", array[3], array[4], array[5]);
printf("-----|-----|-----\n");
printf("     |     |     \n");
printf("  %c  |  %c  |  %c  \n", array[6], array[7], array[8]); 
}

void winCheck(char array[10], char letter) {
	board(array);

	if(array[0] == array[1] && array[1] == array[2]) {
		printf("\nWINNER: %c\n", letter);
		exit(1); }
	else if(array[3] == array[4] && array[4] == array[5]) {
		printf("\nWINNER: %c\n", letter);
	        exit(1); }
	else if(array[6] == array[7] && array[7] == array[8]) {
		printf("\nWINNER: %c\n", letter); // to be fixed 
		exit(1); } 
	else if(array[0] == array[3] && array[3] == array[6]) {
		printf("\nWINNER: %c\n", letter);
                exit(1); }
	else if(array[1] == array[4] && array[4] == array[7]) {
		printf("\nWINNER: %c\n", letter);
		exit(1); }
	else if(array[2] == array[5] && array[5] == array[8]) {
		printf("\nWINNER: %c\n", letter);
		exit(1); }
	else if(array[0] == array[4] && array[4] == array[8]) {
		printf("\nWINNER: %c\n", letter);
		exit(1); }
	else if(array[6] == array[4] && array[4] == array[2]) {
		printf("\nWINNER: %c\n", letter);
		exit(1); }
}

int main() {

char letter;
int selec = 0;
int i;
int used[10];
char array[10] = {'1', '2', '3', '4', '5', '6', '7', '8','9'};

board(array);
printf("\nplayer 1 (O), pick a quadrant: ");
scanf(" %d", &selec);

while(selec > 9 || selec < 1) {
       if (isdigit(selec) == 0) {
	printf("%d", isdigit(selec));
  	exit(1);
	        }
       else {  
	printf("%d", isdigit(selec));     
	printf("please select an available square:\n ");  
	scanf(" %d", &selec); } }  
used[selec] = selec;
array[selec-1] = 'O'; 

for(i = 1; i <= 4; i++) {

winCheck(array, letter);
letter = 'X';
board(array);
	printf("\nplayer 2 (X), pick a quadrant: ");
	scanf(" %d",&selec);
	while(selec > 9 || selec == used[selec]) {
		printf("please select an available square: ");
		scanf(" %d", &selec);
          	} 
	used[selec] = selec;
	array[selec-1] = letter;   


winCheck(array, letter);
letter = 'O';
board(array);
	printf("\nplayer 1 (O), pick a quadrant: ");
	scanf(" %d", &selec);
	while(selec > 9 || selec == used[selec]) {
		printf("please select an available square: ");
		scanf(" %d", &selec); } 
	array[selec-1] = letter;
	used[selec] = selec;

	}

// if tie
winCheck(array, letter);
board(array);
printf("No winner declared!\n");
return 0; 

} 

	

