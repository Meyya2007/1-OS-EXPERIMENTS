#include <stdio.h>

int main() {
    int n, q, i, g[10], rem[10], t = 0;
    printf("Patients & quantum: "); 
    scanf("%d%d", &n, &q);
    
    for (i = 0; i < n; i++) {
        printf("Glucose p%d: ", i + 1);
        scanf("%d", &g[i]); 
        rem[i] = g[i];
    }
    
    printf("\n RR server:\n");
    
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;
                int x = (rem[i] > q) ? q : rem[i];
                printf("p%d (%d)\t", i + 1, x);
                rem[i] -= x; 
                t += x;
            }
        }
        if (done) break;
    }
    
    printf("\n total time: %d\n", t); 
    return 0;
}
