#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void main(){
    long long time = 59796575, dist = 597123410321328, temp = 0;
    for (int i = 0; i<dist; i++){
        if ((i*(time-i)) > dist){temp = i; break;}
    }
    printf("%lld\n",time-2*temp+1);
}