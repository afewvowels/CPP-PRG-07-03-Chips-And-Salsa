//
//  main.cpp
//  PRG-7-3-Chips-And-Salsa
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that lets a maker of chips and salsa keep track of sales for five different
//  types of salsa: mild, medium, sweet, hot, and zesty. The program should use two
//  parallel 5-element arrays: an array of strings that holds the five salsa names, and an
//  array of integers that holds the number of jars sold during the past month for each salsa
//  type. The salsa names should be stored using an initializtion list at the time the name
//  array is created. The program should prompt the user to enter the number of jars sold
//  for each type. Once this sales data has been entered, the program should produce a
//  report that displays sales for each salsa type, total sales, and the names of the highest
//  selling and lowest selling products.
//
//  Input Validation: Do not accept negative numbers for number of jars sold.

#include <iostream>
#include <string>

using namespace std;

void enterSales(int, int[], const string[]);
void calculateHighest(int, const int[], const string[], int &);
void calculateLowest(int, const int[], const string[], int &);
void calculateTotalSales(int, const int[], int &);


int main()
{
    const int INT_SALSA_TYPES = 5;
    
    int intArraySalsaSales[INT_SALSA_TYPES];
    
    int intTotalSales;
    
    int salsaLowest,
           salsaHighest;
    string strArraySalsaNames[INT_SALSA_TYPES] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
    
    enterSales(INT_SALSA_TYPES, intArraySalsaSales, strArraySalsaNames);
    
    calculateHighest(INT_SALSA_TYPES, intArraySalsaSales, strArraySalsaNames, salsaHighest);
    calculateLowest(INT_SALSA_TYPES, intArraySalsaSales, strArraySalsaNames, salsaLowest);
    
    calculateTotalSales(INT_SALSA_TYPES, intArraySalsaSales, intTotalSales);
    
    for(int i = 0 ; i < INT_SALSA_TYPES ; i++)
    {
        cout << "Sold " << intArraySalsaSales[i] << " jars of " << strArraySalsaNames[i] << " salsa" << endl;
    }
    
    cout << "Total jars sold: " << intTotalSales << endl;
    cout << "Salsa highest: " << salsaHighest << endl;
    cout << "Salsa lowest: " << salsaLowest << endl;
    
    return 0;
}

void enterSales(int INT_SALSA_TYPES, int intArraySalsaSales[], const string strArraySalsaNames[])
{
    int intSalsaSalesTemp;
    
    for(int i = 0 ; i < INT_SALSA_TYPES ; i++)
    {
        cout << "Please enter the total jars sold for salsa type " << strArraySalsaNames[i] << ": ";
        cin >> intSalsaSalesTemp;
        while(!cin || intSalsaSalesTemp < 0.0f || intSalsaSalesTemp > 10000.0f)
        {
            cout << "Please enter a value between 0 and 10,000: ";
            cin.clear();
            cin.ignore();
            cin >> intSalsaSalesTemp;
            cout << endl;
        }
        
        intArraySalsaSales[i] = intSalsaSalesTemp;
    }
}

void calculateHighest(int INT_SALSA_TYPES, const int intArraySalsaSales[], const string strArraySalsaNames[], int &refCount)
{
    int intTempCounter;
    
    intTempCounter = 0;
    
    for(int i = 0 ; i < INT_SALSA_TYPES ; i++)
    {
        if(intArraySalsaSales[i] > intTempCounter)
        {
            intTempCounter = intArraySalsaSales[i];
        }
    }
    
    refCount = intTempCounter;
}

void calculateLowest(int INT_SALSA_TYPES, const int intArraySalsaSales[], const string strArraySalsaNames[], int &refCount)
{
    int intTempCounter;
    
    intTempCounter = 10000;
    
    for(int i = 0 ; i < INT_SALSA_TYPES ; i++)
    {
        if(intArraySalsaSales[i] < intTempCounter)
        {
            intTempCounter = intArraySalsaSales[i];
        }
    }
    
    refCount = intTempCounter;
}

void calculateTotalSales(int INT_SALSA_TYPES, const int intArraySalsaSales[], int &refTotalSales)
{
    refTotalSales = 0; // Initialize accumulator
    
    for(int i = 0 ; i < INT_SALSA_TYPES ; i++)
    {
        refTotalSales += intArraySalsaSales[i];
    }
}

