//
//  pc1_leung.cpp
//  final question 42, lowest score drop, SID: 0475
//
//  This program would calculate the average of a group of test
//  scores, where the lowest score in the group is dropped.
//
//  Created by Chadwick Leung on 12/19/18.
//  Copyright © 2018 Chadwick Leung. All rights reserved.
//******************       this line is 70 characters long **********

#include <iostream>

using namespace std;

//funtion prototypes
void getScore(/*out*/ int &);

void calcAverage(/*in*/ int, /*in*/ int, /*in*/ int,
                 /*in*/ int, /*in*/ int);

int findLowest(/*in*/ int, /*in*/ int, /*in*/ int,
               /*in*/ int, /*in*/ int);

int main()

{
    int int1, int2, int3, int4, int5;
    
    //get the 5 scores
    getScore(int1);
    getScore(int2);
    getScore(int3);
    getScore(int4);
    getScore(int5);
    
    //calculate the average of the top 4 scores
    calcAverage(int1, int2, int3, int4, int5);
    
    return 0;
}

void getScore(/*out*/ int &input)
// pre: the score is input by the user
//post: the score entered is saved as a reference variable and is
//      available in main
{
    //prompt the user to enter a test score
    cout << "Enter a test score (0-100): ";
    cin  >> input;
    
    //input validation
    while (input<0 || input>100)
    {
        cout << "Invalid input. Enter a test score (0-100): ";
        cin  >> input;
    }
}

void calcAverage(/*in*/ int input1, /*in*/ int input2, /*in*/ int input3,
                 /*in*/ int input4, /*in*/ int input5)
// pre: the 5 scores are input by the user
//post: drop the lowest score and calculate the average among the top
//      4 scores
{
    int lowest, sum, average;
    
    lowest = findLowest(input1, input2, input3, input4, input5);
    
    sum = input1+input2+input3+input4+input5-lowest;
    
    average = sum/4;
    
    cout << "The lowest score dropped is "<< lowest<<endl;
    cout << "The average of the four highest scores is "<< average;
    
}

int findLowest(/*in*/ int input1, /*in*/ int input2, /*in*/ int input3,
               /*in*/ int input4, /*in*/ int input5)
// pre: the 5 scores are input by the user
//post: drop the lowest score mong the 5 scores and return its value
{
    int lowest=0;
    
    lowest = input1;
    
    if (input2<lowest)
        lowest = input2;
    
    if (input3<lowest)
        lowest = input3;
    
    if (input4<lowest)
        lowest = input4;
    
    if (input5<lowest)
        lowest = input5;
    
    return lowest;
    
}
