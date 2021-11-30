#include <iostream>
#include <cstring>
#include "adjListGraph.h"
using namespace std;
int main()
{
    int N, start, end, k=0; string line;
    cin>>N; cin.get(); getline(cin, line); cin>>start>>end;
    adjListGraph graph(N);
    while (line[k]!='\0')
        if (line[k]=='<')
            {
                int i=line[++k]-'0';
                while(line[k+1]!=',') i=(line[++k]-'0')+i*10;
                k+=2;
                int j=line[k]-'0';
                while(line[k+1]!='>') j=(line[++k]-'0')+j*10;
                graph.insert (i, j);
            }
        else k++;
    cout<<graph.existRoute(start, end);
    cout<<endl;
    cout<<graph.topSort();
    return 0;
}
