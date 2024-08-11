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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int f(int x){ return x==0?0:(x+f(x/10));}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(int i=1000;i<=5000;++i){
		bool flag=false;
		for(int j=i;j>=0;--j)
			if(f(j)==i){flag=true; break;}
		if(!flag)	cout<<i<<endl;
	}
	return 0;
}