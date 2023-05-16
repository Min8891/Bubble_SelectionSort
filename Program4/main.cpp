//  Program4 Bubble Sort vs Selection Sort
//  Created by Minjing Liang on 9/18/20.
//  Copyright © 2020 Minjing Liang. All rights reserved.

#include <iostream>
#include <iomanip>
using namespace std;
//function prototype
void display(int[],int);
void bubbleSort(int[],int);
void selectionSort(int[],int);
void swap(int &,int &);

int main() {
    // declare and initialize first array
    const int SIZE = 8;
    int arr1[SIZE] = {72, 8, 15, 0, 46, 100, 29, 3};
    // declare second array and copy first array's contents
    int arr2[SIZE];
    for (int i = 0; i < SIZE; i++){
        arr2[i] = arr1[i];
    }
    cout << "This program will use bubble sort and selection sort\n";
    cout << "to sort an array in ascending order. It will display\n";
    cout << "the array contents each pass of the sort.\n\n";
    cout << "Show first array and start bubble sort" << endl;
    // call display function
    display(arr1,SIZE);
    // call bubble sort function
    bubbleSort(arr1,SIZE);
    cout << "\nNow show second array and start selection sort." <<endl;
    // call display function
    display(arr2,SIZE);
    // call selection sort function
    selectionSort(arr2, SIZE);
    return 0;
}
void display (int arr[], int size){
    // for loop show array contents
    for (int i = 0; i < size; i++)
        cout << left <<setw(5) << arr[i] << " ";
    cout << endl;
}
void bubbleSort(int arr[], int size){         // bubble sort an int array in ascending order
    int maxElement;
    int index;
    for (maxElement = size -1; maxElement > 0; maxElement--){   // two for-loop to compare two neighbor elements and
        for (index = 0; index < maxElement; index++){           //  switch places
            if(arr[index] > arr[index+1]){
                swap(arr[index], arr[index+1]); // call swap function
                  display( arr, size);          // display array after each pass the sort
            }
        }
    }
}
void swap (int &x, int &y){       // swap two elemnts of the array
    int temp = x;
    x = y;
    y = temp;
}
void selectionSort(int arr[], int size){        // selection sort an int array in ascending order
    int minIndex, minValue;
    for (int start = 0; start < size-1; start++){   // two for-loop to select smallest value
        minIndex = start;                           // and place it in the right location
        minValue = arr[start];
        for(int index = start + 1; index < size; index++){
        if(arr[index] < minValue){
            minValue = arr[index];
            minIndex = index;
            }
        }
        swap (arr[minIndex], arr[start]); // call swap function
        display(arr, size);               // display array after each pass the sort
    }
}
