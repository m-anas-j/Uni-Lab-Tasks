#include<bits/stdc++.h>
using namespace std;
/*int graph[6][6]=
{
    0,0,0,0,0,0,
    0,0,1,6,0,0,
    0,1,0,2,3,5,
    0,6,2,0,4,2,
    0,0,3,4,0,2,
    0,0,5,2,2,0
};*/
int graph[9][9]=
{
    0,0,0,0,0,0,0,0,0,
    0,0,2,4,0,0,0,0,1,
    0,2,0,0,3,4,0,0,0,
    0,4,0,0,6,0,1,0,0,
    0,0,3,6,0,0,0,3,2,
    0,0,4,0,0,0,0,3,0,
    0,0,0,1,0,0,0,9,0,
    0,0,0,0,3,3,9,0,0,
    0,1,0,0,2,0,0,0,0
};
//int length[6]={99,99,1,6,99,99},visited[6]={1,0,0,0,0,0},parent[6]={0,0,1,1,0,0};
int length[9], visited[9], parent[9];
int chooseVertex()
{
    int tempLength=100,v;
    for (int i=1; i<=8; i++)
    {
        if (visited[i]==0)
        {
            if (length[i]<tempLength)
            {
                tempLength=length[i];
                v=i;
            }
        }
    }
    visited[v]=1;
    return v;
}
int checkVisited()
{
    int flag=0;
    for (int i=1;i<=8;i++)
    {
        if (visited[i]==0)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int main()
{
    cout<<"Insert the source vertex:\n";
    int v;
    cin>>v;
    visited[v]=1;
    for (int i=1; i<=8; i++)
    {
        if (graph[v][i]!=0)
        {
            length[i]=graph[v][i];
            parent[i]=v;
        }
        else
        {
            length[i]=99;
        }
    }
    length[v]=0;
    int newLength=length[v];
    while(1)
    {
        int vertex=chooseVertex();
        cout<<"Working with vertex "<<vertex<<endl;
        newLength=newLength+length[vertex];
        for (int i=1; i<=8; i++)
        {
            if (graph[vertex][i]!=0)
            {
                if (newLength+graph[vertex][i]<=length[i])
                {
                    length[i]=newLength+graph[vertex][i];
                    parent[i]=vertex;
                    cout<<"Length of vertex "<<i<<" with respect to vertex "<<vertex<<" is "<<length[i]<<endl;
                }
            }
        }
        newLength=length[v];
        if (checkVisited()==0)
            break;
    }
    cout<<"Enter destination node\n";
    int des;
    cin>>des;
    cout<<des<<"<-";
    cout<<parent[des]<<"<-";
    while(1)
    {
        des=parent[des];
        cout<<parent[des]<<"<-";
        if (des==v) break;
    }

}
