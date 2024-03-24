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

int n, a[N],k,ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		a[i]=i;
	do{
		int s=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(a[i]>a[j])	++s;
		if(s!=k)	continue;
		int sum=0;
		for(int i=1;i<=n;++i)
			sum+=i*a[i];
		ans+=sum;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<endl;
	return 0;
}