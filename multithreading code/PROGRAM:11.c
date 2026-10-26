#include <stdio.h>

// Function for LRU Page Replacement
void lru(int p[], int n, int capacity) {
    int frames[10], time[10], counter = 0, flag1, flag2, i, j, pos, faults = 0;

    for (i = 0; i < capacity; ++i) {
        frames[i] = -1;
    }

    for (i = 0; i < n; ++i) {
        flag1 = flag2 = 0;

        // Check if page already exists in frames
        for (j = 0; j < capacity; ++j) {
            if (frames[j] == p[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page is not present and there is an empty frame
        if (flag1 == 0) {
            for (j = 0; j < capacity; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = p[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If page is not present and frames are full, replace LRU
        if (flag2 == 0) {
            int min = time[0];
            pos = 0;
            for (j = 1; j < capacity; ++j) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }
            counter++;
            faults++;
            frames[pos] = p[i];
            time[pos] = counter;
        }

        printf("\nAfter referencing %d: ", p[i]);
        for (j = 0; j < capacity; ++j) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
    }
    printf("\n\nTotal Page Faults (LRU) = %d\n", faults);
}

// Function for LFU Page Replacement
void lfu(int p[], int n, int capacity) {
    int frames[10], freq[10], age[10], i, j, faults = 0, time = 0;

    for (i = 0; i < capacity; ++i) {
        frames[i] = -1;
        freq[i] = 0;
        age[i] = 0;
    }

    for (i = 0; i < n; ++i) {
        int found = 0;
        time++;

        // Check if page is already in frames (Hit)
        for (j = 0; j < capacity; ++j) {
            if (frames[j] == p[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        // If not found, find an empty frame
        if (!found) {
            for (j = 0; j < capacity; ++j) {
                if (frames[j] == -1) {
                    frames[j] = p[i];
                    freq[j] = 1;
                    age[j] = time;
                    faults++;
                    found = 1;
                    break;
                }
            }
        }

        // If not found and frames are full, replace LFU (with FIFO tie-breaker)
        if (!found) {
            int min_freq = freq[0];
            int min_age = age[0];
            int pos = 0;

            for (j = 1; j < capacity; ++j) {
                if (freq[j] < min_freq) {
                    min_freq = freq[j];
                    min_age = age[j];
                    pos = j;
                } else if (freq[j] == min_freq) {
                    if (age[j] < min_age) {
                        min_age = age[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = p[i];
            freq[pos] = 1;
            age[pos] = time;
            faults++;
        }

        printf("\nAfter referencing %d: ", p[i]);
        for (j = 0; j < capacity; ++j) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
    }
    printf("\n\nTotal Page Faults (LFU) = %d\n", faults);
}

int main() {
    int n, capacity, choice, i;
    int p[20];

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    printf("Enter number of elements in reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("\n--- MENU ---\n");
    printf("1. LRU Page Replacement\n");
    printf("2. LFU Page Replacement\n");
    printf("3. Both\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n--- LRU Page Replacement ---");
            lru(p, n, capacity);
            break;
        case 2:
            printf("\n--- LFU Page Replacement ---");
            lfu(p, n, capacity);
            break;
        case 3:
            printf("\n--- LRU Page Replacement ---");
            lru(p, n, capacity);
            printf("\n\n--- LFU Page Replacement ---");
            lfu(p, n, capacity);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
