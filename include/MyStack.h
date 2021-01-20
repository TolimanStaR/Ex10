// Copyright 2020 A.SHT
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
  T *container;
  int capacity;
  int size;

 public:
    explicit MyStack(int cap) {
        this->capacity = cap;
        this->size = -1;
        this->container = new T[cap];
    }

    MyStack(const MyStack &stack) {
        this->capacity = stack.capacity;
        this->size = stack.size;
        this->container = new T[this->capacity];
        for (int i = 0; i < this->capacity; ++i)
            this->container[i] = stack.container[i];
    }

    T get() const {
        return this->container[this->size];
    }

    T pop() {
        return this->container[this->size--];
    }

    void push(T elem) {
        this->container[++this->size] = elem;
    }

    bool isFull() {
        return this->size + 1 >= this->capacity;
    }

    bool isEmpty() const {
        return this->size == -1;
    }
};

#endif  // INCLUDE_MYSTACK_H_
