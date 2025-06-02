/**
 * @file priority_queue.hpp
 * @author Atilio G. Luiz (you@domain.com)
 * @brief Generic class that implements a priority queue
 * @version 0.1
 * @date 2025-06-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef PRIOTRITY_QUEUE_HPP
#define PRIOTRITY_QUEUE_HPP
#include <stdexcept>
#include <vector>

template <typename T>
class PriorityQueue {
private:
    int m_heapSize;         // numero de elementos no heap
    std::vector<T> m_vec;   // heap

public:
    // Construtor
    PriorityQueue();
    // Contrutor cria um heap a partir de um vector previo
    PriorityQueue(const std::vector<T>& v);
    // retorna o número de elementos na fila
    int size() const;
    // retorna true se e somente se a fila esta vazia
    bool empty() const;
    // retorna o valor do elemento prioritario
    const T& top() const;
    // remove o elemento prioritario
    void pop();
    // insere um elemento na fila
    void push(const T& element);

private:
    // recebe como entrada um indice e faz 
    // o elemento m_vec[index] descer no heap
    void fixDown(int index);
    // recebe como entrada um indice e faz
    // o elemento m_vec[index] subir no heap
    void fixUp(int index);
    // rearranja os elementos do vector m_vec de modo
    // a obter um heap
    void buildMaxHeap();
};

// ----------------------------------------------------------------

// construtor default
template <typename T>
PriorityQueue<T>::PriorityQueue() {
    m_heapSize = 0;
    m_vec.push_back(T());
}


// Contrutor cria um heap a partir de um vector prévio
template <typename T>
PriorityQueue<T>::PriorityQueue(const std::vector<T>& v)
    : PriorityQueue()
{
    // copia os elementos de v para m_vec
    for(const T& element : v) {
        m_vec.push_back(element);
    }
    // ajusta m_heapSize e rearranja os elementos de m_vec
    // de modo a torna-lo um heap!
    m_heapSize = v.size();
    buildMaxHeap();
}

// retorna o número de elementos na fila
template <typename T>
int PriorityQueue<T>::size() const {
    return m_heapSize;
}

// retorna true se e somente se a fila esta vazia
template <typename T>
bool PriorityQueue<T>::empty() const {
    return m_heapSize == 0;
}

// retorna o valor do elemento prioritario
template <typename T>
const T& PriorityQueue<T>::top() const {
    if(empty()) {
        throw std::underflow_error("empty queue");
    }
    return m_vec[1];
}

// insere um elemento na fila
template <typename T>
void PriorityQueue<T>::push(const T& element) {
    m_vec.push_back(element);
    m_heapSize++;
    fixUp(m_heapSize);
}

// remove o elemento prioritario
template <typename T>
void PriorityQueue<T>::pop() {
    if(empty()) {
        throw std::underflow_error("empty queue");
    }
    m_vec[1] = m_vec[m_heapSize];
    m_heapSize--;
    fixDown(1);
}

// recebe como entrada um indice e faz
// o elemento m_vec[index] subir no heap
template <typename T>
void PriorityQueue<T>::fixUp(int index) {
    while(index != 1 && m_vec[index] > m_vec[index/2]) {        
        T aux = m_vec[index];
        m_vec[index] = m_vec[index/2];
        m_vec[index/2] = aux;
        index = index/2;
    }
}

// recebe como entrada um indice e faz 
// o elemento m_vec[index] descer no heap
template <typename T>
void PriorityQueue<T>::fixDown(int index) {
    while(2*index <= m_heapSize) {
        int ileft = 2*index;
        int iright = ileft+1;
        int ilargest = index;
        if(m_vec[index] < m_vec[ileft])
            ilargest = ileft;
        if(iright <= m_heapSize && m_vec[ilargest] < m_vec[iright])
            ilargest = iright;
        if(ilargest != index) {
            T aux = m_vec[index];
            m_vec[index] = m_vec[ilargest];
            m_vec[ilargest] = aux;
            index = ilargest;
        } 
        else break;
    }
}

// rearranja os elementos do vector m_vec de modo a obter um heap
template <typename T>
void PriorityQueue<T>::buildMaxHeap() {
    for(int i = m_vec.size()/2; i >= 1; i--) {
        fixDown(i);
    }
}

#endif