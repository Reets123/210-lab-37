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
    return sum % 256; 
}

int main() {
    ifstream infile("lab-37-data.txt"); 
    if (!infile) {
        cerr << "Error opening file, Check the files name" << endl;
        return 1;
    }

    string hexString;
    long long grandTotal = 0; // Total sum of ASCII values

    map<int, list<string>> hash_table;

    while (infile >> hexString) {
        if (hexString.length() == 12) {
            int hash_index = gen_hash_index(hexString);
            hash_table[hash_index].push_back(hexString);

            for (char c : hexString) {
                grandTotal += (int)c;
            }
        }
    }

    infile.close(); 

    cout << "Grand Total of ASCII values: " << grandTotal << endl;

    int count = 0;
    for (const auto& entry : hash_table) {
        cout << "Hash Index: " << entry.first << " -> Codes: ";
        for (const auto& code : entry.second) {
            cout << code << " ";
        }
        cout << endl;

        if (++count >= 100) {
            break;  
        }
    }

    return 0;
}