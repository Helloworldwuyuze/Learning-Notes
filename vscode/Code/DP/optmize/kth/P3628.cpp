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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n,a,b,c,s[N],f[N];
int q[N], tail, head;

double X(int x){ return s[x];}
double Y(int x){ return a*s[x]*s[x]+f[x]-b*s[x];}
double slope(int x,int y){ return (Y(y)-Y(x))/(X(y)-X(x));}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;++i)   cin>>s[i], s[i]+=s[i-1];
    q[tail=head=1]=0;
    for(int i=1;i<=n;++i){
        while(head<tail&&slope(q[head],q[head+1])>=2*a*s[i])    ++head;
        int j=q[head]; f[i]=f[j]+a*(s[i]-s[j])*(s[i]-s[j])+b*(s[i]-s[j])+c;
        while(head<tail&&slope(q[tail],q[tail-1])<=slope(q[tail],i))    --tail;
        q[++tail]=i;
        // cout<<f[i]<<" ";
    }
    // cout<<endl;
    cout<<f[n]<<endl;
    return 0;
}