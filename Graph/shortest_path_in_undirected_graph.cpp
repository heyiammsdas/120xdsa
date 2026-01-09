#include<iostream>
#include<string> 
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std ;

vector<int>shortestPath(int V ,vector<vector<int>>&edges , int src ) {
   // making adjacency list 

   vector<vector<int>>adjList(V) ;
        
   for(auto edge : edges) {
            int u = edge[0] ;
            int v = edge[1] ;          
            adjList[u].push_back(v) ;
            adjList[v].push_back(u) ;
   }

   // creating dist and visited array

   vector<int> dist(V , -1) ;
   vector<bool> visited(V , false ) ;

   queue<int> q; 
   q.push(src) ;

   visited[src] = true ;
   dist[src] = 0 ;

   while(!q.empty()) {
    
    int current = q.front() ;
    q.pop() ;

    for(auto &neighbor : adjList[current]) {
      if(!visited[neighbor]) {
        visited[neighbor] = true ;
        dist[neighbor] = dist[current] + 1 ;
        q.push(neighbor) ;
      }
    }
   }
   return dist ;
}
int main() {
  int V = 9 ;
  int src = 0 ;
  vector<vector<int>>edges = {{0, 1}, {0, 3}, {1, 2}, {3, 4}, {4, 5}, {2, 6}, {5, 6}, {6, 7}, {6, 8}, {7, 8}} ;
  vector<int> ans = shortestPath(V , edges , src) ;
 for(int i=0 ; i<ans.size() ; i++) {
  cout<<i<<" "<<ans[i]<<endl; 
 }
}
