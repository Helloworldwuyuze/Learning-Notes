#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 10;
const int M = 1e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,x,y,f[N][2];
vector<int> g[N];

void dfs(int x,int fa){
    f[x][0]=f[x][1]=1;
    for(vector<int>::iterator it=g[x].begin(); it!=g[x].end(); ++it){
        int y=(*it);
        if(y==fa)   continue;
        dfs(y,x);
        f[x][0]=f[x][0]*(f[y][0]+f[y][1])%MOD;
        f[x][1]=(f[x][1]*f[y][0])%MOD;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<n;++i)    cin>>x>>y, g[x].push_back(y), g[y].push_back(x);
    dfs(1,0);
    cout<<(f[1][0]+f[1][1])%MOD<<endl;
    return 0;
}