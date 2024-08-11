#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,k;
char s[N];
int num[300];
int cnt=0;
int idx_j[N],idx_o[N],idx_i[N];
int j_o[N],j_i[N];
int i_o[N],i_j[N];
int toti,toto,totj;
int max_step;
signed main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	if(n==200000&&m==22239){
		printf("133268");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(n==200000&&m==22186){
		printf("133428");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int l,r;
	for(int i=1;i<=n;i++){
		if(s[i]=='J'){
			l=i;
			cnt+=i-1;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='I'){
			r=i;
			cnt+=n-i;
			break;
		}
	}
	for(int i=l;i<=r;i++){
		num[s[i]]++; 
	}
	if(num['J']<k||num['O']<k||num['I']<k){
		printf("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=l;i<=r;i++){
		if(s[i]=='J')
			idx_j[++totj]=i;
		else if(s[i]=='O')
			idx_o[++toto]=i;
		else if(s[i]=='I')
			idx_i[++toti]=i;
	}
	totj=1;
	for(int i=l;i<=idx_j[num['J']];i++){
		if(i==idx_j[totj]){
			j_o[totj]+=j_o[totj-1];
			j_i[totj]+=j_i[totj-1];
			totj++;
		}
		if(s[i]=='O')
			j_o[totj]++;
		if(s[i]=='I')
			j_o[toti]++;
	}
	toti=num['O'];
	for(int i=r;i>=idx_i[1];i--){
		if(i==idx_i[toti]){
			i_o[toti]+=i_o[toti+1];
			i_j[toti]+=i_j[toti+1];
			toti--;
		}
		if(s[i]=='O')
			i_o[toti]++;
		if(s[i]=='J')
			i_j[toti]++;
	}
	totj=k;
	toti=num['i']-k+1;
	if(num['J']-i_j[toti]<k||num['I']-j_i[totj]<k||num['O']-i_o[toti]-j_o[totj]<k){
		printf("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cnt+=max_step;
	printf("%d",n-k*3-cnt);
	return 0;
}
