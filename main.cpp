// Lab 37: Hash Table I
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int sum_ascii(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += (int)c; 
    }
    return sum; 
}

int main() {
    ifstream infile("data.txt"); 
    if (!infile) {
        cerr << "Error opening file, Check the files name" << endl;
        return 1;
    }

    string hexString;
    long long 

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
