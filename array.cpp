#include <iostream>
#include "parent.hpp"

using namespace std;

/*
 * Source: https://www.geeksforgeeks.org/array-rotation/
 */

/*
 * Function to left Rotate arr[] of size n by 1
 */
void leftRemovebyOne(Parent **arr, int n) { 
    int i;
    for (i = 0; i < n-1; i++)  arr[i] = arr[i + 1];
    arr[i] = NULL; 
}
  
/*
 * Function to left rotate arr[] of size n by d
 */
void leftRotate(Parent **arr, int d, int n) { 
    for (int i = 0; i < d; i++) 
        leftRemovebyOne(arr, n); 
}

/* 
 * Function to print arr[] of size n 
 */
void printArray (Parent **arr, int n) {
    for (int i = 0; i < n; i++)
        if (arr[i]) arr[i]->print();
}