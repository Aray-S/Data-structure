#include "sLinkString.h"
#include "sLinkString.cpp"
int main()
{
    sLinkList <char> a, b, c;
    string a1, b1;
    cin>>a1>>b1;
    for (int i=0; i<a1.length(); i++)
        {
            if (a1[i]>='A'&&a1[i]<='Z') a1[i]=a1[i]-'A'+'a';
            a.insert(a1[i]);
        }
    for (int i=0; i<b1.length(); i++)
        {
            if (b1[i]>='A'&&b1[i]<='Z') b1[i]=b1[i]-'A'+'a';
            b.insert(b1[i]);
        }
    int i=a.length()-1, j=b.length()-1;
    while (i--!=0&&j--!=0)
        if (a.visit(i)==b.visit(j)) {b.remove(j);}
        else break;
    for (int k=i+1; k<a.length(); k++) c.insert (a.visit(k));
    for (int k=a.length()-1; k>i; k--) a.remove(k);
    a.add (c.get_head()); b.add(c.get_head());
    a.print ();
    return 0;
}

