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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int border[N],n;
char c[N];
bool flag[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>c; n=strlen(c);
    for(int i=1;i<n;++i){
        int j=border[i-1];
        while(c[i]!=c[j]&&j)   j=border[j-1];
        border[i]=j+(c[i]==c[j]);
        if(i!=n-1)  flag[border[i]]=true;
    }
    int x=border[n-1];
    while(!flag[x]&&x)  x=border[x-1];
    if(x){ for(int i=0;i<x;++i) cout<<c[i]; cout<<endl;}
    else    cout<<"Just a legend"<<endl;
	return 0;
}