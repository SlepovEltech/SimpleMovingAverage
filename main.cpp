#include <iostream>
#include <ctime>
#include <chrono>

#include "SimpleMovingAverage.h"

#define TICKS_NUM 1000000
#define TICKS_TYPE double
#define WINDOW_SIZE 4
#define MAX_TICK 1000000
#define RANDOM_INPUT true

using namespace std;
using namespace chrono;
int main() {
    TICKS_TYPE value;
    srand(std::time(nullptr));
    SimpleMovingAverage<TICKS_TYPE> filter(WINDOW_SIZE);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    if(RANDOM_INPUT){
        for (int i = 0; i < TICKS_NUM; i++) {
            value = 1.0 + (std::rand() / (static_cast<double>(RAND_MAX) + 1.0)) * MAX_TICK;
            cout << "Random: " << value << " | filtered: " << filter.getFilteredValueSum(value) << endl;
        }
    }
    else{
        for (int i = 0; i < TICKS_NUM; ++i) {
            cout << "Enter tick(" << i << "/" << TICKS_NUM << "): ";
            cin >> value;
            cout << "Input: " << value << " | filtered: " << filter.getFilteredValue(value) << endl;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double performance = static_cast<double>(TICKS_NUM)/duration.count();
    cout  << "Time taken by function: " << duration.count() << " usec" << endl;
    cout  << "Performance: " << performance << " ticks/usec" << endl;
    return 0;
}
