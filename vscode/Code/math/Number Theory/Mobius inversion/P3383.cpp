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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e8 + 10;
const int M = 1e8;

int p[N], cnt, n;
void init(){
	for(int i=2;i<=M;++i){
		if(!p[i])   p[++cnt] = i;
		for(int j=1;j<=cnt&&i*p[j]<=M;++j){
			p[i*p[j]] = 1;
			if(i%p[j]==0)  break;
		}
	}
}
int q, x;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); init();
    cin>>n>>q;
    while(q--)  cin>>x, cout<<p[x]<<endl;
	return 0;
}