#include "BinarySearchTree.h"
SET *BinarySearchTree::find(const int &x, BinaryNode *t) const
{
    if (t==NULL||t->data.key==x) return (SET *)t;
    if (x<t->data.key) return find(x, t->left);
    else return find (x, t->right);
}
void BinarySearchTree::insert(const SET &x, BinaryNode *&t)
{
    if (t==NULL) t=new BinaryNode(x, NULL, NULL);
    else if (x.key<t->data.key) insert(x, t->left);
         else if (x.key>t->data.key) insert(x, t->right);
}
void BinarySearchTree::remove(const int &x, BinaryNode *&t)
{
    if (t==NULL) return;
    if (x<t->data.key) remove(x, t->left);
    else if (t->data.key<x) remove(x, t->right);
         else if (t->left!=NULL&&t->right!=NULL)
              {
                  BinaryNode *tmp=t->right;
                  while (tmp->left!=NULL) tmp=tmp->left;
                  t->data=tmp->data;
                  remove(t->data.key, t->right);
              }
              else
              {
                  BinaryNode *oldNode=t;
                  t=(t->left!=NULL)?t->left:t->right;
                  delete oldNode;
              }
}
void BinarySearchTree::makeEmpty(BinaryNode*t)
{
    if (t==NULL) return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}
void BinarySearchTree::midOrder(BinaryNode *t) const
{
    if (t==NULL)return;
    midOrder (t->left);
    cout<<t->data.key<<' ';
    midOrder (t->right);
}
void BinarySearchTree::deleteRange (const int &a, const int &b)
{
    if (b<a)
    {
        cout<<"Invalid range"<<endl;
        return;
    }
    deleteRange (a, b, root);
    midOrder();
    cout<<endl;
}
void BinarySearchTree::deleteRange (const int &a, const int &b, BinaryNode *&t)
{
    if (t==NULL) return;
    if (t->data.key<a) deleteRange (a, b, t->right);
    else if (t->data.key>b) deleteRange (a, b, t->left);
         else
         {
             remove (t->data.key, t);
             deleteRange (a, b, t);
         }
}
void BinarySearchTree::deleteLess (const int &x)
{
    deleteLess (x, root);
    midOrder();
    cout<<endl;
}
void BinarySearchTree::deleteLess (const int &x, BinaryNode *&t)
{
    if (t==NULL) return;
    if (t->data.key<x)
    {
        BinaryNode *tmp=t;
        t=t->right;
        makeEmpty(tmp->left);
        delete tmp;
        deleteLess(x, t);
    }
    else deleteLess (x, t->left);
}
void BinarySearchTree::deleteGreat (const int &y)
{
    deleteGreat (y, root);
    midOrder();
    cout<<endl;
}
void BinarySearchTree::deleteGreat (const int &y, BinaryNode *&t)
{
    if (t==NULL) return;
    if (t->data.key>y)
    {
        BinaryNode *tmp=t;
        t=t->left;
        makeEmpty(tmp->right);
        delete tmp;
        deleteGreat(y, t);
    }
     else deleteGreat (y, t->right);
}
int BinarySearchTree::findMax (const int &i, BinaryNode *t) const
{
    if (i<t->data.key) findMax (i, t->left);
    else if (t->right->data.key==i)
            if (t->right->left==NULL) return t->data.key;
            else
            {
                BinaryNode *tmp=t->right->left;
                while (tmp->right!=NULL) tmp=tmp->right;
                return tmp->data.key;
            }
          else if (t->right->left!=NULL&&t->right->left->data.key==i) return t->data.key;
               else findMax (i, t->right);
}
void BinarySearchTree::great (int i, const int n) const
{
    if (i>n)
    {
        cout<<"Invalid value of i"<<endl;
        return;
    }
    BinaryNode*tmp=root;
    while (tmp->right!=NULL) tmp=tmp->right;
    int k=tmp->data.key;
    while ((--i)!=0) k=findMax (k, root);
    cout<<k<<endl;
}
