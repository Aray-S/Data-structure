#ifndef ADJLISTGRAPH_H_INCLUDED
#define ADJLISTGRAPH_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;
class adjListGraph
{
    private:
        struct edgeNode
        {
            int end;
            edgeNode *next;
            edgeNode (int e, edgeNode *n=NULL) {end=e; next=n;}
        };
        struct verNode
        {
            edgeNode *head;
            verNode (edgeNode *h=NULL) {head=h;}
        };
        verNode *verList;
        bool existRoute (int start, int finish, bool visited[], string *route);
        void topSort(int start, bool visited[], string *sort);
    protected:
        int Vers, Edges;
    public:
        adjListGraph (int vSize);
        void insert (int x, int y);
        void remove (int x, int y);
        bool exist (int x, int y) const;
        int numOfVer()const {return Vers;}
        int numOfEdge() const {return Edges;}
        ~adjListGraph ();
        string existRoute (int start, int finish) ;
        string topSort ();
};
#endif // ADJLISTGRAPH_H_INCLUDED
