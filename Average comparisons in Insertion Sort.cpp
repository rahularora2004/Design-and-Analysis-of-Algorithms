//Write a C++ program to sort the elements of an array using insertion sort. The program should record the number of comparisons. 
//Test run  the program on 100 different input sizes valid from 30 to 1000. For each size, find the number of comparisons averaged on 10 input instances.
//Also plot the graph for input size vs average number of comparisons.

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void insertionSort(int arr[], int n, int& comparisons) {
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }

        arr[j + 1] = key;
    }
}

void randomArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand();
    }
}

int main() {
    const int totalSizes = 100;
    const int totalInstances = 10;

    int sizes[totalSizes];
    double avgcomp[totalSizes];

    for (int sizeIndex = 0, size = 30; sizeIndex < totalSizes; sizeIndex++, size += 7) {
        double averageComparisons = 0.0;

        for (int instance = 0; instance < totalInstances; ++instance) {
            int* myArray = new int[size];
            randomArray(myArray, size);

            int comparisons = 0;
            insertionSort(myArray, size, comparisons);
            averageComparisons += comparisons;

            delete[] myArray;
        }

        sizes[sizeIndex] = size;
        avgcomp[sizeIndex] = averageComparisons / totalInstances;
    }

    ofstream outFile("output1.csv");
    if (outFile.is_open()) {
        outFile << "Sizes,AvgComp\n";
        for (int i = 0; i < totalSizes; ++i) {
            outFile << sizes[i] << "," << avgcomp[i] << "\n";
        }
        outFile.close();
        cout << "Data written to output.csv\n";
    } else {
        cerr << "Error opening output file\n";
    }
    
     cout << "Sizes\tAvgComp\n";
        for (int i = 0; i < totalSizes; ++i) {
            cout << sizes[i] << "\t" << avgcomp[i] << "\n";
        }

    return 0;
}


//For plotting graph, write the following Python Program in related compiler
//import pandas as pd
//import numpy as np
//import matplotlib.pyplot as plt
//
//df=pd.read_csv("output1.csv")
//df['AvgComp'].plot()
//plt.xlabel("Sizes")
//plt.ylabel("Average comparisons")


