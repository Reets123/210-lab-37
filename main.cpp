// Lab 38: Hash Table II
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

int gen_hash_index(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += (int)c; 
    }
    return sum % 256; 
}

void display_first_100_entries(const map<int, list<string>>& hash_table) {
    int count = 0;
    for (const auto& entry : hash_table) {
        cout << "Hash Index: " << entry.first << " -> Codes: ";
        for (constauto& code : entry.second) {
            cout << code << " ";
        }
        cout << endl;

        if (++count >= 100) {
            break;  
        }
    }
}

void search_key(const map<int, list<string>>& hash_table, int key) {
    auto it = hash_table.find(key);
    if (it != hash_table.end()) {
        cout << "Hash Index: " << key << " -> Codes: ";
        for (const auto& code : it->second) {
            cout << code << " ";
        }
        cout << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }
}


void add_key(map<int, list<string>>& hash_table, int key, const string& code) {
    hash_table[key].push_back(code);
    cout << "Added code: " << code << " at Hash Index: " << key << endl;
}

void remove_key(map<int, list<string>>& hash_table, int key) {
    auto it = hash_table.find(key);
    if (it != hash_table.end()) {
        hash_table.erase(it);
        cout << "Removed entries at Hash Index: " << key << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }
}

void modify_key(map<int, list<string>>& hash_table, int key, const string& old_code, const string& new_code) {
    auto it = hash_table.find(key);
    if (it != hash_table.end()) {
        auto& code_list = it->second;
        auto code_it = find(code_list.begin(), code_list.end(), old_code);
        if (code_it != code_list.end()) {
            *code_it = new_code; 
            cout << "Modified code: " << old_code << " to " << new_code << " at Hash Index: " << key << endl;
        } else {
            cout << "Code " << old_code << " not found at Hash Index: " << key << endl;
        }
    } else {
        cout << "Key " << key << " not found." << endl;
    }
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