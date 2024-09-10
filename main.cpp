#include <iostream>
#include <fstream>
#include "array_operations.h"

using namespace std;

int main() {
    int data[MAX_SIZE];
    int count = 0;

    readDataFromFile("/Users/ceonjones/Downloads/ALL FILES/SCHOOL/Data Structures CS 303/Assignment 1/A1input.txt", data, count);
    
    cout << "Data read from file:" << endl;
    displayData(data, count);

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Find integer" << endl;
        cout << "2. Modify integer" << endl;
        cout << "3. Add integer" << endl;
        cout << "4. Remove integer" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice:";
        int choice;
        cin >> choice;

        if (choice == 1) {
            findInteger(data, count);
        } else if (choice == 2) {
            modifyInteger(data, count);
        } else if (choice == 3) {
            addInteger(data, count);
        } else if (choice == 4) {
            removeInteger(data, count);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice" << endl;
            }
        } 
       
    return 0;
}


