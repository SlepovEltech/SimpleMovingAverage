//
// Created by artem on 19.09.23.
//

#ifndef SMA_SIMPLEMOVINGAVERAGE_H
#define SMA_SIMPLEMOVINGAVERAGE_H

#include <deque>
#include <numeric>
#include <cmath>

template <typename T>
class SimpleMovingAverage {
private:
    int windowSize;
    T prevSMA;
    std::deque<T> buffer; //deque for O(1) push and pop
public:
    SimpleMovingAverage(int windowSize_){
        windowSize = windowSize_;
        buffer = std::deque<T>(windowSize_);
        prevSMA = 0;
    }
    /*This method implements cheap formula with previos SMA*/
    T getFilteredValue(T newValue){
        T elements_sum = 0;
        T newSMA = 0;
        T frontValue = this->buffer.front();
        this->buffer.pop_front();
        this->buffer.push_back(newValue);

        if(this->buffer.size() < this->windowSize){ //while buffer isn't accumulated, need to calc sum
            elements_sum = std::accumulate(this->buffer.begin(), this->buffer.end(), 0);
            newSMA = elements_sum / this->windowSize;
        }
        else{ //when buffer full, use cheap formula
            newSMA = this->prevSMA + (newValue - frontValue)/this->windowSize;
            this->prevSMA = newSMA;
        }
        this->prevSMA = newSMA;
        return newSMA;
    }
    ~SimpleMovingAverage(){

    }
    /*This method helps to compare performance of cheap and direct calculate */
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
