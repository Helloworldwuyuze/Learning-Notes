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

#define int unsigned long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int LCM(int x,int y){
    return x*y/gcd(x,y);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int lcm=LCM(n,m);
    int l=1,r=9223372036854775808;
    while(l<r){
        int mid=(l+r)>>1;
        if(mid/n+mid/m-mid/lcm*2<k) l=mid+1;
        else    r=mid;
    }
    cout<<l<<endl;
    return 0;
}