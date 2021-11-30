#include "sLinkList.h"
template <class elemType>
void sLinkList <elemType> :: clear()
{
    node *p=head->next, *q;
    head->next=NULL;
    while (p!=NULL)
    {
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
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
template <class elemType>
void sLinkList <elemType> :: erase (const elemType &a, const elemType &b)
{
    int array[currentLength], i,  j, l=0;
    for (i=0; i<currentLength; i++)
        if ((visit(i)>a)&&(visit(i)<b))
        {
            array[i]=0;
            l++;
        }
        else array[i]=1;
    for (i=0, j=0; i<currentLength, j<l; i++)
        if (array[i]==0)
        {
            remove (i-j);
            j++;
        }
}
