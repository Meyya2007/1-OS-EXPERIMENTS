#include <stdio.h>
int main() {
    char *users[] = {"Arun", "Priya"};
    char *files[] = {"notes.txt", "photo.jpg"};
    printf("Two-Level Directory\n");
    for(int i = 0; i < 2; i++)
        printf("%s: %s\n", users[i], files[i]);
    return 0;
}




For double directory
