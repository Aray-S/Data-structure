#ifndef SLINKSTRING_H_INCLUDED
#define SLINKSTRING_H_INCLUDED
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
template <class elemType>
class sLinkList
{
    private:
        struct node {
            elemType data;
            node *next;
            node(const elemType &x, node *n=NULL) {data=x; next=n;}
            node():next(NULL) {}
            ~node(){}
        };
        node *head, *commonMember;
        int currentLength;
        node *move(int i) const
        {
            node *p=head;
            while (i-->=0) p=p->next;
            return p;
        }
    public:
        sLinkList() {head=new node; currentLength=0;}
        ~sLinkList() {clear(); delete head;}
        void clear();
        int length() const {return currentLength;}
        void insert(int i, const elemType &x);
        void insert (const elemType &x) {insert (currentLength, x); }
        void remove(int i);
        elemType visit(int i) const {return move(i)->data;}
        void traverse() const;
        void add (const node *p);
        node *get_head () const {return head;}
        void print () const {for (node *p=commonMember; p!=NULL; p=p->next) cout<<p->data;}
};


#endif // SLINKSTRING_H_INCLUDED
