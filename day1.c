#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

void main(){
    FILE *fptr;
    fptr = fopen("day1input.txt", "r");
    int Firstdigit = 0;
    int Lastdigit = 0;
    int temp;
    char line[100];
        while(fgets(line, 100, fptr)){
            temp = 10;
            char *ptr = line;
            while(*ptr){
                if (isdigit(*ptr)) {
                    if (temp == 10){
                        temp = *ptr - '0';
                        Firstdigit += temp;
                    } else {
                        temp = *ptr - '0';
                    }
                } else if (*ptr == 'o' && *(ptr+1) == 'n' && *(ptr+2) == 'e'){
                    if (temp == 10){Firstdigit += 1; temp = 1;} else {temp = 1;}; 
                } else if (*ptr == 't' && *(ptr+1) == 'w' && *(ptr+2) == 'o'){
                    if (temp == 10){Firstdigit += 2; temp = 2;} else {temp = 2;};
                } else if (*ptr == 's' && *(ptr+1) == 'i' && *(ptr+2) == 'x'){
                    if (temp == 10){Firstdigit += 6; temp = 6;} else {temp = 6;};
                } else if (*ptr == 'f' && *(ptr+1) == 'o' && *(ptr+2) == 'u' && *(ptr+3) == 'r'){
                    if (temp == 10){Firstdigit += 4; temp = 4;} else {temp = 4;};
                } else if (*ptr == 'f' && *(ptr+1) == 'i' && *(ptr+2) == 'v' && *(ptr+3) == 'e'){
                    if (temp == 10){Firstdigit += 5; temp = 5;} else {temp = 5;};
                } else if (*ptr == 'n' && *(ptr+1) == 'i' && *(ptr+2) == 'n' && *(ptr+3) == 'e'){
                    if (temp == 10){Firstdigit += 9; temp = 9;} else {temp = 9;};
                } else if (*ptr == 't' && *(ptr+1) == 'h' && *(ptr+2) == 'r' && *(ptr+3) == 'e' && *(ptr+4)== 'e'){
                    if (temp == 10){Firstdigit += 3; temp = 3;} else {temp = 3;};
                } else if (*ptr == 's' && *(ptr+1) == 'e' && *(ptr+2) == 'v' && *(ptr+3) == 'e' && *(ptr+4)== 'n'){
                    if (temp == 10){Firstdigit += 7; temp = 7;} else {temp = 7;};
                }  else if (*ptr == 'e' && *(ptr+1) == 'i' && *(ptr+2) == 'g' && *(ptr+3) == 'h' && *(ptr+4)== 't'){
                    if (temp == 10){Firstdigit += 8; temp = 8;} else {temp = 8;};
                }
                ptr++;
            }
            Lastdigit += temp;
        }
    printf("%i\n", Firstdigit*10 + Lastdigit);
    fclose(fptr);
}