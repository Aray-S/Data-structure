#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
template <class elemType>
class stack
{
    public:
        virtual bool isEmpty() const=0;
        virtual void push(const elemType &x)=0;
        virtual elemType pop()=0;
        virtual elemType top() const=0;
        virtual ~stack() {}
};
template <class elemType>
class linkStack: public stack <elemType>
{
    private:
        struct node {
        elemType data;
        node *next;
        node(const elemType &x, node *N=NULL) {data=x; next=N;}
        node():next(NULL) {}
        ~node() {}
        };
        node *top_p;
        void check();
    public:
        linkStack() {top_p=NULL;}
        ~linkStack();
        bool isEmpty() const {return top_p==NULL;}
        void push(const elemType &x) {top_p=new node(x, top_p);}
        elemType pop();
        elemType top() const {return top_p->data;}
        int top_prior(){return prior(top_p->data);}
        int prior(char x)
        {
            if ((x=='*')||(x=='/')) return 2;
            if ((x=='+')||(x=='-')) return 1;
            if ((x=='(')||(x==')')) return 0;
        }
};
#endif // STACK_H_INCLUDED
