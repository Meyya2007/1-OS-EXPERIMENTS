#include <stdio.h>

int main()
{
    int i;
    printf("ATM service started\n");
    for(i=1; i<=5; i++)
    {
        printf("customer %d waiting \n",i);
        printf("customer %d using ATM \n",i);
        printf("customer %d left ATM \n",i);
    }
    printf("All customers served \n");
    return 0;
}
