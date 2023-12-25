#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototype fungsi
void generateRandomArray(int array[], int size);
void bubbleSort(int array[], int size);
int binarySearch(int array[], int left, int right, int target);
void playGame(int array[], int size);

int main() {
    // Seed untuk bilangan acak
    srand(time(NULL));

    // Menentukan ukuran array
    int size = 10;
    
    // Deklarasi dan inisialisasi array
    int numberArray[size];
    
    // Menghasilkan array angka secara acak
    generateRandomArray(numberArray, size);
    
    // Urutkan array
    bubbleSort(numberArray, size);

    // Mulai permainan tebak angka
    playGame(numberArray, size);

    return 0;
}

void generateRandomArray(int array[], int size) {
    // Isi array dengan bilangan acak antara 1 - 100
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1;
    }
}

void bubbleSort(int array[], int size) {
    // Urutkan array menggunakan algoritma bubble sort
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                // Tukar elemen jika berada di dalam urutan yang salah
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int array[], int left, int right, int target) {
    // Lakukan pencarian biner untuk menemukan target dalam array yang terurut
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid; // Elemen ditemukan
        }

        if (array[mid] > target) {
            return binarySearch(array, left, mid - 1, target); // Cari di setengah kiri
        }

        return binarySearch(array, mid + 1, right, target); // Cari di setengah kanan
    }

    return -1; // Elemen tidak ditemukan
}

void playGame(int array[], int size) {
    // Tampilkan petunjuk
    printf("Selamat datang di Permainan Tebak Angka!\n");
    printf("Coba tebak angka yang benar antara 1 dan 100.\n");

    // Hasilkan angka target secara acak
    int target = rand() % 100 + 1;
    
    int tebakan;
    int percobaan = 0;

    do {
        // Input
        printf("Masukkan tebakan Anda: ");
        scanf("%d", &tebakan);

        // Tingkatkan jumlah percobaan
        percobaan++;

        // Periksa tebakan
        int hasil = binarySearch(array, 0, size - 1, tebakan);

        if (hasil != -1) {
            printf("Selamat! Anda menemukan angka yang benar dalam %d percobaan.\n", percobaan);
            return;
        } else {
            printf("Coba lagi! ");

            // Berikan petunjuk berdasarkan perbandingan
            if (tebakan < target) {
                printf("Angka yang benar lebih tinggi.\n");
            } else {
                printf("Angka yang benar lebih rendah.\n");
            }
        }
    } while (1); // Perulangan tak terbatas sampai angka yang benar ditebak
}
