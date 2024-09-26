//Functions for reading data from file, displaying data, searching for an integer, modifying an integer, adding an integer, and removing an integer from an array.

#include "array_operations.h"
#include <fstream>
#include <iostream>

using namespace std;

//Resizes an array by doubling its capacity.
//If memory allocation fails, a runtime error is thrown.
//The original array is deleted and the new array is assigned to the original array.
//The capacity is updated to the new capacity.
void resizeArray(int*& data, int& capacity){
    try
    {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        copy(data, data + capacity, newData);

        delete[] data;

        data = newData;
        capacity = newCapacity;
    
    } catch(const bad_alloc& e) {
        throw runtime_error("Memory allocation failed when resizing array.");
    }
    
}
//Reads data from a file and stores it in an array.
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
//Displays the data in an array.
void displayData(const int data[], int count) {
    cout << "Data read from file:" << endl;
    for (int i = 0; i < count; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
//Searches for an integer in an array.
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
//Modifies an integer in an array.
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
void addInteger(int data[], int &count)
{
}
// Adds an integer to an array.
void addInteger(int data[], int& count, int& capacity){
    try{
        if (count >= capacity) {
            resizeArray(data, capacity);
        }

        int newValue;
        cout << "Enter a new integer to add:";
        cin >> newValue;
        data[count] = newValue;
        count++;
        cout << "Added: " << newValue << " to the array" << endl;
    } catch(const overflow_error& e) {
        cout << "Error: " << e.what() << endl;
    } catch(const exception& e) {
        cout << "Unexpected error:" << e.what() << endl;
    }
}

//Removes an integer from an array.
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