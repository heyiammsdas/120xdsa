#include <iostream>
#include <vector> 
#include <string> 
#include <queue> 
#include <algorithm> 
#include <limits.h>
using namespace std;

int main() {

    int V = 5;   // number of vertices

    vector<vector<pair<int,int>>> adj(V);

    // -------- Hardcoded edges --------
    // Graph:
    // 0 → 1 (2)
    // 0 → 2 (4)
    // 1 → 2 (1)
    // 1 → 3 (7)
    // 2 → 4 (3)
    // 3 → 4 (1)

    adj[0].push_back({1,2});
    adj[0].push_back({2,4});

    adj[1].push_back({0,2});
    adj[1].push_back({2,1});
    adj[1].push_back({3,7});

    adj[2].push_back({0,4});
    adj[2].push_back({1,1});
    adj[2].push_back({4,3});

    adj[3].push_back({1,7});
    adj[3].push_back({4,1});

    adj[4].push_back({2,3});
    adj[4].push_back({3,1});
    // ---------------------------------

    int source = 0;
    vector<int>dist(V , INT_MAX) ;
    vector<bool> visited(V , false ) ;

    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
    pq.push({0 , source}) ;
    dist[source] = 0 ;

    while(!pq.empty()) {
        int node = pq.top().second ;
        pq.pop() ;

        if(visited[node]) continue ;

        visited[node] = true ;

        for(auto &ele : adj[node]) {
             int neighbor = ele.first ;
             int weight = ele.second ;

             if(dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight ;
                pq.push({dist[neighbor] , neighbor}) ;
             }
        }


    }





    cout << "Shortest distances from source " << source << ":\n";
    for(int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }

    return 0;
}
