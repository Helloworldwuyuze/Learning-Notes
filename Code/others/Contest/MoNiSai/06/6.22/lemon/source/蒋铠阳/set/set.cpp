#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n;
int a[25];
ll ans;
int check(int p[]){
    for(int i=1;i<=n;++i){
        if(!p[i]) continue;
        if(p[i*2]+p[i*3]>0) return 0;
    }return 1;
}
void dfs(int x,int p[],int l){
    if(l==n){
        ans+=check(p);
        return ;
    }
    p[l+1]=1;
    dfs(x,p,l+1);
    p[l+1]=0;
    dfs(x,p,l+1);
}
signed main(){
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    dfs(1,a,0);
    cout<<ans<<endl;
    return 0;
}