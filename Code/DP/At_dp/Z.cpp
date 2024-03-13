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
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,c,h[N],f[N],q[N],rear,head;

double Y(int x){ return f[x]+h[x]*h[x];}
double X(int x){ return h[x];}
double slope(int x,int y){ return (Y(x)-Y(y))/(X(x)-X(y));}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;++i)   cin>>h[i];
    q[head=rear=1]=1;
    for(int i=2;i<=n;++i){
        while(head<rear&&slope(q[head],q[head+1])<=2*h[i])  ++head;
        f[i]=f[q[head]]+(h[i]-h[q[head]])*(h[i]-h[q[head]])+c;
        while(head<rear&&slope(q[rear],q[rear-1])>=slope(q[rear],i))    --rear;
        q[++rear]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}