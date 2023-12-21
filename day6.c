#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void main(){
    int time[] = {59,79,65,75}, dist[] = {597,1234,1032,1328}, prod=1, tempsum;
    for (int racenum = 0; racenum<4; racenum++){
        tempsum = 0;
        for (int i = 0; i<time[racenum]; i++){
            if ((i*(time[racenum]-i)) > dist[racenum]){tempsum++;}
        }
        prod *= tempsum;
    }
    printf("%i\n",prod);
}