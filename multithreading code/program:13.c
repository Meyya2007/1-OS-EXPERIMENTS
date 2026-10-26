#include <stdio.h>
int main() {
    int r[] = {20, 45, 80}, h = 50, i;
    printf("Online Shopping Disk Scheduling\n");
    for(i = 0; i < 3; i++) {
        printf("Request served: %d\n", r[i]);
        h = r[i];
    }
    return 0;
}
