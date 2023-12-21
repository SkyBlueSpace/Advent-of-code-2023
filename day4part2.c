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
    int total = 0; char line[150]; int matches; int linenum = 0; int numofcards[197] = {0};
    while (fgets(line,150,fptr)){
        numofcards[linenum] += 1;
        matches = 0; int i,j;
        for (i = 0; i < 25; i++){
            for (j = 0; j < 10; j++){
                if ((line[3*j+10] == line[3*i+42]) && (line[3*j+11] == line[3*i+43])){
                    matches++;
                    break;
                }
            }
        }
        for (i = 0;i<matches;i++){
            numofcards[linenum+i+1] += numofcards[linenum];
        }
        linenum++;
    }
    for (int i = 0;i<197;i++){
            total += numofcards[i];
    }
    printf("%i\n", total);
    fclose(fptr);
}