#include <stdio.h>
#include <stdlib.h>

// Simple bubble sort for the median
void sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double getMean(int* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

double getMedian(int* arr, int n) {
    sort(arr, n);
    if (n % 2 == 0) return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    return arr[n / 2];
}

void printMode(int* arr, int n) {
    int maxCount = 0;
    // Basic frequency logic
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) count++;
        }
        if (count > maxCount) maxCount = count;
    }
    printf("Mode(s): ");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) if (arr[j] == arr[i]) count++;
        if (count == maxCount) {
            printf("%d ", arr[i]);
            // Skip duplicates for printing
            i += (count - 1);
        }
    }
    printf("\n");
}

int main() {
    int data[] = {4, 1, 2, 2, 3};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Mean: %.2f\n", getMean(data, n));
    printf("Median: %.2f\n", getMedian(data, n));
    printMode(data, n);

    return 0;
}