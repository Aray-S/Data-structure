#include <iostream>
#include "queue.h"
using namespace std;
template <class elemType>
linkQueue <elemType>::~linkQueue()
{
    node *tmp;
    while (front!=NULL) {
        tmp=front;
        front=front->next;
        delete tmp;
        }
}
template <class elemType>
void linkQueue <elemType>::enQueue (const elemType &x)
{
    if (rear==NULL) front=rear=new node(x);
    else rear=rear->next=new node(x);
}
template <class elemType>
elemType linkQueue <elemType>::deQueue()
{
    node *tmp=front;
    elemType x=front->data;
    front=front->next;
    if (front==NULL) rear=NULL;
    delete tmp;
    return x;
}
