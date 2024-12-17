#include<stdio.h>
#include<conio.h>

void SelectionSort(int data[] , int n) {
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;

        for(int j = i+1; j < n; j++) {
            if(data[j] < data[min_idx]) {
                min_idx = j;
            }
        }

        int temp = data[i];
        data[i] = data[min_idx];
        data[min_idx] = temp;
    }
}

void displayArray(int data[] , int n) {
    for(int i = 0; i < n; i++) {
        printf("%d \t" ,data[i]);
    }
}

int main() {

    int data[5] = {5 , 4 ,3 ,2 ,1 };   
    int n = 5;
    displayArray(data , n);
    SelectionSort(data , n);
    printf("\n Sorted Array \n");
    displayArray(data , n);
    return 0;
}