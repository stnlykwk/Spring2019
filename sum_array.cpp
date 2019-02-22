/*
* sum_array.cpp
*
* Description: This program sums up an array...
* 
*
* Author: Stanley Kwok
* Creation date: Jan 17, 2019
*/ 

#include <iostream>
using namespace std;
 
// function declaration
int sumArray(int arr[], int arrSize);
 
int main () {

   	// local variable declaration:
	int sum;
   	int *arr = NULL;
   	int arrSize = 0;
 
	// get total number of values to be summed
	cout << "Enter the total number of values to be summed: ";
	cin >> arrSize;
	
	// Create a dynamically allocated (heap-allocated) array
	arr = new int[arrSize];
	
	// fill in array with input from user
	if ( arr != NULL ) {
		for(int i = 0; i < arrSize; i++) {
			cout << endl << "Please enter an integer: ";
			cin >> arr[i];
		}
	} else {
		return -1;
	}
	
    // calling a function to get sum.
    sum = sumArray(arr, arrSize);
    cout << "Sum is : " << sum << endl;
 	
 	// delete the dynamically-allocated array
 	delete [] arr;
 	
    return sum;
}
 
// function returning the sum of an array
int sumArray(int arr[], int arrSize) {

    // local variable declaration
   	int result;
 
   	for(int i = 0; i < arrSize; i++) {
   		result += arr[i];
  	}
 
   	return result; 
}
