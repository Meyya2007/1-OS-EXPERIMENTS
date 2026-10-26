#include <stdio.h>
int main() {
    int blocks[] = {10, 11, 12, 13};
    printf("Sequential File Allocation\n");
    printf("Railway Reservation Records:\n");
    for(int i = 0; i < 4; i++)
        printf("Record %d: Block %d\n", i+1, blocks[i]);
    return 0;
}


Sequential file allocation
