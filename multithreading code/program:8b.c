#include <stdio.h>

int main() {
    int bt[] = {6, 2, 4}, wt[3] = {0}, tat[3], i, t;
    if (bt[0] > bt[1]) {t = bt[0]; bt[0] = bt[1]; bt[1] = t;}
    if (bt[1] > bt[2]) {t = bt[1]; bt[1] = bt[2]; bt[2] = t;}
    if (bt[0] > bt[1]) {t = bt[0]; bt[0] = bt[1]; bt[1] = t;}
    for (i = 1; i < 3; i++) wt[i] = wt[i-1] + bt[i-1];
    for (i = 0; i < 3; i++) tat[i] = wt[i] + bt[i];
    printf("Debris \t proc \t wait \t tat \n");
    for (i = 0; i < 3; i++) 
        printf("D%d \t %d \t %d \t %d \n", i+1, bt[i], wt[i], tat[i]);
    return 0;
}
