#include "random.h"
#include <stdio.h>

int random_main(int argc, char* argv[])
{
    int i;
    /* generate 10 random number in (0, 1) with a seed = -2 */
    printf("10 random number in (0, 1)\n");
    long seed = -2;
    for (i = 0; i < 10; i++) {
        printf("random number %d = %f\n", i, ran1(&seed));
    }
    printf("\n");
    
    printf("10 random integers between [10, 50]\n");
    /* generate 10 random integers between [min, max] */
    for (i = 0; i < 10; i++) {
        printf("random integer %d in [10, 50] = %d\n", i, ranInt(10, 50));
    }
    
    printf("\n");

    printf("10 random CPU bursts from Poisson distribution with average length of 13\n");
    /* generate 10 random CPU bursts from Poisson distribution with average length of 13 */
    for (i = 0; i < 10; i++) {
        printf("CPU Burst %d from Poisson distribution = %d \n", i, CPUBurstRandom(13));
    }

    return 0;
}
