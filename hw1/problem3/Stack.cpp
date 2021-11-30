#include "Stack.h"
template <class elemType>
linkStack <elemType>::~linkStack()
{
    node *tmp;
    while (top_p!=NULL){
        tmp=top_p;
        top_p=top_p->next;
        delete tmp;
    }
}
template <class elemType>
elemType linkStack <elemType>::pop()
{
    node *tmp=top_p;
    elemType x=tmp->data;
    top_p=top_p->next;
    delete tmp;
    return x;
}

