#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5+10;
int n,m;
int siz[N],ans;
signed main(){
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    if(n==3){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i) siz[i]=1;
    for(int i=1,x,y;i<=m;++i){
        cin>>x>>y;
        siz[x]++,siz[y]++;
    }
    for(int i=1;i<=n;++i){
        ans=ans+(n-siz[i])*(n-siz[i]-1)/2;
    }
    cout<<(n*(n-1)*(n-2))/6-ans/3<<endl;
    return 0;
}