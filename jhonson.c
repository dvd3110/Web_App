#include <stdio.h>

#define MAXN 10

int p[MAXN];
int dir[MAXN];


void printPermutation(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void generatePermutations(int n) {

    printPermutation(n);

    int mobile, mobileIndex;
    while (1) {
        mobile = 0;
        mobileIndex = -1;


        for (int i = 0; i < n; i++) {
            if ((dir[i] == -1 && i > 0 && p[i] > p[i - 1]) ||
                (dir[i] == 1 && i < n - 1 && p[i] > p[i + 1])) {
                if (p[i] > mobile) {
                    mobile = p[i];
                    mobileIndex = i;
                }
            }
        }


        if (mobileIndex == -1) {
            break;
        }


        if (dir[mobileIndex] == -1) {
            swap(&p[mobileIndex], &p[mobileIndex - 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex - 1]);
            mobileIndex--;
        }
        else if (dir[mobileIndex] == 1) {
            swap(&p[mobileIndex], &p[mobileIndex + 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex + 1]);
            mobileIndex++;
        }

        for (int i = 0; i < n; i++) {
            if (p[i] > mobile) {
                dir[i] = -dir[i];
            }
        }


        printPermutation(n);
    }
}

int main() {
    int n;

    printf("Enter the value of n (maximum %d): ", MAXN);
    scanf("%d", &n);

    if (n <= 0 || n > MAXN) {
        printf("Invalid value of n!\n");
        return 0;
    }


    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i] = -1;
    }


    generatePermutations(n);

    return 0;
}
