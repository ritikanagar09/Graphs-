#include<unordered_map>
#include<list>
#include<queue>
#include<set>

// we have used set in order to print the ansewr in sorted format
void prepareAdjList(unordered_map<int, set<int>>&adjList, vector<pair<int, int>> &edges){
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void printList(unordered_map<int, set<int>>&adjList){
    for(auto i:adjList){
        cout<<i.first<<" ->";
        for(auto j:i.second){
            cout<<j<<" ,";
        }
        cout<<endl;
    }
}
void bfs(unordered_map<int, set<int>>&adjList,unordered_map<int, bool>&visited, vector<int> &ans , int node ){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    
    
    while(!q.empty()){
        int frontNode= q.front();
        q.pop();
        
        //  store frontNode into ans
        ans.push_back(frontNode);
        for(auto i: adjList[frontNode])// ki mere frontNode ke saamne jo vector padha h
        {
            if(!visited[i]){
                
                q.push(i);
                visited[i]=1;
            }
        }
    }
    
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>>adjList;
    vector<int> ans;
    unordered_map<int, bool>visited;
    
    
    prepareAdjList(adjList, edges);
//     printList(adjList);
    
    // tarversse all component of graph 
    for(int i=0;i<vertex;i++){
//         cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        if(!visited[i]){// agar meri node visted nhi h,,toh hum bfs call kardenge 
            bfs(adjList, visited,ans, i);
        }
    }
    
    return ans;
    
}
