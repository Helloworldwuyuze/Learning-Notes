#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int a[N], n, s, t;
double l, r, b[N], pre[N];
int q[N], rear, front;

bool check(double x){
	// cout<<fixed<<setprecision(9)<<x<<endl;
	for(int i=1;i<=n;++i)
		b[i] = a[i] - x, pre[i] = pre[i-1] + b[i];
	front = 1; rear=0;
	for(int i=1;i<=n;++i){
		if(i>=s){
			while(front<=rear && pre[q[rear]] >= pre[i-s])	--rear;
			q[++rear] = pre[i-s];
		}
		while(front<=rear && i - q[front] > t)	++front;
		// cout<<pre[i]<<endl;
		// for(int j=front;j<=rear;++j)
			// cout<<pre[q[j]]<<" ";
		// cout<<endl;
		if(front<=rear && pre[i] - pre[q[front]] > 0)	return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>s>>t;
	for(int i=1;i<=n;++i)	cin>>a[i], l = min(l, (double)a[i]), r = max(r, (double)a[i]);
	while(l<r){
		double mid = (l+r)/2;
		if(check(mid))	l = mid;
		else	r = mid-eps;
	}
	cout<<fixed<<setprecision(3)<<l<<endl;
	return 0;
}