#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<stack>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int J[N],O[N],I[N];
int n,k,sj,so,si;
int nxt[N],id[N],nxtt[N],idd[N];
int ans=INF;
char c[N];

int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>k>>(c+1);
	for(int i=1;i<=n;++i){
		if(c[i]=='J')	J[++sj]=i, id[i]=sj, idd[i]=so;
		if(c[i]=='O')	O[++so]=i, id[i]=so, idd[i]=si;
		if(c[i]=='I')	I[++si]=i, id[i]=si;
	}
	for(int i=1;i<=n;++i){
		if(c[i]=='J')	nxt[i]=J[id[i]+k-1], nxtt[i]=O[idd[i]+1];
		if(c[i]=='O')	nxt[i]=O[id[i]+k-1], nxtt[i]=I[idd[i]+1];
		if(c[i]=='I')	nxt[i]=I[id[i]+k-1];
	}
	for(int i=1;i<=n;++i){
		if(c[i]=='J'){
			int j=nxt[i];
			if(j==0)	continue;
			j=nxtt[j];
			if(j==0)	continue;
			j=nxt[j];
			if(j==0)	continue;
			j=nxtt[j];
			if(j==0)	continue;
			j=nxt[j];
			if(j==0)	continue;
			ans=min(ans,j-i+1);
//			cout<<i<<" "<<j<<" "<<ans<<endl;
		}
	}
	if(ans==INF)	cout<<-1<<endl;
	else	cout<<ans-3*k<<endl;
	return 0;
}
