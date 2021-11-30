#include<iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;
void find_path(int n, int row, int col, int** maze, int** visited, int** way, linkQueue<int>& plan){
    if(!visited[row][col])
    {
        if ((row+1) < n && (row+1) >= 0 && !visited[row+1][col] && (maze[row+1][col] == 0 || (row+1==n-1&&col==n-1)))
        {
            way[row+1][col] = way[row][col] + 1;
            plan.enQueue(row+1);
            plan.enQueue(col);
        }
        if((row-1) < n && (row-1) >= 0 && !visited[row-1][col] && (maze[row-1][col] == 0 || (row-1==n-1&&col==n-1)))
        {
            way[row-1][col] = way[row][col] + 1;
            plan.enQueue(row-1);
            plan.enQueue(col);
        }
        if((col + 1) < n && (col + 1) >= 0 && !visited[row][col+1] && (maze[row][col+1] == 0 || (row==n-1&&col+1==n-1)))
        {
            way[row][col+1] = way[row][col] + 1;
            plan.enQueue(row);
            plan.enQueue(col+1);
        }
        if((col - 1) < n && (col - 1) >= 0 && !visited[row][col-1] && (maze[row][col-1] == 0 || (row==n-1&&col-1==n-1)))
        {
            way[row][col-1] = way[row][col] + 1;
            plan.enQueue(row);
            plan.enQueue(col-1);
        }
        visited[row][col] = 1;
    }
}

bool find_shortest_path(int** maze, int N, int** path, int& path_length)
{
    linkQueue <int> plan;
    int x, y;
    int **way=new int *[N];
    int **visited=new int *[N];
    for (int i=0; i<N; i++)
    {
        visited[i]=new int[N];
        way[i]=new int[N];
    }
    for(int i = 0;i < N; i++)
        for(int j = 0;j < N;j++)
            {
                visited[i][j]=0;
                way[i][j]=0;
            }
    way[0][0]=1;
    plan.enQueue(0); plan.enQueue(0);
    while(!plan.isEmpty())
    {
        x=plan.getHead();
        plan.deQueue();
        y=plan.getHead();
        plan.deQueue();
        find_path(N, x, y, maze, visited, way, plan);
    }
    if(!visited[N-1][N-1]) return false;
    else
    {
        path_length=way[N-1][N-1];
        int k=path_length-1;
        x = N-1; y = N-1;
        path[0][k]=x; path[1][k--]=y;
        while (way[x][y]!= 1)
        {
            if ((x-1) >= 0 && (x-1) < N && (way[x-1][y] == way[x][y] - 1))
            {
                x = x-1;
                path[0][k]=x; path[1][k--]=y;
            }
            else
                if ((x+1) >= 0 && (x+1) < N && (way[x+1][y] == way[x][y] - 1))
                {
                    x = x+1;
                    path[0][k]=x; path[1][k--]=y;
                }
                else
                    if ((y-1) >= 0 && (y-1) < N && (way[x][y-1] == way[x][y] - 1))
                    {
                        y = y-1;
                        path[0][k]=x; path[1][k--]=y;
                    }
                    else
                        if ((y+1) >= 0 && (y+1) < N && (way[x][y+1] == way[x][y] - 1))
                        {
                            y = y+1;
                            path[0][k]=x; path[1][k--]=y;
                        }
        }
        return true;
    }
}

// main cannot be modified
int main() {
    // initialize
    int N;
    cin>>N;
    int **maze = new int*[N];
    for(int i =0; i < N; i++) {
        maze[i] = new int[N];
    }
    for(int i = 0;i < N; i++){
        for(int j = 0;j < N;j++){
            cin>>maze[i][j];
        }
    }

    // path should be an array of size [2][path_length]
    int **path = new int*[2];
    int path_length = 0;

    // should be finished
    if(find_shortest_path(maze, N, path, path_length)){
        for(int i = 0;i < path_length; i++){
            //path[0][i]: row
            //path[1][i]: column
            cout<<'('<<path[0][i]<<','<<path[1][i]<<')';
        }
        cout<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

    // free memory
    for (int i = 0; i < N; i++)
    {
        delete []maze[i];
        maze[i] = NULL;
    }
    delete []maze;
    maze = NULL;
    for (int i = 0; i < 2; i++)
    {
        delete []path[i];
        path[i] = NULL;
    }
    delete []path;
    path = NULL;

    return 0;
}

