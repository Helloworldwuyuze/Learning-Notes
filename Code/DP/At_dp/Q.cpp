#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e5 + 10;
const int M = 5e6 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n,h[N],a[N],f[N];

int bit[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))    bit[i]=max(bit[i],k);}
int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))    ans=max(bit[i],ans); return ans;}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>h[i];
    for(int i=1;i<=n;++i)   cin>>a[i];
    f[1]=a[1];
    update(h[1],f[1]);
    for(int i=2;i<=n;++i){
        f[i]=query(h[i]-1)+a[i];
        update(h[i],f[i]);
    }
    cout<<query(n)<<endl;
    return 0;
}