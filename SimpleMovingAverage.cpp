//
// Created by artem on 19.09.23.
//

#include <numeric>
#include "SimpleMovingAverage.h"

template<typename T>
SimpleMovingAverage<T>::SimpleMovingAverage(int windowSize) {
    SimpleMovingAverage::buffer = std::deque<T>(windowSize, 0);
    SimpleMovingAverage::prevSMA = 0;
    SimpleMovingAverage::windowSize = windowSize;
}

template<typename T>
T SimpleMovingAverage<T>::getFilteredValue(T newValue) {
    T elements_sum = 0;
    T newSMA = 0;
    if(this->buffer.size() < this->buffer.max_size()){
        this->buffer.push_back(newValue);
        elements_sum = std::accumulate(this->buffer.begin(), this->buffer.end(), decltype(this->buffer)::value_type(0));
        newSMA = elements_sum / windowSize;
    }
    else{
        T frontValue = this->buffer.front();
        newSMA = this->prevSMA + (newValue - frontValue);
        this->buffer.pop_front();
        this->buffer.push_back(newValue);
        this->prevSMA = newSMA;
    }
    return newSMA;
}

template<typename T>
SimpleMovingAverage<T>::~SimpleMovingAverage() {
    //this->buffer.erase();
}



////template<typename T>
//SimpleMovingAverage::SimpleMovingAverage(int windowSize_) {
//    SimpleMovingAverage::buffer = std::deque<double>(windowSize, 0);
//    SimpleMovingAverage::prevSMA = 0;
//    SimpleMovingAverage::windowSize = windowSize_;
//}
//
////template<typename T>
//double SimpleMovingAverage::getFilteredValue(double newValue) {
//    double elements_sum = 0;
//    double newSMA = 0;
//    if(this->buffer.size() < this->windowSize){
//        this->buffer.push_back(newValue);
//        elements_sum = std::accumulate(this->buffer.begin(), this->buffer.end(), decltype(this->buffer)::value_type(0));
//        newSMA = elements_sum / this->windowSize;
//        this->prevSMA = newSMA;
//    }
//    else{
//        double frontValue = this->buffer.front();
//        newSMA = this->prevSMA + (newValue - frontValue)/this->windowSize;
//        this->buffer.pop_front();
//        this->buffer.push_back(newValue);
//        this->prevSMA = newSMA;
//    }
//    return newSMA;
//}
//
////template<typename T>
//SimpleMovingAverage::~SimpleMovingAverage() {
//    //this->buffer.erase();
//}
