#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
using namespace std;
class binaryTree
{
    private:
        int **array;
        int n;
    public:
        binaryTree (int initSize=10)
        {
            n=initSize;
            array=new int*[n];
            for (int i=0; i<n; i++) array[i]=new int [3];
        }
        void clear ()
        {
            for (int i = 0; i < n; i++)
            {
                delete []array[i];
                array[i] = NULL;
            }
            delete []array;
            array = NULL;
        }
        void createTree (int initSize, int **x)
        {
            clear();
            n=initSize;
            array=new int*[n];
            for (int i=0; i<n; i++) array[i]=new int [3];
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    array[i][j]=x[i][j];
        }
        int getHead () const
        {
            int *x=new int [n], k;
            for (int i=0; i<n; i++) x[i]=0;
            for (int i=0; i<n; i++)
                {
                    if (array[i][1]!=-1) x[array[i][1]]=1;
                    if (array[i][2]!=-1) x[array[i][2]]=1;
                }
            for (int i=0; i<n; i++)
                if (x[i]==0) k=i;
            delete [] x;
            x=NULL;
            return k;
        }
        void preOrderFunction (int *preOrder, int m, int k)
        {
            preOrder[m++]=array[k][0];
            if (array[k][1]!=-1) preOrderFunction (preOrder, m++, array[k][1]);
            if (array[k][2]!=-1) preOrderFunction (preOrder, m, array[k][2]);
        }
        void midOrderFunction (int *midOrder, int m, int k)
        {
            if (array[k][1]!=-1) midOrderFunction (midOrder, m++, array[k][1]);
            midOrder[m++]=array[k][0];
            if (array[k][2]!=-1) midOrderFunction (midOrder, m, array[k][2]);
        }
        void postOrderFunction (int *postOrder, int m, int k)
        {
            m++;
            if (array[k][1]!=-1) postOrderFunction (postOrder, m, array[k][1]);
            if (array[k][2]!=-1) postOrderFunction (postOrder, m, array[k][2]);
            postOrder[n-m]=array[k][0];
        }
        ~binaryTree () {clear(); n=0;}
};
#endif // BINARYTREE_H_INCLUDED
