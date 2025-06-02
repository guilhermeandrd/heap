#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

//esse eh o heap máximo
//uso de vetor (array redimensionável)
//TODO deixar ele em typename
//TODO fazer o heapminimo
template <typename T>

class Heap{

private:

    std:: vector<T> m_vec;

    int m_size;

    void fixUp(int i);

    void fixDown(int i);


    void buildMaxHeap();

public:

    //construtor
    Heap();

    Heap(const std:: vector<T> &V);
    
    
    //operacoes
    
    //selecionar o elemento com maior prioridade
    //uso do this para 
    const T& top() const;

    
    //insercao um novo elemento
    void push(const T& newKey);
    
    //popr o elemento com maior prioridade
    
    void pop();

    //aumento da prioridade de elemento
    //passar vetor por referencia
    void increaseKey(int i, int newKey){

        if(newKey < this->m_vec[i])
            std::__throw_invalid_argument("invalid key");

        this->m_vec[i] = newKey;
        fixUp(this->m_vec, i);
    }

    //passa indice e valor
    void decreaseKey(int i, int newKey){
        if(newKey > this->m_vec[i]){
            std::cout << "error invalid";
        }
        
        this->m_vec[i] = newKey;
        fixDown(this->m_vec, i);
    }

    bool empty() const;

    int size() const;

    //percursos no heap
        //pre ordem
        //pos ordem
        //em ordem
        //por largura
        //por altura

    
    //exclusoes do const e do =
    Heap(const Heap&) = delete;
    Heap& operator=(const Heap&) = delete;


};

template <typename T>

Heap<T> :: Heap(){
    m_size = 0;
    m_vec.push_back(T()); //construtor "vazio" padrano se for char vai ser vazio se for string tambem se for num vai ser 0 e etc
}

template <typename T>

Heap<T> :: Heap(const std::vector<T>& v)
    : Heap() //chama o construtor default
{

    m_size = v.size(); //O(1)


    //copia do vetor
    for(const T& element : v){ //para todo elemento de v ele vai colocar em m_vec
        m_vec.push_back(element);
    }

    buildMaxHeap();
}

template <typename T>
int Heap<T> :: size() const{
    return m_size;
}

template <typename T>
bool Heap<T> :: empty() const{
    return m_size == 0;
}

template <typename T>
const T& Heap<T>:: top() const{
    if(empty()){
        throw std::underflow_error("empty queue");
    }

    return m_vec[1];
}

template <typename T>
void Heap<T> :: push(const T& newKey){
    m_vec.push_back(newKey);
    m_size++;
    fixUp(m_size);
}

template <typename T>

void Heap<T> :: pop(){
    if(empty()){
        throw std::underflow_error("empty queue");
    }

    
    m_vec[1] = m_vec[m_size];
   
    m_size--;
    fixDown(1);
    m_vec.pop_back();
}

template <typename T>
void Heap<T> ::fixUp(int index){

    while(index != 1 && m_vec[index] > m_vec[index/2]){
        
        T aux = m_vec[index];
        m_vec[index] = m_vec[index/2];
        m_vec[index/2] = aux;
        index = index/2;
        
    }

}

template <typename T>
void Heap<T> ::fixDown(int index){

    while(2 * index <= m_size){
        int ileft = 2 * index;
        int iright = ileft + 1;
        int ilargest = index;

        if(m_vec[index] < m_vec[ileft]){
            ilargest = ileft;
        }

        if(iright <= m_size && m_vec[ilargest] < m_vec[iright]){
            ilargest = iright;
        }

        if(ilargest != index){
            T aux = m_vec[index];
            m_vec[index] = m_vec[ilargest];
            m_vec[ilargest] = aux;
            index = ilargest;
        }
        else break;
        
    }
    
}

template<typename T>
void Heap<T>:: buildMaxHeap(){
    for(int i = m_vec.size()/2; i>=1; i-- ){
        fixDown(i);
    }
}

#endif