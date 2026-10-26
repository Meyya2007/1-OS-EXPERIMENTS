#include <stdio.h>
int main() {
    int b[]={100,250,500}, p=200, i, best=-1;
    for(i=0;i<3;i++)
        if(b[i]>=p && (best==-1 || b[i]<b[best])) best=i;
    printf("Hospital: Patient Monitoring\n");
    if(best!=-1) printf("Allocated: %d KB",b[best]);
    else printf("Memory not available");
    return 0;
}


Best fit memory mangement

