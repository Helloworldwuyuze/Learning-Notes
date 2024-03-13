#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e2 + 10;

#define pb push_back
int n,m,x,y,ans;
vector<int> g[N];
int f[N],in[N];

void topu(){
    queue<int> q;
    for(int i=1;i<=n;++i)
        for(vector<int>::iterator it=g[i].begin(); it!=g[i].end(); ++it){
            int j=*it;
            ++in[j];
        }
    for(int i=1;i<=n;++i)
        if(in[i]==0)    q.push(i), f[i]=-1;
    while(q.size()){
        int x=q.front(); q.pop();
        ++f[x]; ans=max(ans,f[x]);
        for(vector<int>::iterator it=g[x].begin(); it!=g[x].end(); ++it){
            int y=*it;
            f[y]=max(f[y],f[x]);
            --in[y];
            if(in[y]==0)    q.push(y);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i)   cin>>x>>y, g[x].pb(y);
    topu();
    cout<<ans<<endl;
    return 0;
}