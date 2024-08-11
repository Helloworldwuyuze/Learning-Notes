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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

bool t[N], bl[N];
int n, w, l[N], r[N], idx, mx;
set<PII> pr, pa, add, del;

int dfs(int x){
	for(int i=x+1;;++i)
		if(!t[i] && !bl[i])	return i;
		else if(t[i] && !bl[i]){
			int le = i, ri = dfs(i);
			bl[le] = bl[ri] = true;
			i = ri;
		}
}

int main(){
	freopen("whatcanisay.in","r",stdin);
	freopen("whatcanisay.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	while(n--){
		cin>>w;
		t[w] ^= 1, mx = max(mx, w<<1);
		for(int i=1;i<=mx;++i)
			if(t[i] && !bl[i]){
				int le = i, ri = dfs(i);
				bl[le] = bl[ri] = true, l[++idx] = le, r[idx] = ri;
				i = ri;
			}
		pr.clear();
		for(int i=1;i<=idx;++i)	pr.insert(mk(l[i], r[i]));
		add.clear(), del.clear();
		for(PII x:pr)
			if(pa.find(x) == pa.end())	add.insert(x);
		for(PII x:pa)
			if(pr.find(x) == pr.end())	del.insert(x);
		cout<<del.size()<<endl;
		for(PII x:del)	cout<<x.fi<<" "<<x.se<<endl;
		cout<<add.size()<<endl;
		for(PII x:add)	cout<<x.fi<<" "<<x.se<<endl;
		pa = pr;
		for(int i=1;i<=mx;++i)	bl[i] = false;
		for(int i=1;i<=idx;++i)	l[i] = r[i] = 0;
		idx = 0;
		cout<<endl;
	}
	return 0;
}

