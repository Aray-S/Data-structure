#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
    int N, a, b, x, y, i;
    cin>>N;
    SET *array=new SET [N];
    BinarySearchTree tree;
    for (int j=0; j<N; j++) cin>>array[j].key>>array[j].value;
    cin>>i; cin>>a>>b; cin>>x; cin>>y;
    for (int j=0; j<N; j++) tree.insert(array[j]);
    tree.great(i, N);
    tree.deleteRange(a, b);
    tree.deleteLess(x);
    tree.deleteGreat(y);
    return 0;
}
