//new year transportation
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t; 
    cin >> n >> t;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++ ){
        if(i==t){
            ans = true;
            break;
        }
        i = i +a[i]-1;
        cout << i << endl;
    }
    if(ans)cout<<"YES\n";
    else cout <<"NO\n";
}

