// Lab 37: Hash Table I
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>

using namespace std;

int gen_hash_index(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += (int)c; 
    }
    return sum; 
}

int main() {
    ifstream infile("lab-37-data.txt"); 
    if (!infile) {
        cerr << "Error opening file, Check the files name" << endl;
        return 1;
    }

    string hexString;
    long long grandTotal = 0; // Total sum of ASCII values

    while (infile >> hexString) {
        if (hexString.length() == 12) {
            grandTotal += sum_ascii(hexString); 
        }
    }

    infile.close(); 

    cout << "Grand Total of ASCII values: " << grandTotal << endl;

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
