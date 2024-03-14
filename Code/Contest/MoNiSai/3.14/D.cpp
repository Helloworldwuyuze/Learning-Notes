#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 2e2 + 10;
const int MOD = 1e9 + 7;

int n,s[N],f[N],st[N],pre[N][M],k,g[N];
int q[N],tail,head;

double X(int x){ return s[x];}
int Y(int x){ return g[x]-s[n]*s[x];}
double slope(int x,int y){ return X(y)==X(x)?-1e18:(Y(y)-Y(x))/(X(y)-X(x));}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)   cin>>s[i], s[i]+=s[i-1];
    // for(int i=1;i<n;++i)
    //     g[i]=s[i]*(s[n]-s[i]);
    // for(int i=1;i<=n;++i)   cout<<g[i]<<" ";
    // cout<<endl;
    for(int j=1;j<=k;++j){
        q[head=tail=1]=j-1;
        for(int i=j;i<n;++i){
            while(head<tail&&slope(q[head],q[head+1])>=-s[i])   ++head;
            int k=q[head];  f[i]=g[k]+(s[i]-s[k])*(s[n]-s[i]); pre[i][j]=k;
            while(head<tail&&slope(q[tail],q[tail-1])<=slope(q[tail],i))    --tail;
            q[++tail]=i;
        }
        for(int i=1;i<=n;++i)   g[i]=f[i];
        // for(int i=1;i<=n;++i)   cout<<f[i]<<" ";
        // cout<<endl;
    }
    int ans=0;
    for(int i=k;i<=n;++i)
        if(f[ans]<f[i]) ans=i;
    cout<<f[ans]<<endl;
	if(n==2){cout<<1<<endl; return 0;}
    int kk=k;
    while(k)   st[k]=ans, ans=pre[ans][k], --k;
    for(int i=1;i<=kk;++i)   cout<<st[i]<<" ";
    cout<<endl;
	return 0;
}
/*
7 3
3 2 0 4 3 1 4
*/