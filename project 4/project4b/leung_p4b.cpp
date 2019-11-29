//
//  leung_p4b.cpp
//  project4b
//  This program prints the values of all needed banknotes
//  in a row after the user input the value
//  Created by Chadwick Leung on 12/1/18.
//  Copyright © 2018 Chadwick Leung. All rights reserved.
//

#include <iostream>

using namespace std;

//function prototype
void calculation(int);

int main()
{
    int money;

    cout << "Please enter the amount of money: ";
    cin  >> money;
    
    calculation(money);
    
    return 0;
}

//Function calculates the number of each banknote needed
void calculation(int moneyentered)
//Pre: input the money required
//Post: print out the minimal number of bank notes needed
//      to deliver any amount of money to the client
{
    int banknotes[] = {50, 20, 10, 5, 1};
    
    int issued[] = {0, 0, 0, 0, 0};
    
    cout << "The minimal number of banknotes needed to deliver any amount "
         << "of money to the client is "<<endl;
    
    for (int count=0; count<5; count++)
    {
        issued[count] = moneyentered/banknotes[count];
        
        moneyentered -= issued[count]*banknotes[count];
        
        for (int needed=0; needed<issued[count]; needed++)
        {
            cout << banknotes[count]<< " ";
        }
    }
}
