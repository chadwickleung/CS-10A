//
//  leung_p5.cpp
//  project 5
//  This program displays and shows the required ratings for the movies rated
//  by 4 reviewers.
//  Created by Chadwick Leung on 12/11/18.
//  Copyright © 2018 Chadwick Leung. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

//global constants
const int NUM_REVIEWERS = 4;   //Number of rows in reviews array
const int NUM_MOVIES = 6;      //Number of columns in reviews array

//function prototypes
void initialRatings(int [][NUM_MOVIES]);
void displayRatings(int [][NUM_MOVIES]);
void showAverageRatings(int [][NUM_MOVIES]);
void getNewRatings(int [][NUM_MOVIES]);
void showReviewersHighestRating(int [][NUM_MOVIES]);
void showLowestMovie(int [][NUM_MOVIES]);


int main()
{
    int someArray[NUM_REVIEWERS][NUM_MOVIES] = {0};
    int choice;
    
    //initializing the orginal data
    initialRatings(someArray);
    
    do
    {
        cout << "-----------------------------------------------------------------" <<endl;
        cout << "2-D ARRAY PROCESSING MENU OPTIONS" <<endl;
        cout << "-----------------------------------------------------------------" <<endl;
        cout << "1. Display current movie ratings." <<endl;
        cout << "2. Show the average rating for each movie." <<endl;
        cout << "3. Show a reviewers highesr rated movie. (Enter reviewer# 1-4)" <<endl;
        cout << "4. Show a movies lowest rating. (Enter movie# 100-105)" <<endl;
        cout << "5. Enter new ratings (1-5) for movie# 100-105 for four reviewers." <<endl;
        cout << "6. Quit program." <<endl;
        cout <<endl;
        cout << "Enter your choice: ";
        cin  >> choice;
        
        //input validation
        while (choice<1 || choice>6)
        {
            cout << "Invalid choice. Please retype: ";
            cin  >> choice;
        }
        cout << endl;
        
        //switch function depends on the choice that the user made
        switch (choice)
        {
            case 1: displayRatings(someArray);
                break;
            case 2: displayRatings(someArray);
                    showAverageRatings(someArray);
                break;
            case 3: displayRatings(someArray);
                    showReviewersHighestRating(someArray);
                break;
            case 4: displayRatings(someArray);
                    showLowestMovie(someArray);
                break;
            case 5: getNewRatings(someArray);
                break;
            case 6: return 0;
                break;
           
        }
    }
    while (choice != 6);
   
    return 0;
}

void initialRatings(int someArray[][NUM_MOVIES])
//pre: pre-input data
//post: put the pre-input data into the array
{
    //original data
    int initialArray[NUM_REVIEWERS][NUM_MOVIES] = {{3,1,5,2,1,5}, {4,2,1,4,2,4}, {3,1,2,4,4,1}, {5,1,4,2,4,2}};
    
    for (int rcount=0; rcount<NUM_REVIEWERS; rcount++)
    {
        for (int ccount=0; ccount<NUM_MOVIES; ccount++)
        {
            someArray[rcount][ccount] = initialArray[rcount][ccount];
        }
    }

}

void displayRatings(int someArray[][NUM_MOVIES])
//pre: an array already exist in the someArray
//post: display the array element by element
{
    cout << "********************* MOVIE RATINGS *********************"<<endl;
    cout << "REVIEWER|  MV#100  MV#101  MV#102  MV#103  MV#104  MV#105"<<endl;
    cout << "*********************************************************"<<endl;
    for (int rcount=0; rcount<NUM_REVIEWERS; rcount++)
    {
            cout << "   #"<<rcount+1<< "         ";
        for (int ccount=0; ccount<NUM_MOVIES; ccount++)
        {
            
            cout << someArray[rcount][ccount];
            cout << "       ";
        }
        cout << endl;
    }
    cout <<endl;
}

void showAverageRatings(int someArray[][NUM_MOVIES])
//pre: an array assigned to the array someArray
//post: display the average rating for each movie
{
    cout << "*********************************************************"<<endl;
    cout << "Average Rating for each movie:"<<endl;
    for (int ccount=0; ccount<NUM_MOVIES; ccount++)
    {
        double sum=0, average=0, count=0;
        
        for (int rcount=0; rcount<NUM_REVIEWERS; rcount++)
        {
            sum += someArray[rcount][ccount];
            count++;
        }
        
        average = sum/count;
        
        cout << "Movie#10"<<ccount<<": "<< average <<endl;
    }
   
}

void getNewRatings(int newarray[][NUM_MOVIES])
//pre: let user input the ratings for the movies
//post: save the use-input ratings in the array someArray
{
    int input;
    for (int rcount=0; rcount<NUM_REVIEWERS; rcount++)
    {
        cout << "*********************************************************"<<endl;
        cout << "REVIEWER#"<< rcount+1<<":"<<endl;
        cout << "*********************************************************"<<endl;
        for (int ccount=0; ccount<NUM_MOVIES; ccount++)
        {
            cout << "Enter rating (1-5) for movie#10"<<ccount<<": ";
            cin  >> input;
            
            //input validation
            while (input<1 || input>5)
            {
                cout << "Invalid rating. It must be from 1-5."<<endl;
                cout << "Enter rating (1-5) for movie#10"<<ccount<<": ";
                cin >> input;
            }
            newarray[rcount][ccount] = input;
        }
    }
}

void showReviewersHighestRating(int someArray[][NUM_MOVIES])
//pre: an array assigned to the array someArray
//post: show the highest rating movie by the selected reviewer
{
    int choice, index, max=0;
    
    cout << "*********************************************************"<<endl;
    cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest: ";
    cin  >> choice;
    
    //input validation
    while (choice<1 || choice>4)
    {
        cout << "That is an invalid number."<<endl;
        cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest: ";
        cin  >> choice;
    }
    
    
    index = choice-1;
    
    for (int ccount=0; ccount<NUM_MOVIES; ccount++)
    {
        if (someArray[index][ccount]>=max)
        {
            max = someArray[index][ccount];
        }
    }
    
    cout << "Reviewer#"<<choice<< " rated the following movies as the highest:"<<endl;
    for (int ccount=0; ccount<NUM_MOVIES; ccount++)
    {
        if (someArray[index][ccount]==max)
        {
            cout << "Movie#10"<<ccount<<endl;
        }
    }
  
}

void showLowestMovie(int someArray[][NUM_MOVIES])
//pre: an array assigned to the array someArray
//post: display the lowest rating of the selected movie
{
    int choice, index, low=5;
    
    cout << "*********************************************************"<<endl;
    cout << "Enter a movie number (100-105), to find the lowest rating: ";
    cin  >> choice;
    
    //input validation
    while (choice<100 || choice>105)
    {
        cout << "That is an invalid number."<<endl;
        cout << "Enter a movie number (100-105), to find the lowest rating: ";
        cin  >> choice;
    }
    
    index = choice-100;
    
    for (int rcount=0; rcount<NUM_REVIEWERS; rcount++)
    {
        if (someArray[rcount][index]<=low)
        {
            low = someArray[rcount][index];
        }
    }
    cout << "Movie#"<<choice<< " lowest rating is "<<low<<"."<<endl;
    
}
