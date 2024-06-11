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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,m,p,d[N],a[N],t[N],f[N],g[N],s[N],h[N];
int q[N],tail,head;

double Y(int x){ return g[x]+s[x];}
double X(int x){ return x;}
double slope(int x,int y){ return (Y(y)-Y(x))/(X(y)-X(x));}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m>>p;
    for(int i=2;i<=n;++i)   cin>>d[i], d[i]+=d[i-1];
    for(int i=1;i<=m;++i)   cin>>h[i]>>t[i], a[i]=t[i]-d[h[i]];
    sort(a+1,a+1+m);
    for(int i=1;i<=m;++i)   s[i]=s[i-1]+a[i];
    int st=1;
    while(a[st]<0&&st<=n)   ++st;
    if(st>m){ cout<<-s[m]<<endl; return 0;}
    for(int i=1;i<=m;++i)   f[i]=a[i]*i-s[i];
    for(int i=1;i<=m;++i)   g[i]=f[i];
    // for(int i=1;i<=m;++i)   cout<<a[i]<<" ";
    // cout<<endl;
    for(int j=2;j<=p;++j){
        q[tail=head=1]=0;
        for(int i=1;i<=m;++i){
            while(head<tail&&slope(q[head],q[head+1])<=a[i])   ++head;
            int k=q[head]; f[i]=g[k]+(i-k)*a[i]-(s[i]-s[k]);
            // cout<<i<<" "<<k<<endl;
            while(head<tail&&slope(q[tail],q[tail-1])>=slope(q[tail],i))    --tail;
            q[++tail]=i;
        }
        for(int i=1;i<=m;++i)   g[i]=f[i];
        // cout<<endl;
    }
    cout<<f[m]<<endl;
	return 0;
}