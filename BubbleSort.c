#include<stdio.h>
#include<conio.h>


void swap(int* x , int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int arr[] , int n) {
    //Bubble sort Algorithm
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) { 
            if(arr[j] > arr[j+1]) {
                swap(&arr[j] , &arr[j+1]);
            }
        }

    }
}
void displayArray(int arr[] , int n) {
    for(int i = 0; i < n; i++) {
        printf("%d \t" ,arr[i]);
    }
}


int main() {

    int arr[10] = {10 , 9 , 8 , 7 , 6 , 5 , 4 , 3  , 2 , 1};
    int n = 10;
    printf("Before Sorting \n");
    displayArray(arr , n); 
    printf("\n After Sorting \n");
    BubbleSort(arr , n);
    displayArray(arr , n);



    return 0;
}