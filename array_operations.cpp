#include "array_operations.h"
#include <fstream>
#include <iostream>

using namespace std;

void readDataFromFile(const string& filename, int data[], int& count) {
    ifstream in(filename);

    if (!in.is_open()) {
        cout << "Error: File not found" << endl;
        return;
    }

    count = 0;
    while (!in.eof()) {
        in >> data[count];
        count++;
    }

    in.close();
}

void displayData(const int data[], int count) {
    cout << "Data read from file:" << endl;
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void findInteger(const int data[], int count) {
    cout << "Enter an integer to search for:";
    int search;
    cin >> search;
    bool found = false;
        for (int i = 0; i < count; i++) {
            if (data[i] == search) {
                cout << "Found " << search << " at index " << i << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Could not find " << search << " in array" << endl;
        }
}

void modifyInteger(int data[], int count) {
    try
    {
       int index, newValue;
       cout << "Enter an index to modify: ";
       cin >> index;

       if (index < 0 || index >= count) {
            throw out_of_range ("Index out of bounds");
        }
        int oldValue = data[index];
        cout << "Enter a new value: ";
        cin >> newValue;

        data[index] = newValue;

        cout << "Old value " << oldValue << " is modified to: " << newValue << endl;
    
    } catch(const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    } catch(const exception& e) {
        cout << "Unexpected error:" << e.what() << endl;
    }
}

void addInteger(int data[], int& count){
    try
    {
        if (count >= MAX_SIZE)
        {
            throw overflow_error("Array is full");
        }
        int newValue;
        cout << "Enter a new intger to add:";
        cin >> newValue;

        data[count] = newValue;
        count++;

        cout << "Added" << newValue << " to the array" << endl;
    
    } catch(const overflow_error& e) {
        cout << "Error: " << e.what() << endl;
    } catch(const exception& e) {
        cout << "Unexpected error:" << e.what() << endl;
    }
}


void removeInteger(int data[], int& count){
    cout << "Enter an index to remove:";
    int index;
    cin >> index;
    if (index < 0 || index >= count) {
        cout << "Invalid index" << endl;
    } else {
        for (int i = index; i < count - 1; i++) {
             data[i] = data[i + 1];
        }
        count--;
        cout << "Data modified:" << endl;
        displayData(data, count);
        }
    
    return;

}