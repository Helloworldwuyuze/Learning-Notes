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
#include<random>

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
const int N = 1e3 + 10;
const int M = 1e6 + 10;

int n;
double x[N],y[N],w[N];
double ansx, ansy;

void hillclime(){
    double t=1000;
    while(t>1e-18){
        double tx=0, ty=0;
        for(int i=1;i<=n;++i){
            double dx=x[i]-ansx, dy=y[i]-ansy;
            double dis=sqrt(dx*dx+dy*dy)+1e-8;
            tx+=(x[i]-ansx)*w[i]/dis;
            ty+=(y[i]-ansy)*w[i]/dis;
        }
        ansx+=tx*t, ansy+=ty*t;
        if(t>0.5)   t*=0.5;
        else    t*=0.97;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>x[i]>>y[i]>>w[i], ansx+=x[i], ansy+=y[i];
    ansx/=n, ansy/=n;
    hillclime();
    printf("%.3lf %.3lf\n",ansx,ansy);
    return 0;
}