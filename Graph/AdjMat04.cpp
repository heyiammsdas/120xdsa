#include <iostream> 
#include <algorithm>
#include <climits> 
#include <vector> 

using namespace std ;

int main() { 
      int vertex , edges ;

    cin>>vertex>>edges ;

    vector < vector < int > > adjMat(vertex , vector<int> (vertex , 0)) ;

    for(int i=0 ; i<edges ; i++){

        int v , u , weight;
        cin>>v >> u >> weight  ;

        adjMat[u][v]  = weight ;
        

       
        


    }



    for(int i = 0; i<vertex ; i++){
        for(int j = 0 ; j<vertex ; j++){

            cout<<adjMat[i][j] <<" " ;


        }
        cout<<endl; 
        

    }



}