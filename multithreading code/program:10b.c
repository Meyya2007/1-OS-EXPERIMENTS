#include <stdio.h>

int main() {
    int f, n, i, j, faults = 0, q[50], front = 0, rear = 0, p[50];

    scanf("%d%d", &f, &n);

    for(i = 0; i < n; i++) 
        scanf("%d", &p[i]);

    for(i = 0; i < n; i++) {
        for(j = front; j < rear; j++) {
            if(q[j] == p[i])
                break;
        }

        if(j == rear) {
            faults++;
            if(rear - front == f) {
                front++;
            }
            q[rear++] = p[i];
        }
    }

    printf("page faults : %d", faults);

    return 0;
}
