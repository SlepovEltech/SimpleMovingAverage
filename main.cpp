#include <iostream>
#include <ctime>
#include <chrono>

#include "SimpleMovingAverage.h"

#define TICKS_NUM 1000000

using namespace std;
using namespace chrono;
int main() {
    srand(std::time(nullptr));
    SimpleMovingAverage<float> filter(8);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    for (int i = 0; i < TICKS_NUM; i++) {
        double value = 1.0 + (std::rand() / (static_cast<double>(RAND_MAX) + 1.0)) * 100;
        cout << "Random: " << value << " | filtered: " << filter.getFilteredValueSum(value) << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double performance = static_cast<double>(TICKS_NUM)/duration.count();
    cout  << "Time taken by function: " << duration.count() << " usec" << endl;
    cout  << "Performance: " << performance << " ticks/usec" << endl;
    return 0;
}
