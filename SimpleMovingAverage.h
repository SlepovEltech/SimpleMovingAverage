//
// Created by artem on 19.09.23.
//

#ifndef SMA_SIMPLEMOVINGAVERAGE_H
#define SMA_SIMPLEMOVINGAVERAGE_H

#include <deque>


//class SimpleMovingAverage {
//public:
//    SimpleMovingAverage(int windowSize);
//    double getFilteredValue(double newValue);
//    ~SimpleMovingAverage();
//private:
//    int windowSize;
//    double prevSMA;
//    std::deque<double> buffer;
//
//};

template <typename T>
class SimpleMovingAverage {
public:
    SimpleMovingAverage(int windowSize);
    T getFilteredValue(T newValue);
    ~SimpleMovingAverage();
private:
    int windowSize;
    T prevSMA;
    std::deque<T> buffer;

};


#endif //SMA_SIMPLEMOVINGAVERAGE_H
