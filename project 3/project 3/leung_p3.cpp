//
//  leung_p3.cpp
//  project 3
//
//  Created by Chadwick Leung on 11/26/18.
//  Copyright © 2018 Chadwick Leung. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function prototypes
void menu(int &);

void option1(int [], int);
void option2(int [], int);

void option3(int [], int);
void option4(int [], int);
void option5(int [], int);
void option6(int [], int);
void option7(int [], int);


int main()
{
    // declaring variables
    int options;
    
    const int SIZE=10;
    int scores[SIZE]={0,0,0,0,0,0,0,0,0,0};
    
    do
    {
        // display menu
        menu(options);
        switch (options)
        {
            case 1: option1(scores,SIZE);
                break;
           
            case 2: option2(scores,SIZE);
                break;
                
            case 3: option3(scores,SIZE);
                break;
                
            case 4: option4(scores,SIZE);
                break;
                
            case 5: option5(scores,SIZE);
                break;
                
            case 6: option6(scores,SIZE);
                break;
                
            case 7: option7(scores,SIZE);
                break;
                
            case 8:
                return 0;
        }
    }
    while (options>0 && options<8);
    
    


    
    return 0;
}
          
// This function is to bring up the menu
void menu(int &options)
// pre: this function asks for the option
// post: the option would be saved
{
    cout <<"-------------------------------------------------\n"
         <<"1-D ARRAY PROCESSING MENU OPTIONS\n"
         <<"-------------------------------------------------\n"
         <<"1. Read in 10 scores from user.\n"
         <<"2. Read in 10 scores from the file, scores.txt.\n"
         <<"3. Print all scores.\n"
         <<"4. Print the highest score.\n"
         <<"5. Print the lowest score.\n"
         <<"6. Print the average score.\n"
         <<"7. Print one score (give its entry number)\n"
         <<"8. Quit program\n"
         <<endl;
    
    cout <<"Enter your choice: ";
    cin >> options;

    while (options<=0 || options>8)
    {
        cout <<"Incorrect! Enter your choice again: ";
        cin >>options;
    }
    cout <<endl;

}

// This function allows user to input the array elements
void option1(int scores[], int SIZE)
// pre: this function allows users to enter the array elements
// post: the array will be saved for later usage
{
    int order[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    for (int count=0; count<SIZE; count++)
    {
        cout <<"Enter score #"<< order[count]<<": ";
        cin >> scores[count];
        while (scores[count]<0 || scores[count]>100)
        {
            cout <<"Invalid input! Please enter again.\n";
            cout <<"Enter score #"<< order[count]<<": ";
            cin >> scores[count];
        }
    }
}

// This function reads the array elements of scores.txt to scores
void option2(int scores[], int SIZE)
// pre: this function would ask the user for the filename
// post: the file would be passed to the array scores
{
    ifstream inputFile;
    
    string filename;
    
    cout <<"Please enter filename: ";
    cin  >>filename;
    
    inputFile.open(filename);
    
    // file validation
    while (!inputFile)
    {
        // displaying the error notification
        cout <<"File not found.\n";
        inputFile.close();
        inputFile.clear();
        
        // allow user to enter the filename again
        cout <<"Please enter a correct file name: ";
        cin >> filename;
        inputFile.open(filename);
    }
    
    if (inputFile)
    {
        for (int count=0; count<SIZE; count++)
        {
            inputFile>>scores[count];
        }
        
        cout <<"File has successfully opened and 10 scores have been read and stored.\n"
             <<"Please select the print all scores menu option to view the scores\n";
    }
    
    inputFile.close();
}

// This function would print the 10 scores in the array scores
void option3(int scores[], int SIZE)
// pre: the array has been assigned
// post: the array is displayed element by element
{
    int orders[]={1,2,3,4,5,6,7,8,9,10};
    for (int count=0; count<SIZE; count++)
    {
        cout <<"score #"<< orders[count] <<": "<<scores[count]<<endl;
    }
    cout <<endl;
}

// This function would display the highest score in the respective array
void option4(int scores[], int SIZE)
{
    int maxValue=0;
    
    for (int count=0; count<SIZE; count++)
    {
        if (scores[count]>=maxValue)
        {
            maxValue = scores[count];
        }
    }
    
    cout <<"The highest score is "<<maxValue <<endl;
}

// This function would display the lowest score in the respective array
void option5(int scores[], int SIZE)
// pre: the array has been assigned
// post: the highest score will be displayed
{
    int minValue=101;
    
    for (int count=0; count<SIZE; count++)
    {
        if (scores[count]<=minValue)
        {
            minValue = scores[count];
        }
    }
    
    cout <<"The lowest score is "<<minValue<<endl;
}

// This function produces the average value of the scores
void option6(int scores[], int SIZE)
// pre: the array has been assigned
// post: the lowest score will be displayed
{
    double sum=0;
    double average;
    
    for (int count=0; count<SIZE; count++)
    {
        sum += scores[count];
    }
    
    average = sum/SIZE;
    
    cout <<"The average score is "<<average <<endl;
}

// This function displays the score that is required by the user
void option7(int scores[], int SIZE)
// pre: the array has been assigned, and ask for the entry number
// post: the score of the respective entry will be displayed, and also the score statistic
{
    int choice, higher=0;
    
    cout <<"Please enter entry or row # of score you want: ";
    cin >>choice;
    
    cout <<"Entry #"<<choice <<" score: "<<scores[choice-1]<< endl;
    
    for (int count=0; count<SIZE; count++)
    {
        if (scores[count]>scores[choice-1])
            higher++;
    }
    
    cout <<"Score statistics: "<<higher<<" higher"<<endl;
    
}
