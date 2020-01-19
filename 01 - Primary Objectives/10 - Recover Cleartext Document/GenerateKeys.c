#include <time.h>
#include <stdio.h>
#include <uchar.h>
int main(int argc, char** argv) {
    time_t seed = 1575658800;
    time_t temp_seed;
    int i;

    while (seed < 1575666000) {
        time_t this_seed = seed;
        i = 0;
        while (i < 8) {
            this_seed = this_seed * 0x343fd + 0x269ec3;
            temp_seed = this_seed >> 0x10 & 0x7fff;
            printf("%x", (unsigned char)temp_seed);
            i++;
        }
        printf("\n");
        seed++;
    }
    
    return 0;
}