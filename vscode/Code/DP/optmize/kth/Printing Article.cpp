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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n,m,c[N],f[N];
int q[N], head, tail;

int X(int x){ return c[x];}
int Y(int x){ return f[x]+c[x]*c[x];}
double slope(int x,int y){ return (Y(x)-Y(y))/(X(x)-X(y));}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while(cin>>n>>m){
        for(int i=1;i<=n;++i)
            cin>>c[i], c[i]+=c[i-1];
        q[head=tail=1]=0;
        for(int i=0;i<=n;++i)   f[i]=0;
        for(int i=1;i<=n;++i){
            while(head<tail&&Y(q[head+1])-Y(q[head])<=2*c[i]*(X(q[head+1])-X(q[head])))    ++head;
            int j=q[head]; f[i]=f[j]+(c[i]-c[j])*(c[i]-c[j])+m;
            while(head<tail&&(Y(q[tail])-Y(q[tail-1]))*(X(i)-X(q[tail]))>=(Y(i)-Y(q[tail]))*(X(q[tail])-X(q[tail-1]))) --tail;
            q[++tail]=i;
        }
        cout<<f[n]<<endl;
    }
    return 0;
}