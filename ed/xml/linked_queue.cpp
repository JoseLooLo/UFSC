#include <iostream>
#include "linked_queue.h"

template<typename T>
structures::LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

template<typename T>
structures::LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void structures::LinkedQueue<T>::clear() {
    for (int i = 0; i < size(); i++)
        dequeue();
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

template<typename T>
void structures::LinkedQueue<T>::enqueue(const T& data) {
    if (empty()) {
        Node* new_node = new Node(data);
        tail = new_node;
        head = new_node;
        size_++;
    } else {
        Node* new_node = new Node(data, tail);
        tail = new_node;
        size_++;
    }
}

template<typename T>
T structures::LinkedQueue<T>::dequeue() {
    if (empty()) throw std::out_of_range("empty queue");
    if (size() == 1) {
        T temp = head->data();
        delete head;
        head = nullptr;
        tail = nullptr;
        size_--;
        return temp;
    } else {
        T temp = head->data();
        Node* anterior = tail;
        Node* proximo = tail->next();
        while (proximo->next() != nullptr) {
            anterior = proximo;
            proximo = proximo->next();
        }
        delete head;
        anterior->next(nullptr);
        head = anterior;
        size_--;
        return temp;
    }
}

template<typename T>
T& structures::LinkedQueue<T>::front() const {
    if (empty()) throw std::out_of_range("empty queue");
    return head->data();
}

template<typename T>
T& structures::LinkedQueue<T>::back() const {
    if (empty()) throw std::out_of_range("empty queue");
    return tail->data();
}

template<typename T>
bool structures::LinkedQueue<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t structures::LinkedQueue<T>::size() const {
    return size_;
}

template<typename T>
structures::LinkedQueue<T>::Node::Node(const T& data) {
    data_ = data;
    next_ = nullptr;
}

template<typename T>
structures::LinkedQueue<T>::Node::Node(const T& data, Node * next) {
    data_ = data;
    next_ = next;
}

template<typename T>
T& structures::LinkedQueue<T>::Node::data() {
    return data_;
}

template<typename T>
const T& structures::LinkedQueue<T>::Node::data() const {
    return data_;
}

template<typename T>
typename structures::LinkedQueue<T>::Node* structures::LinkedQueue<T>::Node::next() {
    return next_;
}

template<typename T>
const typename structures::LinkedQueue<T>::Node* structures::LinkedQueue<T>::Node::next() const {
    return next_;
}

template<typename T>
void structures::LinkedQueue<T>::Node::next(Node* next) {
    next_ = next;
}