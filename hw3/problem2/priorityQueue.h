#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED
#include <iostream>
using namespace std;
class priorityQueue
{
    private:
        int currentSize;
        int *array;
        int maxSize;
        void doubleSpace ();
        void buildHeap ();
        void percolateDown (int hole);
    public:
        priorityQueue (int capacity=100)
        {
            array = new int [capacity];
            maxSize=capacity;
            currentSize=0;
        }
        priorityQueue (const int data[], int size);
        ~priorityQueue () {delete [] array;}
        bool isEmpty () const {return currentSize==0;}
        void enQueue (const int &x);
        int deQueue();
        int getHead () const {return array[1];}
        int findMin (int x);
        void decreaseKey (int i, int value);
};
#endif // PRIORITYQUEUE_H_INCLUDED
