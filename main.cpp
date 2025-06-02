#include <iostream>
#include "Heap.hpp"
#include "priority_queue.hpp"

using namespace std;

int main() {

    Heap <int> oi;
    
    oi.push(4);
    oi.push(10);
    oi.push(5);

    cout << oi.top() << endl;

    oi.pop();

    cout << oi.top() << endl;

    vector<int> restp;

    for(int i=0;i<7;i++){
        restp.push_back(i);
    }

    Heap<int> tchau(restp);

    cout << tchau.top() << endl;

    PriorityQueue<int> bye(restp);

    cout << bye.top() << endl;
    

    return 0;
}