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
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    // unit test for merge
    /* your code here */
    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    /* your code here */
    mergeSort(v, t, 0, v.size());

    // print output
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

    // Organize and Merge
    mergeSortedLists(a, tmp, left, (((right + left) + 1) / 2), right);
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {
    for (int i = left; i > middle; i++) {
        if (a.at(i) < a.at(i + 1)) {
            tmp.at(i) = a.at(i);
            a.at(i) = a.at(i + 1);
            a.at(i + 1) = tmp.at(i);
        }
    }
}