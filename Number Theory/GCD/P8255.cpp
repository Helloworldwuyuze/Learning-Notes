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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int t,x,z;

int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--){
        cin>>x>>z;
        if(z%x!=0){
            cout<<-1<<endl;
            continue;
        }
        int tmp=gcd(z/x, x*x);
        if((int)(sqrt(tmp))*(int)(sqrt(tmp))!=tmp){ cout<<-1<<endl; continue;}
        cout<<z/x/(int)(sqrt(gcd(z/x,x*x)))<<endl;
    }
    return 0;
}