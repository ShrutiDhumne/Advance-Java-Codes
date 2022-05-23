// Name: Shruti Deepak Dhumne           Batch: E1
// Roll: 227        PRN: 0220200161     Assignment_4 (Prims Algorithm)

#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
class MSTPrims{
    public:
    void Prims_MST();
};
void MSTPrims :: Prims_MST(){
    int V,i,j,x,y,min;
    int nodes, max_edges, weight,cost = 0;
    min=INFINITY;
    x = 0;
    y = 0;
    cout<<"\nEnter number of nodes : ";
    cin>>V;
    int adj[V][V];
    int selected[V*V];
    memset(selected, false, sizeof(selected));
    int no_edge = 0;
    selected[0] = true;
    cout<<endl;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            cout<<"Enter Weight for Edge : "<<i<<"--"<<j<<" : ";
            cin>>adj[i][j];
        }
    }
    cout<<"\nAdjacency Matrix --> \n";
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<"\n";
    }
    for(i=0;i<V;i++){
        if(selected[i]==true)
        for(j=0;j<V;j++){
            if(selected[j]==false && adj[i][j]!=0){
                if(min>adj[i][j]){
                    min=adj[i][j];
                    x=i;
                    y=j;
                }
            }
        }
    }
    cout<<"\nPrims Algorithm --> \n";
    while (no_edge < V - 1){
    int min = INFINITY;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++){
      if (selected[i]){
        for (int j = 0; j < V; j++){
          if (!selected[j] && adj[i][j]){                   // not in selected and there is an edge
            if (min > adj[i][j]){
              min = adj[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << adj[x][y];
    cost = cost + adj[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }
  cout<<"\nCost --> "<<cost<<endl;
}
int main(){
   MSTPrims M;
   M.Prims_MST();
   return 1;
}
/*
************************************OUTPUT********************************
Enter number of nodes : 4

Enter Weight for Edge : 0--0 : 0
Enter Weight for Edge : 0--1 : 2
Enter Weight for Edge : 0--2 : 3
Enter Weight for Edge : 0--3 : 4
Enter Weight for Edge : 1--0 : 2
Enter Weight for Edge : 1--1 : 0
Enter Weight for Edge : 1--2 : 0
Enter Weight for Edge : 1--3 : 3
Enter Weight for Edge : 2--0 : 3
Enter Weight for Edge : 2--1 : 0
Enter Weight for Edge : 2--2 : 0
Enter Weight for Edge : 2--3 : 4
Enter Weight for Edge : 3--0 : 4
Enter Weight for Edge : 3--1 : 3
Enter Weight for Edge : 3--2 : 4
Enter Weight for Edge : 3--3 : 0

Adjacency Matrix -->
0       2       3       4
2       0       0       3
3       0       0       4
4       3       4       0

Prims Algorithm -->
0 - 1 :  2
0 - 2 :  3
1 - 3 :  3

Cost --> 8

*/
