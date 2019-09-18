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
    // initialize and print input
    cout << "Unorganized Values:" << endl;
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // Sort v
    /* your code here */
    mergeSort(v, t, 0, v.size());

    // Overwrite v with the organized values in t
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = t.at(i);
    }

    // Print Output
    cout << "Organized Values" << endl;
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
    // Quick Return if Vector Size is 1
    if (a.size() == 1) {
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
    int i = left;
    int j = (middle + 1);
    int k = left;
    while (i < (middle + 1) && j < (right + 1)) { // If left element is lesser
        if (a.at(i) < a.at(j)) {
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
    if (i == (middle + 1)) { // If the end of the left list has been reached
        while (j < right) {
            tmp.at(k) = a.at(j);
            j++;
            k++;
        }
    }
    else if (j == right) { // If the end of the right list has been reached
        while (i < (middle + 1)) {
            tmp.at(k) = a.at(i);
            i++;
            k++;
        }
    }
}