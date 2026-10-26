#include <stdio.h>
int main() {
    int index[] = {10, 15, 22, 30};
    printf("Indexed File Allocation\n");
    printf("Railway Reservation Records:\n");
    for(int i = 0; i < 4; i++)
        printf("Record %d: Block %d\n", i+1, index[i]);
    return 0;
}



Indexed file allocation
