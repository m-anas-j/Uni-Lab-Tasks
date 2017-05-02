#include<bits/stdc++.h>
using namespace std;
int visited[16], origin[16],org=1;
int graph2[16][16]=
{
//  0 1 2 3 4 5 6 7 8 9 101112131415
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,
    0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,
    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
    0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
    0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,
    0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
};
char characters[11]={'n','q','r','s','t','u','v','w','x','y','z'};
int graph1[11][11]=
{
//  0 1 2 3 4 5 6 7 8 9 10
    0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,1,0,0,0,1,0,0,0,
    0,0,0,0,0,1,0,0,0,1,0,
    0,0,0,0,0,0,1,0,0,0,0,
    0,0,0,0,0,0,0,0,1,1,0,
    0,0,0,0,0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,1,0,0,0,
    0,0,0,0,0,0,0,0,0,0,1,
    0,0,0,0,0,0,0,0,0,0,1,
    0,1,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,1,0,0
};
int graph[16][16];
int frnt, rear, sz=100, que[100];
void enque(int num)
{
    if (frnt==0)
    {
        frnt=1;
        rear=1;
    }
    else rear++;
    que[rear]=num;
    cout<<"Inserted "<<que[rear]<<" Front value: "<<frnt<<" Rear value: "<<rear<<endl;
}
int deq()
{
    int temp;
    if (frnt==0)
        {
            cout<<"Queue is empty\n";
            temp=123;
            return 123;
        }
    else
    {
        temp=que[frnt];
        frnt++;
        cout<<"Dequed "<<temp<<" front value: "<<frnt<<"rear value: "<<rear<<endl;
        return temp;
    }

}
int main()
{
    cout<<"Which graph would you like to perform bfs on?\n1. Graph 01\n2. Graph 02\n";
    int choice;
    cin>>choice;
    if (choice==1)
    {
        for (int i=1;i<=15;i++)
        {
            for (int j=1;j<=15;j++)
            {
                graph[i][j]=graph1[i][j];
            }
        }
    }
    else
    {
        for (int i=1;i<=10;i++)
        {
            for (int j=1;j<=10;j++)
            {
                graph[i][j]=graph2[i][j];
            }
        }
    }
    int start, ending, done;
    cout<<"Enter the starting node\n";
    cin>>start;
    cout<<"Enter the ending node\n";
    cin>>ending;
    enque(start);
    visited[start]=1;
    origin[start]=0;
    org++;
    start=deq();
    while(1)
    {
        int flag=0;
        for (int j=1;j<=15;j++)
        {
            if (graph[start][j]==1 && visited[j]==0)
                {
                    enque(j);
                    origin[org]=start;
                    org++;
                    visited[j]=1;
                    if (j==ending)
                    {
                        flag=1;
                        break;
                    }
                }
        }
        if (flag==1) break;
        start=deq();
        if (start==123)
        {
            cout<<"Path doesn't exist.\n";
            break;
        }
    }
    cout<<"front: "<<frnt<< "rear: "<<rear<<endl;
    cout<<que[rear]<<"<-";
    int i=origin[rear];
    while(1)
    {
        cout<<i<<"<-";
        for (int t=1;t<16;t++)
        {
            if (que[t]==i)
            {
                i=origin[t];
                break;
            }
        }
        if (i==0) break;
    }
    cout<<"Start";
}
