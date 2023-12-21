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
    fptr = fopen("day5input.txt", "r");
    long long min; char line[150]; 
    long long seeds[] = {2906961955, 52237479, 1600322402, 372221628, 2347782594, 164705568, 541904540, 89745770, 126821306, 192539923, 3411274151, 496169308, 919015581, 8667739, 654599767, 160781040, 3945616935, 85197451, 999146581, 344584779}
    , soil[20] = {0}, fert[20] = {0}, water[20] = {0}, light[20] = {0}, temp[20] = {0}, humid[20] = {0}, location[20] = {0}, tempnum;
    int linenum = 0, i, j, k;
    while (fgets(line,150,fptr)){
        long long cond[3] = {0};
        for (i = 0; i < 3; i++){
            for (j = 0; j < 10; j++){
                if (isdigit(line[11*i+j])){
                    tempnum = line[11*i+j]-'0';
                    for (k=0; k<9-j;k++){tempnum*=10;}
                    cond[i] += tempnum;
                }
            }
        }
        if (3 < linenum && linenum < 17){
            for (i = 0; i<20; i++){
                if ((cond[1] <= seeds[i]) && (seeds[i] < (cond[1]+cond[2]))){
                    soil[i] = seeds[i] - cond[1] + cond[0];
                }
            }
        } else if (linenum == 17){
            for (i = 0; i<20; i++){
                if (soil[i] == 0){ soil[i] = seeds[i];}
            }
        } else if (18 < linenum && linenum < 40){
            for (i = 0; i<20; i++){
                if ((cond[1] <= soil[i]) && (soil[i] < (cond[1]+cond[2]))){
                    fert[i] = soil[i] - cond[1] + cond[0];
                }
            }
        } else if (linenum == 40){
            for (i = 0; i<20; i++){
                if (fert[i] == 0){ fert[i] = soil[i];}
            }
        } else if (41 < linenum && linenum < 90){
            for (i = 0; i<20; i++){
                if ((cond[1] <= fert[i]) && (fert[i] < (cond[1]+cond[2]))){
                    water[i] = fert[i] - cond[1] + cond[0];
                }
            }
        } else if (linenum == 90){
            for (i = 0; i<20; i++){
                if (water[i] == 0){ water[i] = fert[i];}
            }
        } else if (91 < linenum && linenum < 131){
            for (i = 0; i<20; i++){
                if ((cond[1] <= water[i]) && (water[i] < (cond[1]+cond[2]))){
                    light[i] = water[i] - cond[1] + cond[0];
                }
            }
        } else if (linenum == 131){
            for (i = 0; i<20; i++){
                if (light[i] == 0){ light[i] = water[i];}
            }
        } else if (132 < linenum && linenum < 149){
            for (i = 0; i<20; i++){
                if ((cond[1] <= light[i]) && (light[i] < (cond[1]+cond[2]))){
                    temp[i] = light[i] - cond[1] + cond[0];
                }
            }
        } else if (linenum == 149){
            for (i = 0; i<20; i++){
                if (temp[i] == 0){ temp[i] = light[i];}
            }
        } else if (150 < linenum && linenum < 158){
            for (i = 0; i<20; i++){
                if ((cond[1] <= temp[i]) && (temp[i] < (cond[1]+cond[2]))){
                    humid[i] = temp[i] - cond[1] + cond[0];
                }
            }
        } else if (linenum == 158){
            for (i = 0; i<20; i++){
                if (humid[i] == 0){ humid[i] = temp[i];}
            }
        } else if (159 < linenum && linenum < 191){
            for (i = 0; i<20; i++){
                if ((cond[1] <= humid[i]) && (humid[i] < (cond[1]+cond[2]))){
                    location[i] = humid[i] - cond[1] + cond[0];
                }
            }
        }
        for (i = 0; i<20; i++){
            if (location[i] == 0){ location[i] = humid[i];}
        }
        linenum++;
    }
    min = location[0];
    for (i = 0; i<20; i++){
        if (location[i] < min){printf("%i\n", i);min = location[i];}
    }
    printf("%lld\n", min); 
    fclose(fptr);
}