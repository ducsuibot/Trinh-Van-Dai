#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Ham tim so nguyen to be hon N
void sieveOfEratosthenes(int N, bool isPrime[]) {
    for (int i = 0; i < N; i++) {
        isPrime[i] = true; // Khoi tao tat ca deu la so nguyen to
    }
    isPrime[0] = isPrime[1] = false; // 0 va 1 khong phai la so nguyen to

    for (int i = 2; i <= sqrt(N); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false; // Danh dau cac boi so cua i la khong nguyen to
            }
        }
    }
}

// Ham in ra tat ca cac cap so nguyen to co tong cung la mot so nguyen to nho hon N
void findPrimePairs(int N, bool isPrime[]) {
    printf("Cac cap so nguyen to co tong cung la so nguyen to nho hon %d:\n", N);
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for (int j = i; j < N; j++) {
                if (isPrime[j] && i + j < N && isPrime[i + j]) {
                    printf("(%d, %d) -> Tong: %d\n", i, j, i + j);
                }
            }
        }
    }
}

// Ham kiem tra xem M co phai la so nguyen to khong
bool isPrimeNumber(int M, bool isPrime[], int N) {
    if (M < N && isPrime[M]) {
        return true;
    }
    return false;
}

int main() {
    int N, M;
    printf("Nhap so N: ");
    scanf("%d", &N);

    // Mang danh dau cac so nguyen to
    bool isPrime[N];

    // Tim tat ca cac so nguyen to nho hon N
    sieveOfEratosthenes(N, isPrime);

    // In ra cac so nguyen to nho hon N
    printf("Cac so nguyen to nho hon %d:\n", N);
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Tim cac cap so nguyen to co tong cung la so nguyen to
    findPrimePairs(N, isPrime);

    // Kiem tra mot so nguyen to M co ton tai khong
    printf("Nhap so nguyen to can kiem tra: ");
    scanf("%d", &M);
    if (isPrimeNumber(M, isPrime, N)) {
        printf("%d la mot so nguyen to.\n", M);
    } else {
        printf("%d khong phai la so nguyen to.\n", M);
    }

    return 0;
}

