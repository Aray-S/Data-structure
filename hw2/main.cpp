#include<iostream>
#include "binaryTree.h"
using namespace std;

void preorder_tranversal(int num, int** nodes, int* preOrder) {
    binaryTree tree;
    tree.createTree(num, nodes);
    int k=tree.getHead();
    tree.preOrderFunction (preOrder, 0, k);
}

void midorder_tranversal(int num, int** nodes, int* midOrder) {
    binaryTree tree;
    tree.createTree(num, nodes);
    int k=tree.getHead();
    tree.midOrderFunction (midOrder, 0, k);
}

void postorder_tranversal(int num, int** nodes, int* postOrder) {
    binaryTree tree;
    tree.createTree(num, nodes);
    int k=tree.getHead();
    tree.postOrderFunction (postOrder, 0, k);
}

// main cannot be modified
int main(){

    // initialize
    int num;
    cin>>num;
    int **nodes = new int*[num];
    for(int i =0; i < num; i++) {
        nodes[i] = new int[3];
    }
    for(int i = 0;i < num; i++){
        for(int j = 0;j < 3;j++){
            cin>>nodes[i][j];
        }
    }

    //use preOrder, midOrder, postOrder store the results
    int *preOrder = new int[num];
    int *midOrder = new int[num];
    int *postOrder = new int[num];

    // should be finished
    preorder_tranversal(num, nodes, preOrder);
    midorder_tranversal(num, nodes, midOrder);
    postorder_tranversal(num, nodes, postOrder);

    // output the results
    // print preOrder results
    for(int i = 0;i < num; i++){
        cout<<preOrder[i]<<' ';
    }
    cout<<endl;
    // print midOrder results
    for(int i = 0;i < num; i++){
        cout<<midOrder[i]<<' ';
    }
    cout<<endl;
    // print postOrder results
    for(int i = 0;i < num; i++){
        cout<<postOrder[i]<<' ';
    }
    cout<<endl;

    // free memory
    for (int i = 0; i < num; i++)
    {
        delete []nodes[i];
        nodes[i] = NULL;
    }
    delete []nodes;
    nodes = NULL;
    delete []preOrder;
    preOrder = NULL;
    delete []midOrder;
    midOrder = NULL;
    delete []postOrder;
    postOrder = NULL;

    return 0;
}
