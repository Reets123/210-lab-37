// Lab 37: Hash Table I
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <string>

using namespace std;

int sum_ascii(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += (int)c; 
    }
    return sum; 
}

int main() {
    string test1 = "Hello";
    string test2 = "World";
    string test3 = "!";

    cout << "Sum of ASCII values for '" << test1 << "': " << sum_ascii(test1) << endl; 
    cout << "Sum of ASCII values for '" << test2 << "': " << sum_ascii(test2) << endl; 
    cout << "Sum of ASCII values for '" << test3 << "': " << sum_ascii(test3) << endl; 
    

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
