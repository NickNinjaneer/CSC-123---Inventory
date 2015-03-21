//
//  main.cpp
//  Inventory
//
//  Created by Nick Williams on 10/25/14.
//  Copyright (c) 2014 Ninjaneer. All rights reserved.
//
//  This Program Manages an Inventory using a Vector of Structs. 

#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <string>
#include <iomanip>
#include <vector> 
#include <algorithm> 


using namespace std;

struct inventoryItem {
    string upc;
    string description;
    double price = 0;
    int qty = 0;
};

vector<inventoryItem> product;

void showMenu(); //Displays Main Menu with Choices
void promptInvalid(); //Tells User an Invalid Entry has been Submitted
void addToInventory(vector<inventoryItem> &); //Adds User Input to Vector of Structs
void outputInventory(vector<inventoryItem> &); //Displays Entire Inventory
void searchInventory(vector<inventoryItem> &); //Searches for UPC with User Input
void calculateValue(vector<inventoryItem> &); //Calculates Dollar Value and Outputs Result

int main(int argc, const char * argv[])
{
    int selection = 0;
    
    do
    {
        showMenu();
        
        cin >> selection;
        
        switch (selection)
        {
            case 1: //Add an Item
                addToInventory(product);
                break;
            case 2: //Search
                searchInventory(product);
                break;
            case 3: //List Contents
                outputInventory(product);
                break;
            case 4: //Show Dollar Value
                calculateValue(product);
                break;
            case 0: //Exit
                cout << "Goodbye\n\n\n";
                break;
            default:
                promptInvalid();
        }
    } while (selection != 0);
    
    return 0;
}

void showMenu()
{
    cout << "======================================\n";
    cout << "MAIN MENU\n";
    cout << "Please Make a Selection by Typing the Number\n";
    cout << "that Corresponds to your Desired Operation\n" << endl;
    cout << "1: Add an Item to Inventory Memory\n";
    cout << "2: Search Inventory Memory for an Item\n";
    cout << "3: List Contents of Inventory Memory\n";
    cout << "4: Display Dollar Value from Inventory Memory\n";
    cout << "0: EXIT" << endl << endl;
    cout << "Items in Inventory: " << product.size() << endl << endl;
    cout << "Selection: \n\n";
}

void promptInvalid()
{
    cout << "You have provided an invalid input\n";
    cout << "Please Try Again\n" << endl;
}

void addToInventory(vector<inventoryItem> &product)
{
    char confirm[5] = {"Y"};

    do
    {
        cout << "Add another Item? (Y or N)\n";
        
        cin >> confirm;
        
        if ((toupper(confirm[0]) != 'N'))
        {
            product.push_back(inventoryItem());
            
            cout << "Enter the UPC: ";
            cin.ignore();
            getline(cin, product[product.size() - 1].upc);
            
            cout << "Enter the Description: ";
            getline(cin, product[product.size() - 1].description);
            
            cout << "Enter the Price: ";
            cin >> product[product.size() - 1].price;
            
            cout << "Enter the Quantity: ";
            cin >> product[product.size() - 1].qty;
        }
    }while (toupper(confirm[0]) != 'N');
    
}

void outputInventory(vector<inventoryItem> &product)
{
    string enter;
    
    cout << "Inventory List: \n";
    cout << setw(8);
    cout << left << "Qty";
    cout << setw(12);
    cout << left << "UPC";
    cout << setw(20);
    cout << left << "Description";
    cout << setw(10);
    cout << right << "Price" << endl;
    
    for (int i = 0; i < product.size(); i++)
    {
        cout << setw(8);
        cout << left << product[i].qty;
        cout << setw(12);
        cout << left << product[i].upc;
        cout << setw(20);
        cout << left << product[i].description;
        cout << setw(10);
        cout << right << product[i].price << endl;
    }
    
    cout << "\nPress Enter to Return to Menu\n\n";
    cin.get();
    cin.ignore();
}

void searchInventory(vector<inventoryItem> &product)
{
    string search = "";
    string result = "Item Not Found";
    
    cout << "Enter the UPC for which to Search: ";
    cin >> search;
    
    for (int i = 0; i < product.size(); i++)
    {
        if (search == product[i].upc)
        {
            result = "Item Found: \n";
            cout << result << endl;
            cout << setw(8);
            cout << left << "Qty";
            cout << setw(12);
            cout << left << "UPC";
            cout << setw(20);
            cout << left << "Description";
            cout << setw(10);
            cout << right << "Price" << endl;
            
            cout << setw(8);
            cout << left << product[i].qty;
            cout << setw(12);
            cout << left << product[i].upc;
            cout << setw(20);
            cout << left << product[i].description;
            cout << setw(10);
            cout << right << product[i].price << endl;
        }
    }
    
    if (result == "Item Not Found")
    {
        cout << result << endl;
    }
    
    cout << "\nPress Enter to Return to Menu\n\n";
    cin.get();
    cin.ignore();
}

void calculateValue(vector<inventoryItem> &product)
{
    double total = 0.00;
    
    for (int i = 0; i < product.size(); i++)
    {
        total += (product[i].price * product[i].qty);
    }
    
    cout << "The Total Value of Inventory is: $";
    cout.precision(2);
    cout << fixed << total << endl;
    
    cout << "\nPress Enter to Return to Menu\n\n";
    cin.get();
    cin.ignore();
}