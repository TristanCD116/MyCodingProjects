#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() {

    double input;
    double divide;
    int i;
    int count = 0;

    printf("\nPRIME DETECTOR");
    printf("\n\ninput number: ");
    scanf("%lf", &input);
    //input process
    //
    for(i = 1; i <= input; i++) {
            divide = input/i;
            if(ceil(divide)==floor(divide)) {
                    printf("\ninput is divisible by: %d", i);
                    count++;
            }
    }
    //Check all possibilities
    //
    if(count < 3 && count > 0) {
            printf("\n\nCONCLUSION: NUMBER IS PRIME\n");
            }
    else if(count > 2) {
            printf("\n\nCONCLUSION: NON-PRIME\n");
            }
    else {
            printf("ERROR: INVALID OPERATOR\n");
            }
    return 0;
}
