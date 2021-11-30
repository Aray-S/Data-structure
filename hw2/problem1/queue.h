#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
using namespace std;
template <class elemType>
class linkQueue
{
    private:
        struct node {
            elemType data;
            node *next;
            node (const elemType &x, node *N=NULL)
                {data=x; next=N;}
            node(): next(NULL) {}
            ~node(){}
        };
        node *front, *rear;
    public:
        linkQueue() {front=rear=NULL;}
        ~linkQueue();
        bool isEmpty() const {return front==NULL;}
        void enQueue (const elemType &x);
        elemType deQueue();
        elemType getHead() const {return front->data;}
};
#endif // QUEUE_H_INCLUDED
