/*
 * TestInsultGenerator.cpp
 *
 *      Author: Alan McLeod
 *      A testing program for CISC320 assignment 1.
 */

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <assert.h>

#include "insultgenerator_14vb16.h"

using namespace std;

int main() {
    InsultGenerator ig;
    vector<string> insults;
    double start, finish;

    // The initialize() method should load all the source phrases from the InsultsSource.txt file into the attributes.
    // If the file cannot be read, the method should throw an exception.
    try {
        ig.initialize();
    } catch (FileException& e) {
        cerr << e.what() << endl;
        return 1;
    }

    start = clock();
    insults = ig.generate(10000);
    finish = clock();
    cout << "\n" << insults.size() << " insults generated." << endl;
    cout << (finish - start) << " msec to complete." << endl;
    return 0;

} // end main
