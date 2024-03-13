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

#include<windows.h>
#include<conio.h>
#include<bits/stdc++.h>

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
const int N = 10 + 10;
const int M = 1e6 + 10;

int n;
double a[N][N],ans[N],cans[N];
double tot,dis[N];

void check(){
    tot=0;
    for(int i=1;i<=n+1;++i){
        cans[i]=dis[i]=0;
        for(int j=1;j<=n;++j)   dis[i]+=(a[i][j]-ans[j])*(a[i][j]-ans[j]);
        dis[i]=sqrt(dis[i]);
        tot+=dis[i];
    }
    tot/=(n+1);
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=n;++j)
            cans[j]+=(dis[i]-tot)*(a[i][j]-ans[j])/tot;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=n;++j)   scanf("%lf",&a[i][j]), ans[j]+=a[i][j];
    for(int i=1;i<=n;++i)   ans[i]/=(n+1);
    for(double i=10001;i>=0.0001;i*=0.99995){
        check();
        for(int j=1;j<=n;++j)   ans[j]+=cans[j]*i;
        for(int j=1;j<=n;++j)   printf("%.3lf ",ans[j]);
        cout<<endl;
        char c=getch();
    }
    for(int i=1;i<=n;++i)   printf("%.3lf ",ans[i]); 
    cout<<endl;
    return 0;
}