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
#define int long long

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,a[50],idx=0;
    cin>>n; --n;
    if(n==0){ cout<<0<<endl; return 0;}
    while(n)    a[++idx]=n%5, n/=5;
    for(int i=idx;i;--i)   cout<<a[i]*2;
    cout<<endl;
    return 0;
}