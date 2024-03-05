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

const long long INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int a[N],b[N];

int gcd(int a,int b){ return b?gcd(b,a%b):a;}
bool check(){
	__int128 n=1;
	int d=a[1];
	for(int i=1;i<=n;++i)	n=n*b[i], d=gcd(d,b[i]);
	return n<=INF&&d==1;
}

int main(){
	freopen("equation1.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    srand((unsigned)time(NULL));
    int n=10, m=1;
    cout<<n<<endl;
	do{
		for(int i=1;i<=n;++i)	a[i]=rand()%10, b[i]=a[i]+rand()%10;
	}while(!check());
	for(int i=1;i<=n;++i)	cout<<a[i]<<" "<<b[i]<<endl;
	cout<<m<<endl;
	cout<<"2 1 "<<n<<endl;
    return 0;
}

