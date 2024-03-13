#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,k;
char s[N];

int cnt[N][4];

void preset(){
	for(int i=1;i<=n;i++){
		cnt[i][1]=cnt[i-1][1];
		cnt[i][2]=cnt[i-1][2];
		cnt[i][3]=cnt[i-1][3];
		if(s[i]=='J')cnt[i][1]++;
		if(s[i]=='O')cnt[i][2]++;
		if(s[i]=='I')cnt[i][3]++;
	}
}

int query(int L,int R,int joi){
	return cnt[R][joi]-cnt[L-1][joi];
}

int solve(int st,int joi){
	int l=st,r=n;
	while(l<r){
		int mid=l+r>>1;
		int re=query(st,mid,joi);
		if(re<k)l=mid+1;
		else r=mid;
	}
	if(l>n||query(st,l,joi)<k)return -1;
	return l;
}

int ans=0x3f3f3f3f;

int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	cin>>(char*)(s+1);
	preset();
	for(int i=1;i<=n;i++){
		int now=0,tmp=0;
		if(s[i]!='J')continue;
		int J=solve(i,1);
		tmp=(J-i+1)-k;
		if(tmp<0)continue;
		now+=tmp;
		int O=solve(J+1,2);
		tmp=(O-(J+1)+1)-k;
		if(tmp<0)continue;
		now+=tmp;
		int I=solve(O+1,3);
		tmp=(I-(O+1)+1)-k;
		if(tmp<0)continue;
		now+=tmp;
		ans=min(ans,now);
	}
	if(ans!=0x3f3f3f3f)cout<<ans<<endl;
	else cout<<"-1\n";
	return 0;
}
