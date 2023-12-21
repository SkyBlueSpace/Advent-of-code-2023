#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void main(){
    FILE *fptr;
    fptr = fopen("day4input.txt", "r");
    int total = 0; char line[150]; int score;
    while (fgets(line,150,fptr)){
        score = 0; int i,j;
        for (i = 0; i < 25; i++){
            for (j = 0; j < 10; j++){
                if ((line[3*j+10] == line[3*i+42]) && (line[3*j+11] == line[3*i+43])){
                    if (score == 0){score++;} else {score*=2;}
                    break;
                }
            }
        }
        total += score;
    }
    printf("%i\n", total);
    fclose(fptr);
}