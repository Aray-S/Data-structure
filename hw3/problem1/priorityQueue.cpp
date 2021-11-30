#include "priorityQueue.h"
void priorityQueue ::buildHeap()
{
    for (int i=currentSize/2; i>0; i--) percolateDown(i);
}
priorityQueue :: priorityQueue (const int *items, int size): maxSize(size+10), currentSize(size)
{
    array=new int [maxSize];
    for (int i=0; i<size; i++) array[i+1]=items[i];
    buildHeap();
}
void priorityQueue::enQueue (const int &x)
{
    if (currentSize==maxSize-1) doubleSpace();
    int hole=++currentSize;
    for (;hole>1&&x<array[hole/2]; hole/=2) array[hole]=array[hole/2];
    array[hole]=x;
}
int priorityQueue::deQueue ()
{
    int minItem=array[1], k=1;
    for (int i=1; i<currentSize+1; i++)
        if (array[i]<minItem)
        {
            minItem=array[i];
            k=i;
        }
    array[k]=array[currentSize--];
    percolateDown(k);
    return minItem;
}
void priorityQueue::percolateDown(int hole)
{
    int child, tmp=array[hole];
    for (;hole*2<=currentSize; hole=child)
    {
        child=hole*2;
        if (child!=currentSize&&array[child+1]<array[child]) child++;
        if (array[child]<tmp) array[hole]=array[child];
        else break;
    }
    array[hole]=tmp;
}
void priorityQueue::doubleSpace()
{
    int *tmp=array;
    maxSize*=2;
    array=new int [maxSize];
    for (int i=0; i<currentSize; ++i) array[i]=tmp[i];
    delete[]tmp;
}
int priorityQueue::findMin(int x)
{
    int min, k=0, s=-1;
    for (int i=1; i<currentSize+1; i++)
    {
        if ((array[i]>x||array[i]==x)&&k==0)
            {min=array[i]; k=1; s=i;}
        if ((array[i]>x||array[i]==x)&&k==1&&array[i]<min)
            {min=array[i]; s=i;}
    }
    return s;
}
int * priorityQueue::getArray()
{
    int *tmp=new int [currentSize];
    for (int i=0; i<currentSize; i++) tmp[i]=array[i+1];
    return tmp;
}
void priorityQueue :: decreaseKey (int i, int value)
{
    if (i==-1)
        {cout<<"Not found"<<endl; throw i;}
    if (value>array[i])
        {cout<<"Subtrahend is greater"<<endl; throw -1;}
    array[i]=array[i]-value;
    buildHeap();
}
