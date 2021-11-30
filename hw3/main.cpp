#include <iostream>
#include "priorityQueue.h"
using namespace std;
int minBoxSize (int N, int *items, int capacity)
{
    priorityQueue pq, tmp;
    int k=0;
    for (int i=0; i<N; i++)
    {
        pq.enQueue(capacity);
        tmp.enQueue(items[i]);
    }
    while (!tmp.isEmpty())
    {
        int t=tmp.deQueue();
        pq.decreaseKey(pq.findMin(t), t);
    }
    while (!pq.isEmpty())
        if (pq.deQueue()<capacity) ++k;
    return k;
}
int main()
{
    int N;
    cin>>N;
    int*items = new int [N];
    for (int i=0; i<N; i++){
        cin>>items[i];
    }
    int capacity;
    cin>>capacity;
    cout<<minBoxSize(N, items, capacity)<<endl;
    delete [] items;
    return 0;
}
