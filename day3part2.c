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
            int numnexttogear = 0; int prod = 1;
            if (line2[i] == '*'){
                int tempnum = 0;
                for (int j = -3; j<2;j++){
                    if (isdigit(line1[i+j]) && isdigit(line1[i+1+j]) && isdigit(line1[i+2+j])){
                        tempnum = (line1[i+j] - '0') * 100 + (line1[i+1+j]-'0')*10 + (line1[i+2+j]-'0');
                        prod *= tempnum; numnexttogear++; j += 2;
                    } else if ((j > -3) && isdigit(line1[i+j]) && isdigit(line1[i+1+j]) && (isdigit(line1[i+2+j]) == 0)){
                        tempnum = (line1[i+j] - '0') * 10 + (line1[i+1+j]-'0');
                        prod *= tempnum; numnexttogear++; j++;
                    } else if ((j > -2) && isdigit(line1[i+j]) && (isdigit(line1[i+1+j]) == 0)){
                        tempnum = (line1[i+j] - '0');
                        prod *= tempnum; numnexttogear++;
                    }
                }
                for (int j = -3; j<2;j++){
                    if (isdigit(line3[i+j]) && isdigit(line3[i+1+j]) && isdigit(line3[i+2+j])){
                        tempnum = (line3[i+j] - '0') * 100 + (line3[i+1+j]-'0')*10 + (line3[i+2+j]-'0');
                        prod *= tempnum; numnexttogear++; j += 2;
                    } else if ((j > -3) && isdigit(line3[i+j]) && isdigit(line3[i+1+j]) && (isdigit(line3[i+2+j]) == 0)){
                        tempnum = (line3[i+j] - '0') * 10 + (line3[i+1+j]-'0');
                        prod *= tempnum; numnexttogear++; j++;
                    } else if ((j > -2) && isdigit(line3[i+j]) && (isdigit(line3[i+1+j]) == 0)){
                        tempnum = (line3[i+j] - '0');
                        prod *= tempnum; numnexttogear++;
                    }
                }
                if (isdigit(line2[i-3]) && isdigit(line2[i-2]) && isdigit(line2[i-1])){
                    tempnum = (line2[i-3] - '0') * 100 + (line2[i-2]-'0')*10 + (line2[i-1]-'0');
                    prod *= tempnum; numnexttogear++;
                } else if (isdigit(line2[i-2]) && isdigit(line2[i-1])) {
                    tempnum = (line2[i-2]-'0')*10 + (line2[i-1]-'0');
                    prod *= tempnum; numnexttogear++;
                } else if (isdigit(line2[i-1])){
                    tempnum = (line2[i-1]-'0');
                    prod *= tempnum; numnexttogear++;
                }
                if (isdigit(line2[i+1]) && isdigit(line2[i+2]) && isdigit(line2[i+3])){
                    tempnum = (line2[i+1] - '0') * 100 + (line2[i+2]-'0')*10 + (line2[i+3]-'0');
                    prod *= tempnum; numnexttogear++;
                } else if (isdigit(line2[i+1]) && isdigit(line2[i+2])) {
                    tempnum = (line2[i+1]-'0')*10 + (line2[i+2]-'0');
                    prod *= tempnum; numnexttogear++;
                } else if (isdigit(line2[i+1])){
                    tempnum = (line2[i+1]-'0');
                    prod *= tempnum; numnexttogear++;
                }
            }
            if (numnexttogear == 2) {total += prod;}
        }
    }
    fclose(fptr);
    printf("%i\n", total);
}