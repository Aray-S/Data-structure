#include <iostream>
#include "priorityQueue.h"
using namespace std;
int main()
{
    int N;
    cin>>N;
    int *nodes=new int [N];
    for (int i=0; i<N; i++) {
        cin>>nodes[i];
    }
    int x, value;
    cin>>x;
    cin>>value;
    priorityQueue pq (nodes, N);
    int r=pq.findMin(x);
    int *a;
    a=pq.getArray();
    for (int i=0; i<N; i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    pq.decreaseKey (r, value);
    a=pq.getArray();
    for (int i=0; i<N; i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    while (!pq.isEmpty()){
        cout<<pq.deQueue()<<' ';
    }
    cout<<endl;
    delete[]nodes;
    delete[]a;
    return 0;
}
