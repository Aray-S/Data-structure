#include "sLinkList.h"
#include "sLinkList.cpp"
int main()
{
    int x, y, n;
    sLinkList <int> List;
     while (cin.peek()!='\n')
    {
        cin>>n;
        List.insert(n);
    }
    cin>>x>>y;
    List.erase (x, y);
    cout<<List.length();
    List.traverse();
    return 0;
}
