#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

void main(){
    FILE *fptr;
    fptr = fopen("day2input.txt", "r");
    int total = 5050;
    int gamenumber = 1;
    char line[200];
    while(fgets(line, 200, fptr)){
        char *ptr = line;
        while(*ptr){
            if ((*ptr == ':' || *ptr == ',' || *ptr == ';') && isdigit(*(ptr+3)) == 0){
                ptr++;
                continue;
            }
            if ((*ptr == ':' || *ptr == ',' || *ptr == ';') && isdigit(*(ptr+3))){
                if (*(ptr+2) != '1') {
                    total -= gamenumber; ptr++;
                    break;
                } else if ((*(ptr + 5) == 'r')&& (*(ptr+3) > '2')){
                    total -= gamenumber; ptr++;
                    break;
                } else if ((*(ptr + 5) == 'g')&& (*(ptr+3) > '3')){
                    total -= gamenumber; ptr++;
                    break;
                } else if ((*(ptr + 5) == 'b')&& (*(ptr+3) > '4')){
                    total -= gamenumber; ptr++;
                    break;
                }
            }
            ptr++;
        }
        gamenumber++;
    }
    fclose(fptr);
    printf("%i\n", total);
}