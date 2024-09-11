#include "circular-queue.h"

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_ = 16;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_ = capacity;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    if(size_ == 0){
        return true;
    }
    return false;
}

bool CircularQueue::full() const {
    if(size_ == capacity_){
        return true;
    }
    return false;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if(empty()){
        return EMPTY_QUEUE;
    }
    return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if(full()){
        return false;
    }

    items_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    size_++;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if(empty()){
        return EMPTY_QUEUE;
    }

    QueueItem popped = items_[head_];
    head_ = (head_ + 1) % capacity_;
    size_--;
    return popped;
}

void CircularQueue::print() const {
    for(int i = 0; i < size_; i++){
        cout << items_[i];
    }
}
