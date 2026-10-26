#include <stdio.h>
int main() {
    char files[3][20] = {"notes.txt", "photo.jpg", "resume.doc"};
    printf("Single-Level Directory\n");
    for(int i = 0; i < 3; i++)
        printf("%s\n", files[i]);
    return 0;
}


For single directory
