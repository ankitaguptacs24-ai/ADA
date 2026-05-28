#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to find the largest mobile element
int getMobile(int a[], int dir[], int n) {
    int mobile = 0, mobile_index = -1;

    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i != 0 && a[i] > a[i - 1]) {
            if (a[i] > mobile) {
                mobile = a[i];
                mobile_index = i;
            }
        }
        if (dir[i] == RIGHT && i != n - 1 && a[i] > a[i + 1]) {
            if (a[i] > mobile) {
                mobile = a[i];
                mobile_index = i;
            }
        }
    }
    return mobile_index;
}


void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


void johnsonTrotter(int n) {
    int a[n], dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    while (1) {
        int mobile_index = getMobile(a, dir, n);

        if (mobile_index == -1)
            break;


        if (dir[mobile_index] == LEFT) {
            int temp = a[mobile_index];
            a[mobile_index] = a[mobile_index - 1];
            a[mobile_index - 1] = temp;

            int tempDir = dir[mobile_index];
            dir[mobile_index] = dir[mobile_index - 1];
            dir[mobile_index - 1] = tempDir;

            mobile_index = mobile_index - 1;
        } else {
            int temp = a[mobile_index];
            a[mobile_index] = a[mobile_index + 1];
            a[mobile_index + 1] = temp;

            int tempDir = dir[mobile_index];
            dir[mobile_index] = dir[mobile_index + 1];
            dir[mobile_index + 1] = tempDir;

            mobile_index = mobile_index + 1;
        }


        for (int i = 0; i < n; i++) {
            if (a[i] > a[mobile_index]) {
                dir[i] = -dir[i];
            }
        }

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);
    return 0;
}