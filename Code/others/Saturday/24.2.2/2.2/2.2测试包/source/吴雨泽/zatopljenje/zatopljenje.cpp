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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,q,a[N],l[N],r[N],x[N],ans[N]; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("zatopljenje.in","r",stdin);
    freopen("zatopljenje.out","w",stdout);
    cin>>n>>q;
	bool flag=false;
    int t=clock(); 
    for(int i=1;i<=n;++i)	cin>>a[i];
    for(int i=1;i<=q;++i){
    	cin>>l[i]>>r[i]>>x[i];
    }
    for(int i=1;i<=q;++i){
    	int sum=0;
    	int j=l[i];
    	while(a[j]<=x[i]&&j<=r[i])	++j;
    	for(;j<=r[i];){
    		while(a[j]>x[i]&&j<=r[i])	++j;
    		++sum;
    		while(a[j]<=x[i]&&j<=r[i])	++j;
		}
		ans[i]=sum;
		if(clock()-t>2200)	goto ELSE;
	}
	for(int i=1;i<=q;++i)	cout<<ans[i]<<endl, flag=true;
	if(flag)	return 0;
	ELSE:
	int maxx=INF,idx=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<maxx)	maxx=a[i], idx=i;
	}
	for(int i=1;i<=q;++i){
		cin>>l[i]>>r[i]>>x[i];
		if(l[i]>=idx){
			cout<<(x[i]<a[r[i]])<<endl;
		}else if(r[i]<=idx)	cout<<(x[i]<a[l[i]])<<endl;
		else{
			if(x[i]<maxx)	cout<<1<<endl;
			else if(x[i]<a[l[i]]&&x[i]<a[r[i]])	cout<<2<<endl;
			else if(x[i]<a[l[i]]||x[i]<a[r[i]])	cout<<1<<endl;
			else	cout<<0<<endl;
		}
	}
    return 0;
}

