#include<bits/stdc++.h>

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
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10; 

int n,a[N],q,t;
map<PII, bool> ma;

int print(int x,int y,bool flag){
	cout<<min(x,y)<<" "<<max(x,y)<<" "<<a[max(x,y)]-a[min(x,y)]+flag<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crow1.in","w",stdout);
    srand((unsigned)time(NULL));
    t=40;
    cout<<t<<endl;
    while(t--){
	    n=1000, q=2000;
	    cout<<n<<" "<<q<<endl;
	    bool flag=false;
	    for(int i=1;i<=n;++i)
	    	a[i]=a[i-1]+rand();
	    for(int i=1;i<=q;++i){
	    	int x=rand()%n+1, y=rand()%n+1;
	    	int z=rand()%2000;
	//    	while(ma[mk(x,y)])	x=rand()%n+1, y=rand()%n+1;
			if(z==0&&!flag&&i<q-3){
				int u=min(x,y), v=max(x,y);
				int w=rand()%n+1;
				print(u,w,false), print(v,w,false), print(u,v,true);
				i+=2; continue;
				flag=true;
			}
	    	cout<<min(x,y)<<" "<<max(x,y)<<" "<<a[max(x,y)]-a[min(x,y)]<<endl;
	//    	ma[mk(x,y)]=true;
		}
	}
    return 0;
}

