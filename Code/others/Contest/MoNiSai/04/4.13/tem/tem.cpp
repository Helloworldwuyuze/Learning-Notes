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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n, t, ans=1, l, r;
struct node{
	int l,r,id;
};
deque<node> q;

signed main(){
//	freopen("tem.in","r",stdin);
//	freopen("tem.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&l,&r);
		while(!q.empty()&&q.front().l>r)	q.pop_front();
		if(!q.empty())	ans=max(ans,i-q.front().id+1);
		int tmp=i;
		while(!q.empty()&&q.back().l<l)	tmp=q.back().id, q.pop_back();
		q.push_back((node){l,r,tmp});
	}
	cout<<ans<<endl;
	return 0;
}
