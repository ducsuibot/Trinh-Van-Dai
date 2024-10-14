#include <stdio.h>

void dutchNationalFlag(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    // 0: do, 1: trang, 2: xanh
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:  // mau do
                // Hoan doi arr[low] va arr[mid], sau do tang low va mid
                {
                    int temp = arr[low];
                    arr[low] = arr[mid];
                    arr[mid] = temp;
                    low++;
                    mid++;
                }
                break;

            case 1:  // mau trang
                // Giu nguyen, chi tang mid
                mid++;
                break;

            case 2:  // mau xanh
                // Hoan doi arr[mid] va arr[high], giam high
                {
                    int temp = arr[mid];
                    arr[mid] = arr[high];
                    arr[high] = temp;
                    high--;
                }
                break;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            printf("do ");
        else if (arr[i] == 1)
            printf("trang ");
        else
            printf("xanh ");
    }
    printf("\n");
}

int main() {
    // Ma hoa mau: do = 0, trang = 1, xanh = 2
    int arr[] = {0, 2, 0, 1, 0, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    dutchNationalFlag(arr, n);
    printArray(arr, n);

    return 0;
}

