#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000


void countingSort(long int arr[], int n) {
    int arr1[1000];

    int x = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
            x = arr[i];
    }


    int count_arr[1000];

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
}
void displayy(long int arr[], long int arr1[], long int arr2[], long int arr3[],long int arr4[],long int arr5[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d%d%d%d%d%d", arr[i], arr1[i], arr2[i], arr3[i],arr4[i],arr5[i]);
        printf("\n");
    }
    printf("\n");
}
void RadixSort() {

    long int arr[SIZE];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000;
    int n = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, n);


    long int arr1[SIZE];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr1[i] = rand() % 1000;
    int n1 = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr1, n1);


    long int arr2[SIZE];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr2[i] = rand() % 1000;
    int n2 = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr2, n2);


    long int arr3[SIZE];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr3[i] = rand() % 1000;
    int n3 = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr3, n3);
   
  
    long int arr4[SIZE];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr4[i] = rand() % 1000;
    int n4 = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr4, n4);
   
    long int arr5[SIZE];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr5[i] = rand() % 1000;
     int n5 = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr5, n5);
 
    displayy(arr, arr1, arr2, arr3, arr4, arr5, n5);

}
void display(long int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}


int main(void){

    RadixSort();

}