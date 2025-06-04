#include <iostream>
#include "Heap.hpp"

using namespace std;

int main() {

    
    vector<int> restp;
    
    for(int i=0;i<7;i++){
        restp.push_back(i);
    }
    
    Heap<int> tchau(restp);
    Heap <int> oi(restp);

    cout << tchau.top() << endl;

    while(!tchau.empty()){
        cout << tchau.top() << " " ;
        tchau.pop();
    }

    cout << endl;

    oi.pop(2);

    while(!oi.empty()){
        cout << oi.top() << " " ;
        oi.pop();
    }

    return 0;
}