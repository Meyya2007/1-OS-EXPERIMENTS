#include <stdio.h>

int main() {
    int f, n, i, j, faults = 0, q[20], front = 0, rear = 0;
    
    printf("frames: "); 
    scanf("%d", &f);
    
    printf("No of pages: "); 
    scanf("%d", &n);
    
    int page[n];
    printf("pages: ");
    
    for (i = 0; i < n; i++) 
        scanf("%d", &page[i]);
        
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = front; j < rear; j++) {
            if (q[j] == page[i]) {
                found = 1; 
                break;
            }
        }
        if (!found) {
            faults++;
            if (rear - front == f) 
                front++;
            q[rear++] = page[i];
        }
    }
    
    printf("page faults: %d\n", faults);
    return 0;
}
