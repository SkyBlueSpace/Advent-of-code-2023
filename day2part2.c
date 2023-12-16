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
    int total = 0;
    char line[200];
    int minred, mingreen, minblue, temp;
    while (fgets(line, 200, fptr)){
        char *ptr = line;
        minred = 0; mingreen = 0; minblue = 0; temp = 0;
        while(*ptr){
            if ((*ptr == ':' || *ptr == ',' || *ptr == ';') && isdigit(*(ptr+3)) == 0){
                temp = *(ptr+2) - '0';
                if ((*(ptr+4) == 'r') && (temp > minred)) {minred = temp;}
                if ((*(ptr+4) == 'g') && (temp > mingreen)) {mingreen = temp;}
                if ((*(ptr+4) == 'b') && (temp > minblue)) {minblue = temp;}
            } else if ((*ptr == ':' || *ptr == ',' || *ptr == ';') && isdigit(*(ptr+3))){
                temp = (*(ptr+2) - '0')*10 + (*(ptr+3) - '0');
                if ((*(ptr+5) == 'r') && (temp > minred)) {minred = temp;}
                if ((*(ptr+5) == 'g') && (temp > mingreen)) {mingreen = temp;}
                if ((*(ptr+5) == 'b') && (temp > minblue)) {minblue = temp;}
            }
            ptr++;
        }
        total += (minred * mingreen * minblue);
    }
    fclose(fptr);
    printf("%i\n", total);
}