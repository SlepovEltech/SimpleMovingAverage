#include <iostream>
#include <ctime>
#include <deque>
#include <numeric>
//#include "SimpleMovingAverage.h"

#define TICKS_NUM 20

template <typename T>
class SimpleMovingAverage {
private:
    int windowSize;
    T prevSMA;
    std::deque<T> buffer;
public:
    SimpleMovingAverage(int windowSize_){
        windowSize = windowSize_;
        buffer = std::deque<T>(windowSize_, 0);
        prevSMA = 0;
    }
    T getFilteredValue(T newValue){
        T elements_sum = 0;
        T newSMA = 0;
        if(this->buffer.size() <= this->windowSize){
            this->buffer.push_back(newValue);
            elements_sum = std::accumulate(this->buffer.begin(), this->buffer.end(), 0);
            newSMA = elements_sum / this->windowSize;
            this->prevSMA = newSMA;
        }
        else{
            T frontValue = this->buffer.front();
            newSMA = this->prevSMA + (newValue - frontValue)/this->windowSize;
            this->buffer.pop_front();
            this->buffer.push_back(newValue);
            this->prevSMA = newSMA;
        }
        return newSMA;
    }
    ~SimpleMovingAverage(){

    }
};

int main() {
    std::srand(std::time(nullptr));
    SimpleMovingAverage<float> filter(8);

    for (int i = 0; i < TICKS_NUM; i++) {
        double value = 1.0 + (std::rand() / (static_cast<double>(RAND_MAX) + 1.0)) * 100;
        std::cout << value << " | filtered: " << filter.getFilteredValue(value) << std::endl;

    }
    return 0;
}
