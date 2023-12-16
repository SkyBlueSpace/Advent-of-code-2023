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
    fptr = fopen("day3input.txt", "r");
    int total = 0;
    char line[150]; char line3[150]; char line2[150];
    char line1[] = "............................................................................................................................................\n";
    strcpy(line2, line1);
    strcpy(line3, line2);
    while (fgets(line,150,fptr)){
        strcpy(line1, line2);
        strcpy(line2, line3);
        strcpy(line3, line);
        for (int i = 0; i < 141;i++) {
            int tempnum = 0;
            if (isdigit(line2[i]) && isdigit(line2[i+1]) && isdigit(line2[i+2])){
                tempnum = (line2[i] - '0') * 100 + (line2[i+1]-'0')*10 + (line2[i+2]-'0');
                if ((i == 0) && ((line1[3] != '.') || (line2[3] != '.') || (line3[3] != '.'))) {
                    total += tempnum;
                } else if ((i == 137) && ((line1[136] != '.') || (line2[136] != '.') || (line3[136] != '.'))){
                    total += tempnum;
                } else if ((i != 0) && (i != 137) && ((line1[i-1] != '.') || (line1[i] != '.') || (line1[i+1] != '.') || (line1[i+2] != '.') || (line1[i+3] != '.') || (line3[i-1] != '.') || (line3[i] != '.') || (line3[i+1] != '.') || (line3[i+2] != '.') || (line3[i+3] != '.') || (line2[i+3] != '.') || (line2[i-1] != '.'))) {
                    total += tempnum;
                }
                i += 2;
            } else if (isdigit(line2[i]) && isdigit(line2[i+1]) && (isdigit(line2[i+2]) == 0)){
                tempnum = (line2[i] - '0') * 10 + (line2[i+1]-'0');
                if ((line1[i-1] != '.') || (line1[i] != '.') || (line1[i+1] != '.') || (line1[i+2] != '.') || (line3[i-1] != '.') || (line3[i] != '.') || (line3[i+1] != '.') || (line3[i+2] != '.') || (line2[i+2] != '.') || (line2[i-1] != '.')) {
                    total += tempnum;
                }
                i++;
            } else if (isdigit(line2[i]) && (isdigit(line2[i+1]) == 0)){
                tempnum = (line2[i] - '0');
                if (i == 0) {continue;}
                if ((line1[i-1] != '.') || (line1[i] != '.') || (line1[i+1] != '.') || (line3[i-1] != '.') || (line3[i] != '.') || (line3[i+1] != '.') || (line2[i+1] != '.') || (line2[i-1] != '.')){
                    total += tempnum;
                }
            }
        }
    }
    fclose(fptr);
    printf("%i\n", total);
}