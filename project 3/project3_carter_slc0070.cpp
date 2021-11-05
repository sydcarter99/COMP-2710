// ****************************************************************
// filename: project3_carter_slc0070.cpp
// author: Sydney Carter
// sources: http://cplusplus.com/reference/iolibrary/
//          http://cplusplus.com/reference/algorithm/sort/
//          project3_hint.pdf
// compile: g++ -std=c++11 project3_carter_slc0070.cpp on au server
// ****************************************************************

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* declare user-defined functions */
bool check_file(string);

/* don't forget to describe each function*/
vector<int> read_file(string);

void write_file(string, vector<int>);

vector<int> merge(vector<int>, vector<int>);

/*
 * Display the values of a given vector.
 *
 * Param: file - name of file to display (string)
 * Param: v - vector containing values to display (vector<int>)
 */
void to_string(vector<int>);

/*
 * Merge numbers in two specified files and write all numbers to a specified
 * third file sorted in ascending order.
 *
 * Return: 1 program completed successfully (int)
 */
int main() {
    /* declare vars */
    string file1;
    string file2;
    string file3;
    vector<int> numbers;
    vector<int> numbers2;
    vector<int> numbers3;
    
    cout << "*** Welcome to Sydney's sorting program ***" << endl;
    
    // ifstream instream;
    /* get name of file 1 */
    do {
        cout << "Enter the first input file name: ";
        cin >> file1;
        
        // cout << cin.fail() << !check_file(file1);
        // instream.close();
    }
    while (cin.fail() || !check_file(file1));
    // instream.close();
    
    /* get and display numbers from file 1 */
    numbers = read_file(file1);
    cout << "The list of " << numbers.size() << " numbers in file"
         << file1 << "is:\n";
    to_string(numbers);
    
    /* get name of file 2 */
    do {
        cout << "Enter the second input file name: ";
        cin >> file2;
    }
    while (cin.fail() || !check_file(file2));
    
    /* get and display numbers from file 2 */
    numbers2 = read_file(file2);
    cout << "The list of " << numbers2.size() << " numbers in file"
         << file1 << "is:\n";
    to_string(numbers2);
    
    /* combine vectors and display the sorted result */
    numbers3 = merge(numbers, numbers2);
    cout << "The sorted list of " << numbers3.size() << " numbers is: ";
    for ( unsigned int i = 0; i < numbers3.size(); i++) {
        cout << numbers3.at(i) << " ";
    }
    cout << endl;
    
    /* get name of output file */
    do {
        cout << "Enter the output file name: ";
        cin >> file3;
    }
    while (cin.fail());
    
    /* write combined vector output file */
    write_file(file3, numbers3);
    
    cout << "*** Please check the new file - " << file3 << " ***\n"
         << "*** Goodbye. ***" << endl;
    
    return 0;
}

bool check_file(string file) {
    // input file stream. (ifstream)
    ifstream stream;
    
    // check whether file exists
    stream.open(file.c_str());
    if (stream.fail()) {
        stream.close();
        return false;
    }
    stream.close();
    
    return true;
}

vector<int> read_file(string file) {
    /* input file stream (ifstream) */
    ifstream stream;
    /* vector containing numbers from file (vector<int>) */
    vector<int> v;
    /* integer read from file (int) */
    int i;
    /* add each number in the file to a vector */
    stream.open(file);
    while (stream >> i) {
        // stream >> i;
        v.push_back(i);
        // v.insert(v.end(), i);
    }
    stream.close();
    
    return v;
}

void write_file(string file, vector<int> v) {
    /* output file stream (ofstream) */
    ofstream stream;
    stream.open(file.c_str());
    for (unsigned int i = 0; i < v.size(); i++) {
        stream << v.at(i) << endl;
    }
    stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> v3;
    
    v3 = v1;
    v3.insert(v3.end(), v2.begin(), v2.end());
    for (int i = 0; i < v3.size(); i++) {
        for (int j = i; j < v3.size(); j++) {
            if (v3[i] > v3[j]) {
                swap(v3[i], v3[j]);
            }
        }
    }

        return v3;
}

void to_string(vector<int> v) {
    /* vector interator number. (unsigned short) */
    unsigned short i;
    /* display the numbers contained in a vector */
    for (i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    cout << endl;
}
