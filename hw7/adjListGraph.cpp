#include "adjListGraph.h"
adjListGraph::adjListGraph (int vSize)
{
    Vers=vSize; Edges=0;
    verList=new verNode[vSize];
}
adjListGraph::~adjListGraph ()
{
    edgeNode *p;
    for (int i=0; i<Vers; i++)
    while ((p=verList[i].head)!=NULL)
    {
        verList[i].head=p->next;
        delete p;
    }
    delete[] verList;
}
void adjListGraph::insert(int x, int y)
{
    ++Edges;
    verList[x].head=new edgeNode(y,verList[x].head);
}
void adjListGraph::remove(int x, int y)
{
    edgeNode *p=verList[x].head, *q;
    if (p==NULL) return;
    if (p->end==y)
    {
        verList[x].head=p->next;
        delete p; --Edges;
        return;
    }
    while (p->next!=NULL&&p->next->end!=y) p=p->next;
    if (p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        delete q;
        --Edges;
    }
}
bool adjListGraph::exist (int x, int y) const
{
    edgeNode *p=verList[x].head;
    while(p!=NULL&&p->end!=y) p=p->next;
    if (p==NULL) return false;
    else return true;
}
bool adjListGraph::existRoute (int start, int finish, bool visited[], string *route)
{
    edgeNode *p=verList[start].head;
    bool flag;
    visited[start]=true;
    do {(*route).insert((*route).length(), 1, start+'0');}
    while (start/10);
    (*route).insert((*route).length(), 1, ' ');
    while (p!=NULL)
    {
        if (p->end==finish)
        {
            do {(*route).insert((*route).length(), 1, finish+'0');}
            while (finish/10);
            (*route).insert((*route).length(), 1, ' ');
            return true;
        }
        if (visited[p->end]==false)
        {
            flag=existRoute (p->end, finish, visited, route);
            if (flag==true) return true;
        }
        p=p->next;
    }
    return false;
}
string adjListGraph::existRoute (int start, int finish)
{
    string route;
    bool *visited = new bool [Vers];
    for (int i=0; i<Vers; i++) visited[i]=false;
    if (existRoute (start, finish, visited, &route)) return route;
    else return "false";
}
string adjListGraph::topSort ()
{
    string sort;
    for (int i=0; i<Vers; i++)
        if (existRoute(i, i)!="false") return "loop";
    bool *visited=new bool [Vers];
    for (int i=0; i<Vers; i++) visited[i]=false;
    for (int i=0; i<Vers; i++)
    {
        if (visited[i]) continue;
        topSort(i, visited, &sort);
    }
    return sort;
}
void adjListGraph::topSort (int start, bool visited[], string *sort)
{
    edgeNode *p=verList[start].head;
    visited[start]=true;
    while (p!=NULL)
    {
        if (!visited[p->end]) topSort(p->end, visited, sort);
        p=p->next;
    }
    (*sort).insert(0, 1, ' ');
    do {(*sort).insert(0, 1, start+'0');}
    while (start/10);
}
