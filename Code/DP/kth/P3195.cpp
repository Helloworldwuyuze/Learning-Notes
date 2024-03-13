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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n,l,c[N],f[N];
int q[N],tail, head;

double X(int x){ return c[x];}
double Y(int x){ return f[x]+(c[x]+l)*(c[x]+l);}
double slope(int x,int y){ return (Y(y)-Y(x))/(X(y)-X(x));}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>l; ++l;
    for(int i=1;i<=n;++i)
        cin>>c[i], c[i]+=c[i-1];
    for(int i=1;i<=n;++i)   c[i]+=i;
    q[tail=head=1]=0;
    for(int i=1;i<=n;++i){
        while(head<tail&&slope(q[head],q[head+1])<=2*c[i])  ++head;
        int j=q[head]; f[i]=f[j]+(c[i]-c[j]-l)*(c[i]-c[j]-l);
        while(head<tail&&slope(q[tail],q[tail-1])>=slope(q[tail],i))    --tail;
        q[++tail]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}