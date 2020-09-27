#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

namespace structures {

template<typename T>
class LinkedStack {
 public:
    LinkedStack();

    ~LinkedStack();
    //! limpa pilha
    void clear();  // limpa pilha
    //! empilha
    void push(const T& data);  // empilha
    //! desempilha
    T pop();  // desempilha
    //! dado no topo
    T& top() const;  // dado no topo
    //! pilha vazia
    bool empty() const;  // pilha vazia
    //! tamanho da pilha
    std::size_t size() const;  // tamanho da pilha

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {return data_;}  // getter: info
        const T& data() const {return data_;}  // getter-constante: info

        Node* next() {return next_;}  // getter: próximo
        const Node* next() const {return next_;}  // getter-constante: próximo

        void next(Node* next) {next_ = next;}  // setter: próximo
     private:
        T data_;
        Node* next_;
    };

    Node* top_;  // nodo-topo
    std::size_t size_;  // tamanho
};

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

}

#endif