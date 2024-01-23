//rumor
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
    vector <int> charge(n);
    for(int i = 0; i < n; i++){
        cin >> charge[i];
    }
    vector <vector <int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    long long ans = 0;
    vector<int> visited(n,-1);
    for(int i = 0; i < n; i++){
        if(visited[i]==1){
            continue;
        }
        stack <int> st;
        st.push(i);
        visited[i] = 1;
        int minm = charge[i];
        while(!st.empty()){
            int cur_node = st.top();
            st.pop();
            for(auto it: adj[cur_node]){
                if(visited[it]==-1){
                    visited[it]=1;
                    if(charge[it] < minm){
                        minm = charge[it];
                    }
                    st.push(it);
                }
            }
        }
        ans+=minm;
    }
    cout << ans << endl;
}