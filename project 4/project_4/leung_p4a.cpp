//
//  leung_p4a.cpp
//  project_4
//  This program manipulates some simple arrays, such as
//  moved the cell to the right by one and reverse it orders
//  Created by Chadwick Leung on 12/1/18.
//  Copyright © 2018 Chadwick Leung. All rights reserved.
//

#include <iostream>

using namespace std;

//Function prototypes
void showArray(int [], int);
void moveRight(int [], int, int []);
void reverse(int [], int, int[]);


int main()
{
    //1D arrays declared with initialization lists
    int array1[7] = {4, 7, 2, 8, 1, 3, 0};
    int array2[7] = {0, 0, 0, 0, 0, 0, 0};
    
    cout <<"The original order:"<<endl;
    showArray(array1,7);
    
    moveRight(array1,7,array2);
    cout <<"The order after moving to the right by one:"
         <<endl;
    showArray(array2,7);
    
    reverse(array1, 7, array2);
    cout <<"The order which is reversed:"<<endl;
    showArray(array2,7);
    
    return 0;
    
}

//Function displays the elements of an integer array
void showArray(int somearray[], int size)
//Pre: elements of array1 being input
//Post: show the elements of the array
{
    for (int count=0; count<size; count++)
    {
        cout << somearray[count] << " ";
    }
    cout << endl;
}

//Function that move cells to the right, while last one goes first
void moveRight(int somearray[], int size, int resultarray[])
//Pre: array1 and the size
// Post: array2 that is moved to the right
{
    resultarray[0] = somearray[6];
    
    for (int count=1; count<(size); count++)
    {
        resultarray[count] = somearray[count-1];
    }
}

//Function that reverse the cell order
void reverse(int somearray[], int size, int resultarray[])
//Pre: array1 and the size
//Post: array2 which is reversed, last one goes first...
{
    for (int count=0; count<size; count++)
    {
        resultarray[count] = somearray[6-count];
    }
}
