#include <stdio.h>

int main() {
    int n = 3, bt[] = {4, 2, 6}, wt[3] = {0}, tat[3];
    for(int i = 1; i < n; i++) 
        wt[i] = wt[i-1] + bt[i-1];
    for(int i = 0; i < n; i++) 
        tat[i] = wt[i] + bt[i];
    printf("Debris\tproc\twait\tTAT\n");
    for(int i = 0; i < n; i++) 
        printf("D%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    return 0;
}
