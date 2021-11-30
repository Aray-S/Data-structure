#include "sLinkString.h"
template <class elemType>
void sLinkList <elemType> :: clear()
{
    node *p=head->next, *q;
    head->next=NULL;
    while (p!=NULL){
        q=p->next;
        delete p;
        p=q;
        }
    currentLength=0;
}
template <class elemType>
void sLinkList <elemType> :: insert(int i, const elemType &x)
{
    node *pos;
    pos=move(i-1);
    pos->next=new node(x, pos->next);
    ++currentLength;
}
template <class elemType>
void sLinkList <elemType> :: remove(int i)
{
    node *pos, *delp;
    pos=move(i-1);
    delp=pos->next;
    pos->next=delp->next;
    delete delp;
    --currentLength;
}
template <class elemType>
void sLinkList <elemType> :: traverse() const
{
    node *p=head->next;
    cout<<endl;
    while (p!=NULL)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}
template <class elemType>
void sLinkList <elemType> :: add (const node *p)
{
    node *delp=head->next;
    while (delp->next!=NULL) {delp=delp->next;}
    delp->next=p->next;
    commonMember=p->next;
}
