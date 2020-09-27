#include <iostream>
#include "linked_stack.h"

template<typename T>
structures::LinkedStack<T>::LinkedStack() {
    top_ = nullptr;
    size_ = 0;
}

template<typename T>
structures::LinkedStack<T>::~LinkedStack() {
    clear();
}

template<typename T>
void structures::LinkedStack<T>::clear() {
    for (int i = 0; i < size(); i++)
        pop();
    top_ = nullptr;
    size_ = 0;
}

template<typename T>
void structures::LinkedStack<T>::push(const T& data) {
    Node* new_top = new Node(data, top_);
    top_ = new_top;
    size_++;
}

template<typename T>
T structures::LinkedStack<T>::pop() {
    if (empty()) throw std::out_of_range("lista vazia");
    T temp = top_->data();
    Node* node_temp = top_;
    top_ = top_->next();
    delete node_temp;
    size_--;
    return temp;
}

template<typename T>
T& structures::LinkedStack<T>::top() const {
    if (empty()) throw std::out_of_range("lista vazia");
    return top_->data();
}

template<typename T>
bool structures::LinkedStack<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t structures::LinkedStack<T>::size() const {
    return size_;
}