#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MOD = (1<<30);

int mxa, mya, mza, mxb, myb, mzb, ans;
int s[N];

int main(){
	freopen("stars.in","r",stdin);
	freopen("stars.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	for(int i=1;i<=10;++i){
//		int sum = 0;
//		for(int j=0;j<=i;++j)
//			for(int z=0;z<=i;++z)
//				sum += (j^z);
//		s[i] = sum + s[i-1];
//		cout<<sum<<endl;
//	}
	cin>>mxa>>mya>>mza>>mxb>>myb>>mzb;
	if(max(max(max(mya, mza), mxa), max(max(myb, mzb), mza)) <= 10){
		for(int xa=0;xa<=mxa;++xa)
			for(int ya=0;ya<=mya;++ya)
				for(int za=0;za<=mza;++za)
					for(int xb=0;xb<=mxb;++xb)
						for(int yb=0;yb<=myb;++yb)
							for(int zb=0;zb<=mzb;++zb)
								ans = ans + (max(max(abs(xa-xb), abs(ya-yb)), abs(za-zb)) ^ xa ^ xb ^ ya ^ yb ^ za ^ zb), ans = ans%MOD;
		cout<<ans<<endl;
		return 0;
	}
//	if(mxb==myb && myb==mzb && mxb==0){
//		
//	}
	return 0;
}

