// Author: Nathan Maynard
// Course: CSC 112 Section B (Fall 2019)
// Project: Project 2 - MergeSort
// Due Date: 5:00pm, Sept. 19, 2019
// Purpose:

#include <iostream>
#include <vector>
using namespace std;

// Function Declarations

// "Divide"
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);

// "Conquer"
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cout << "Please type in a srand() seed, then please type the desired vector length" << endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    /* your code here */
    cout << "Beginning MergeSort Unit Test" << endl;
    vector<int> testVect1{0,2,4,6,8,1,3,5,7,9}; // Test 1
    vector<int> testTempVect1(10);
    cout << "Test 1: Using mergeSortedLists() Only" << endl;
    cout << "Original Vector Contents:" << endl;
    cout << "0,2,4,6,8,1,3,5,7,9" << endl;
    cout << "Expected Organized Contents:" << endl;
    cout << "0,1,2,3,4,5,6,7,8,9" << endl;
    cout << "Received Result:" << endl;
    mergeSortedLists(testVect1, testTempVect1, 0, (((testVect1.size() - 1) + 0) / 2), (testVect1.size() - 1));
    for(int i = 0; i < testVect1.size(); i++) {
        cout << testVect1.at(i) << '\t';
    }
    cout << endl << endl;

    vector<int> testVect2{2,4,3,1,5}; // Test 2
    vector<int> testTempVect2(5);
    cout << "Test 2: Using mergeSortedLists() Only" << endl;
    cout << "Original Vector Contents:" << endl;
    cout << "2,4,3,1,5" << endl;
    cout << "Expected Organized Contents:" << endl;
    cout << "1,2,3,4,5" << endl;
    cout << "Received Result:" << endl;
    mergeSortedLists(testVect2, testTempVect2, 0, (((testVect2.size() - 1) + 0) / 2), (testVect2.size() - 1));
    for(int i = 0; i < testVect2.size(); i++) {
        cout << testVect2.at(i) << '\t';
    }
    cout << endl << endl;

    vector<int> testVect3{1,0,1,0,1,0,1,0,1,0}; // Test 3
    vector<int> testTempVect3(10);
    cout << "Test 3: Using mergeSortedLists() and mergeSort()" << endl;
    cout << "Original Vector Contents:" << endl;
    cout << "1,0,1,0,1,0,1,0,1,0" << endl;
    cout << "Expected Organized Contents:" << endl;
    cout << "0,0,0,0,0,1,1,1,1,1" << endl;
    cout << "Received Result:" << endl;
    mergeSort(testVect3, testTempVect3, 0, (testVect3.size() - 1));
    for(int i = 0; i < testVect3.size(); i++) {
        cout << testVect3.at(i) << '\t';
    }
    cout << endl << endl;

    vector<int> testVect4{9,8,7,6,5,4,3,2,1,0}; // Test 4
    vector<int> testTempVect4(10);
    cout << "Test 4: Using mergeSortedLists() and mergeSort()" << endl;
    cout << "Original Vector Contents:" << endl;
    cout << "9,8,7,6,5,4,3,2,1,0" << endl;
    cout << "Expected Organized Contents:" << endl;
    cout << "0,1,2,3,4,5,6,7,8,9" << endl;
    cout << "Received Result:" << endl;
    mergeSort(testVect4, testTempVect4, 0, (testVect4.size() - 1));
    for(int i = 0; i < testVect4.size(); i++) {
        cout << testVect4.at(i) << '\t';
    }
    cout << endl << endl;

    // initialize and print input
    cout << "Unorganized Values:" << endl;
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // Sort v
    /* your code here */
    mergeSort(v, t, 0, (v.size() - 1));

    // Print Output
    cout << "Organized Values:" << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

/* your code here */
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    // Quick Return if size is 1
    if (left == right) {
        return;
    }

    // Left Half
    mergeSort(a, tmp, left, ((right + left) / 2));

    // Right Half
    mergeSort(a, tmp, (((left + right) / 2) + 1), right);

    // Organize
    mergeSortedLists(a, tmp, left, ((right + left) / 2), right);
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {
    int i = left; // Index of the Left Half
    int j = (middle + 1); // Index of the Right Half
    int k = left; // Index of the temporary vector
    while (i < (middle + 1) && j < (right + 1)) {
        if (a.at(i) < a.at(j)) { // If left element is lesser
            tmp.at(k) = a.at(i);
            i++;
            k++;
        }
        else { // If right element is lesser or equal
            tmp.at(k) = a.at(j);
            j++;
            k++;
        }
    }
    if (i >= (middle + 1)) { // If the end of the left list has been reached
        while (j <= right) {
            tmp.at(k) = a.at(j);
            j++;
            k++;
        }
    }
    else if (j >= right) { // If the end of the right list has been reached
        while (i < (middle + 1)) {
            tmp.at(k) = a.at(i);
            i++;
            k++;
        }
    }

    // Overwrite Vector v with the organized values in Vector t
    for (int h = left; h <= right; h++) {
        a.at(h) = tmp.at(h);
    }

}