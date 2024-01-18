#include<bits/stdc++.h>
using namespace std;

vector <int> bfs_adjlist(int n, vector <vector<int>> &adj_list){
    vector <int> bfs_trav;
    vector <int> visited(n,-1);
    
    for(int i = 0; i < n; i++){
        if(visited[i]==1){
            continue;
        }
        queue <int> q;
        int source  = i;
        q.push(source);
        visited[source] = 1;
        while(q.empty()!=0){
            int cur_node = q.front();
            q.pop();
            bfs_trav.push_back(cur_node);
            for(auto it: adj_list[cur_node]){
                if(visited[it]==-1){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    return bfs_trav;
}

vector <int> dfs_adjlist(int n, vector <vector <int>> &adj_list){
    vector <int> dfs_trav;
    vector <int> visited(n,-1);
    for(int i = 0; i < n; i++){
        if(visited[i]==1){
            continue;
        }
        stack <int> st;
        int source  = i;
        st.push(source);
        visited[source] = 1;
        while(st.empty()!=0){
            int cur_node = st.top();
            st.pop();
            dfs_trav.push_back(cur_node);
            for(auto it: adj_list[cur_node]){
                if(visited[it]==-1){
                    st.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    return dfs_trav;
}

vector <pair<int,int>> bfs_matrix(int row, int col, vector <vector<int>> &matrix){
    int total_nodes = row*col;
    vector <pair<int,int>> bfs_trav;
    vector <vector<int>> visited(row,vector <int> (col,-1));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(visited[i][j]==1){
                continue;
            }
            queue <pair<int,int>> q;
            int source_row  = i;
            int source_col = j;
            q.push(make_pair(source_row, source_col));
            visited[source_row][source_col] = 1;
            vector <int> tr{1,-1,0,0};
            vector <int> tc{0,0,-1,1};
            while(q.empty()!=0){
                pair<int,int> cur_node = q.front();
                q.pop();
                bfs_trav.push_back(cur_node);
                for(int k = 0; k < tr.size(); k++){
                    int new_row = cur_node.first + tr[k];
                    int new_col = cur_node.second + tc[k];
                    if(0 <= new_row && new_row < row && 0 <= new_col && new_col < col ){
                        pair<int,int> next_node = make_pair(new_row,new_col);
                        if(visited[new_row][new_col]==-1){
                            q.push(next_node);
                            visited[new_row][new_col]=1;
                        }
                    }
                }
            }
        }
    }
    return bfs_trav;
}

vector <pair<int,int>> dfs_matrix(int row, int col, vector <vector<int>> &matrix){
    int total_nodes = row*col;
    vector <pair<int,int>> dfs_trav;
    vector <vector<int>> visited(row,vector <int> (col,-1));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(visited[i][j]==1){
                continue;
            }
            stack <pair<int,int>> st;
            int source_row  = i;
            int source_col = j;
            st.push(make_pair(source_row, source_col));
            visited[source_row][source_col] = 1;
            vector <int> tr{1,-1,0,0};
            vector <int> tc{0,0,-1,1};
            while(st.empty()!=0){
                pair<int,int> cur_node = st.top();
                st.pop();
                dfs_trav.push_back(cur_node);
                for(int i = 0; i < tr.size(); i++){
                    int new_row = cur_node.first + tr[i];
                    int new_col = cur_node.second + tc[i];
                    if(0 <= new_row && new_row < row && 0 <= new_col && new_col < col ){
                        pair<int,int> next_node = make_pair(new_row,new_col);
                        if(visited[new_row][new_col]==-1){
                            st.push(next_node);
                            visited[new_row][new_col]=1;
                        }
                    }
                }
            }
        }
    }
    return dfs_trav;
}



int main(){
    
}