/*
 * sort_all.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: Aaron Nettles
 */

#include <iostream>
#include <ctime> //for random call (not required)
#include <stdlib.h> // for random call (required)
#include <algorithm>
#include <vector>

using namespace std;

class Sort{

public:

	void fill_array(int array[], int size);


	void bubble_sort(int arr[], int size);


	void selection_sort(int arr[], int size);
	// insertion sort
    void insertion(int arr[], int size);

    // merge sort
    void merge(int arr[],int arr2[],int arr3[]);

    // quick sort
    void quick(int arr[], int size);

    void print_function(int arr[], int size);

};

int main()
{
	//create size for array
	int size = 100;
	//create the actual array
	int arr[size];

//function calls
	Sort obj;
obj.fill_array(arr, size);

obj.print_function(arr, size);

obj.bubble_sort(arr, size);

obj.print_function(arr, size);

obj.fill_array(arr, size);

obj.selection_sort(arr, size);

obj.print_function(arr, size);




	return 0;
}
//add random elements to the array created
void Sort::fill_array(int array[], int size){

//fill the array
	for(int i=0; i<size; i++)
		{
			array[i] = rand()%100 + 1;
		}
}
//bubble sort function
void Sort:: bubble_sort(int arr[], int size){

	int i, j, start = 1; //start is set to 1 for the pass
	int temp;	//variable; temporary

	for(i = 1; i <= size && start; i++)
	{
		start = 0;
		for (j = 0; j < size; j++){
			if (arr[j+1] > arr[j]) //ascending order changes
			{
				temp = arr[j];	//swap
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				start = 1;	//swap happened
			}
		}
	}
}
//selection sort function
void Sort:: selection_sort(int arr[], int size){

	int i, j, first, temp;

	for (i = size -1; i > 0; i--)
	{
		first = 0; //initialize for first element
		for (j = 1; j <= i; j++){ //locate the smallest between 1 & i

			if(arr[j] < arr[first])
			first = j;
		}
		temp = arr[first]; //swap smallest with element found in i position
		arr[first] = arr[i];
		arr[i] = temp;

	}
}
//print the array
void Sort:: print_function(int arr[], int size){
//loop the array to print out each element
	for (int i=1; i < size; i++){

	   cout<<arr[i]<<" ";
	}
	cout<<"\n"<<endl;
}

void Sort:: merge(int arrayA[], int arrayB[], int arrayC[])
{
     int indexA = 0;     // initialize variables for the subscripts
     int indexB = 0;
     int indexC = 0;

     while((indexA < arrayA.length( )) && (indexB < arrayB.length( ))
     {
          if (arrayA[indexA] < arrayB[indexB])
          {
                 arrayC[indexC] = arrayA[indexA];
                 indexA++;    //increment A
          }
         else
         {
                 arrayC[indexC] = arrayB[indexB];
                 indexB++;      //increment B
         }
        indexC++;      //move to the next position in the new array
     }
     // Move remaining elements to end of new array when one merging array is empty
     while (indexA < arrayA.length( ))
     {
           arrayC[indexC] = arrayA[indexA];
           indexA++;
           indexC++;
     }
     while (indexB < arrayB.length( ))
     {
           arrayC[indexC] = arrayB[indexB];
           indexB++;
           indexC++;
     }
     return;
}

void Sort::insertion(int arr[], int size)
{
     int i, j, key, sizeLength = size.length( );
     for(j = 1; j < sizeLength; j++)    // Start with 1 (not 0)
    {
           key = size[j];
           for(i = j - 1; (i >= 0) && (size[i] < key); i--)   // Smaller values move up
          {
                 size[i+1] = size[i];
          }
         size[i+1] = key;    //Put key into its proper location
     }
     return;
}
