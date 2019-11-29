//
//  pc2_leung.cpp
//  final question 43, 2D array Operation program, SID: 0475
//
//  This program would operate the initialize 2D array
//
//  Created by Chadwick Leung on 12/19/18.
//  Copyright © 2018 Chadwick Leung. All rights reserved.
//******************       this line is 70 characters long **********


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//global variables
const int row=4, col=5;

//function prorotypes
void showArray(int [][col]);
void getRandomNumberInput(int [][col]);
void getTotal(int [][col]);
void getAverage(int [][col]);
void getRowTotal(int [][col], /*in*/ int);
void getHighestInColumn(int [][col], /*in*/ int);


int main()
{
    int first_array[row][col] = {{2,3,4,1,6},{5,6,7,8,4},{4,5,6,3,8},
                                 {3,3,4,4,5}};
    int second_array[row][col];
    
    cout << "Showing the first_array" <<endl;
    showArray(first_array);
    cout << endl;
    
    cout << "Showing the random array" <<endl;
    getRandomNumberInput(second_array);
    cout << endl;
    
    cout << "Showing the total of the first_array" <<endl;
    getTotal(first_array);
    cout << endl;
    
    cout << "Showing the average of the first_array" <<endl;
    getAverage(first_array);
    cout << endl;
    
    cout << "Showing the row total of the first row of the first_array" <<endl;
    getRowTotal(first_array, 0);
    cout << endl;
    
    cout << "Showing the highest value of the first column of the first_array" <<endl;
    getHighestInColumn(first_array,0);
    cout << endl;


    return 0;
}

void showArray(int array[][col])
// pre: array assigned
//post: display the array
{
    for (int rcount=0; rcount<row; rcount++)
    {
        for (int ccount=0; ccount<col; ccount++)
        {
            cout << array[rcount][ccount];
            cout << " ";
        }
        cout << endl;
    }
}

void getRandomNumberInput(int array[][col])
// pre: array assigned
//post: display the random array
{
    srand(time(NULL));
    
    for (int rcount=0; rcount<row; rcount++)
    {
        for (int ccount=0; ccount<col; ccount++)
        {
            array[rcount][ccount] = 2+rand()%((9+1)-2);
        }
    }
    for (int rcount=0; rcount<row; rcount++)
    {
        for (int ccount=0; ccount<col; ccount++)
        {
            cout << array[rcount][ccount];
            cout << " ";
        }
        cout << endl;
    }
    
}

void getTotal(int array[][col])
// pre: array assigned
//post: show the total of all values
{
    int sum=0;
    
    for (int rcount=0; rcount<row; rcount++)
    {
        for (int ccount=0; ccount<col; ccount++)
        {
            sum = sum + array[rcount][ccount];
        }
    }
    cout << "The sum of all the values in the array is " << sum;
    cout << endl;
   
}

void getAverage(int array[][col])
// pre: array assigned
//post: show the average of all values
{
    int sum=0, count=0, average=0;
    
    for (int rcount=0; rcount<row; rcount++)
    {
        for (int ccount=0; ccount<col; ccount++)
        {
            sum = sum + array[rcount][ccount];
            count++;
        }
    }
    
    average = sum/count;
    cout << "The average of all the values in the array is "<< average;
    cout <<endl;
}

void getRowTotal(int array[][col], int rowselected)
// pre: array assigned
//post: show the row total of the selected row
{
    int rowsum=0;
    
    for (int ccount=0; ccount<col; ccount++)
    {
        rowsum = rowsum + array[rowselected][ccount];
    }
    cout << "The row total of row " << rowselected+1 << " is "<< rowsum;
    cout <<endl;
}

void getHighestInColumn(int array[][col], int columnselected)
// pre: array assigned
//post: show the highest of the column selected
{
    int colhighest=0;
    
    for (int rcount=0; rcount<row; rcount++)
    {
        if (array[rcount][columnselected]>colhighest)
        {
            colhighest = array[rcount][columnselected];
        }
    }
    cout << "The highest value in column " << columnselected+1 << " is " << colhighest;
}
