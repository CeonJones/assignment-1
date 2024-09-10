#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H
#include <string>

using namespace std;

const int MAX_SIZE = 200;

void readDataFromFile(const string& filename, int data[], int& count);
void displayData(const int data[], int count);
void findInteger(const int data[], int count);
void modifyInteger(int data[], int count);
void addInteger(int data[], int& count);
void removeInteger(int data[], int& count);

#endif //ARRAY_OPERATIONS_H