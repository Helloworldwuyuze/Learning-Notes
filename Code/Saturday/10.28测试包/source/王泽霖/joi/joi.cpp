#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
char s[200005];
int J[200005],O[200005],I[200005];
int cntj,cnto,cnti;
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	for(int i=0; i<n; i++){
		if(s[i]=='J')J[++cntj]=i;
		if(s[i]=='O')O[++cnto]=i;
		if(s[i]=='I')I[++cnti]=i;
	}int ans=1000000000;
	for(int i=1; i<=cntj; i++){
		if(i+k-1>cntj){break;}
		int j=lower_bound(O+1,O+1+cnto,J[i+k-1])-O;
		if(j+k-1>cnto){break;}
		int l=lower_bound(I+1,I+1+cnti,O[j+k-1])-I;
		if(l+k-1>cnti){break;}
//		cout<<J[i]<<" "<<I[l+k-1]<<endl;
		ans=min(ans,I[l+k-1]-J[i]+1-3*k);
	}if(ans!=1000000000)cout<<ans;
	else cout<<-1;
	return 0;
}/*

*/
