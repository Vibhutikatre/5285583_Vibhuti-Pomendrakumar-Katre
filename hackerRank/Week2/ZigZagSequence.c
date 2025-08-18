#include <stdio.h>
#include <stdlib.h>

void findZigZagSequence(long long arr[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                long long temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int mid = (n - 1) / 2;
    long long temp = arr[mid];
    arr[mid] = arr[n - 1];
    arr[n - 1] = temp;

    int front = mid + 1;
    int back = n - 2;
    while (front <= back) {
        temp = arr[front];
        arr[front] = arr[back];
        arr[back] = temp;
        front++;
        back--;
    }

    for (int i = 0; i < n; i++) {
        printf("%lld", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
        }
        findZigZagSequence(arr, n);
    }
    return 0;
}
