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
#define int long long

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 50;
const int MAXN = 1e6;
const int MAXM = 100;
const int MAXP = 25;

int n, a[N]; 
bool flag = false;
int b[N], p[N], cnt, tot, c[N];

void init(){
	for(int i=2;i<=MAXM;++i){
		if(!p[i])	p[++cnt] = i;
		for(int j=1;j<=cnt&&p[j]*i<=MAXM;++j){
			p[i*p[j]]=1;
			if(i%p[j]==0)	break;
		}
	}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0); init();
    srand((unsigned)time(NULL));
    freopen("construct20.in","w",stdout);
    b[1] = 1;
    for(int i=2;;++i){
    	tot = i-1;
    	b[i] = b[i-1] * p[rand()%MAXP+1];
    	if(b[i]>MAXN)	break;
	}
	n = M;
	cout<<n<<endl;
//	for(int i=1;i<=tot;++i)	cout<<b[i]<<endl;
	for(int i=1;i<=n;++i){
		int x;
		do{
			x=0;
			for(int i=1;i<=tot;++i)	a[i] = rand()%(MAXP/3*2);
			for(int i=1;i<=tot;++i)	x += a[i] * b[i];
		}while(x>MAXN);
		cout<<x<<" ";
	}
    return 0;
}

