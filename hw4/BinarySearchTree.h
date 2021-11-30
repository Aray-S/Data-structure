#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <iostream>
using namespace std;
struct SET
{
    int key;
    string value;
};
class BinarySearchTree
{
    private:
        struct BinaryNode
        {
            SET data;
            BinaryNode *left;
            BinaryNode *right;
            BinaryNode (const SET &thedata, BinaryNode *lt=NULL, BinaryNode *rt=NULL):data(thedata), left(lt), right(rt) {}
        };
        BinaryNode *root;
        void insert(const SET &x, BinaryNode *&t);
        void remove(const int &x, BinaryNode *&t);
        SET *find(const int &x, BinaryNode *t) const;
        void makeEmpty(BinaryNode *t);
        void midOrder (BinaryNode *t) const;
        void deleteRange (const int &a, const int &b, BinaryNode *&t);
        void deleteLess (const int &x, BinaryNode *&t);
        void deleteGreat (const int &y, BinaryNode *&t);
        int findMax (const int &i, BinaryNode *t) const;
    public:
        BinarySearchTree() {root=NULL;}
        ~BinarySearchTree() {makeEmpty(root);}
        SET *find(const int &x) const {return find(x, root); }
        void insert(const SET &x) {insert(x, root); }
        void remove(const int &x) {remove(x, root); }
        void midOrder () const {midOrder (root);}
        void deleteLess (const int &x);
        void deleteGreat (const int &y);
        void deleteRange (const int &a, const int &b);
        void great (int i, const int n) const;
};
#endif // BINARYSEARCHTREE_H_INCLUDED
