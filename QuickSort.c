#include<stdio.h>
#include<conio.h>


int partition(int arr[] , int first , int last) {

    int pivot = arr[last];
    int i = first-1;
    int j = first;


        for(; j < last; j++) {
            if(arr[j] < pivot){
                i++;
                // swaping(arr[i] , arr[j]);
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swaping(arr[i+1] , arr[last]);
        int temp = arr[i+1];
        arr[i+1] = arr[last];
        arr[last] = temp;

        return i+1;
 
}

void QuickSort(int arr[] , int first , int last) {
    
    // base case
    if(first >= last) {
        return;
    }
              
    int pi = partition(arr , first , last);
    QuickSort(arr , first , pi-1);
    QuickSort(arr , pi+1 , last);
}

int main () {
    int arr[] = {18 , 12 , 16 , 20 , 35 , 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr , 0 , n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d \t" , arr[i]);
    }
    

    return  0;
}