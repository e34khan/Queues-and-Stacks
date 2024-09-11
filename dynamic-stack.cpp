#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    init_capacity_ = 16;
    size_ = 0;
    capacity_ = init_capacity_;
    items_ = new StackItem[init_capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity){
    size_ = 0;
    init_capacity_ = capacity;
    capacity_ = capacity;
    items_ = new StackItem[capacity];
}

DynamicStack::~DynamicStack() {
    delete[] items_;
    items_ = nullptr;
}

unsigned int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    if(size_ == 0){
        return true;
    }
    return false;
}

DynamicStack::StackItem DynamicStack::peek() const {
    if(empty()){
        return EMPTY_STACK;
    }
    return items_[size_ - 1];
}

void DynamicStack::push(StackItem value) {
    if(size_ <  capacity_){
        items_[size_] = value;
    }
    else{
        capacity_ *= 2;
        StackItem* temp = new StackItem[capacity_];
        for(int i = 0; i < size_; i++){
            temp[i] = items_[i];
        }
        delete[] items_;
        items_ = temp;
        items_[size_] = value;
    }
    size_++;
 }

DynamicStack::StackItem DynamicStack::pop() {
    if(empty()){
        return EMPTY_STACK;
    }

    StackItem popped = items_[size_ - 1];
    size_--;
    if (size_ <= capacity_/4 && capacity_/2 >= init_capacity_){
        capacity_ /= 2;
        StackItem* temp = new StackItem[capacity_];
        for(int i = 0; i < size_; i++){
            temp[i] = items_[i];
        }
        delete[] items_;
        items_ = temp;
    }

    return popped;
}

void DynamicStack::print() const {
    for(int i = size_ - 1; i >= 0; i--){
        std::cout << items_[i];
    }
}
