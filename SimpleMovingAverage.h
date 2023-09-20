//
// Created by artem on 19.09.23.
//

#ifndef SMA_SIMPLEMOVINGAVERAGE_H
#define SMA_SIMPLEMOVINGAVERAGE_H

#include <deque>
#include <numeric>

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
        T frontValue = this->buffer.front();
        this->buffer.pop_front();
        this->buffer.push_back(newValue);

        if(this->buffer.size() < this->windowSize){
            elements_sum = std::accumulate(this->buffer.begin(), this->buffer.end(), 0);
            newSMA = elements_sum / this->windowSize;
        }
        else{
            newSMA = this->prevSMA + (newValue - frontValue)/this->windowSize;
            this->prevSMA = newSMA;
        }
        this->prevSMA = newSMA;
        return newSMA;
    }
    ~SimpleMovingAverage(){

    }

    T getFilteredValueSum(T newValue){
        T elements_sum = 0;
        T newSMA = 0;

        T frontValue = this->buffer.front();
        this->buffer.pop_front();
        this->buffer.push_back(newValue);

        for(auto element : this->buffer){
            elements_sum += element;
        }
        newSMA = elements_sum / this->windowSize;
        this->prevSMA = newSMA;

        return newSMA;
    }
};
#endif //SMA_SIMPLEMOVINGAVERAGE_H
