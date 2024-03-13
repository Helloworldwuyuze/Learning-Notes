#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int c,m,n,q,kx,ky,px,py;
int x[N],y[N],a[N],b[N],pxx[N],pxn[N],sxx[N],sxn[N],pyx[N],pyn[N],syx[N],syn[N],t1[N],t2[N];
bool flag;

void init(){
	for(int i=1;i<=n;++i)	x[i]=a[i], pxx[i]=pxn[i]=sxx[i]=sxn[i]=0;
	for(int i=1;i<=m;++i)	y[i]=b[i], pyx[i]=pyn[i]=syx[i]=syn[i]=0;
	flag=false;
}

void SWAP(){
	flag=true;
	for(int i=1;i<=n;++i)	t1[i]=x[i];
	for(int i=1;i<=m;++i)	t2[i]=y[i];
	for(int i=1;i<=m;++i)	x[i]=t2[i];
	for(int i=1;i<=n;++i)	y[i]=t1[i];
	swap(n,m);
}

bool pre(int n,int m){
	if(n<1&&m<1)	return true;
	int ax=pxx[n], ix=pxn[n], ay=pyx[m], iy=pyn[m];
	if(x[ix]>=y[iy]&&x[ax]>=y[ay])	return false;
	else if(x[ix]<y[iy])	return pre(ix-1,m);
	else if(x[ax]<y[ay])	return pre(n,ay-1);
}

bool suf(int nn,int mm){
	if(nn>n||mm>m)	return true;
	int ax=sxx[nn], ix=sxn[nn], ay=syx[mm], iy=syn[mm];
	if(x[ix]>=y[iy]&&x[ax]>=y[ay])	return false;
	else if(x[ix]<y[iy])	return suf(ix+1,mm);
	else if(x[ax]<y[ay])	return suf(nn,ay+1);
}

void get_ps(){
	x[0]=y[0]=0, x[n+1]=y[m+1]=INF;
	pxx[0]=sxx[n+1]=0, pxn[0]=sxn[n+1]=n+1;
	pyx[0]=syx[m+1]=0, pyn[0]=syn[m+1]=m+1;
	for(int i=1;i<=n;++i){
		pxx[i]=x[i]>x[pxx[i-1]]?i:pxx[i-1];
		pxn[i]=x[i]<x[pxn[i-1]]?i:pxn[i-1];
	}
	for(int i=1;i<=m;++i){
		pyx[i]=y[i]>y[pyx[i-1]]?i:pyx[i-1];
		pyn[i]=y[i]<y[pyn[i-1]]?i:pyn[i-1];
	}
	for(int i=n;i;--i){
		sxx[i]=x[i]>x[sxx[i+1]]?i:sxx[i+1];
		sxn[i]=x[i]<x[sxn[i+1]]?i:sxn[i+1];
	}
	for(int i=m;i;--i){
		syx[i]=y[i]>y[syx[i+1]]?i:syx[i+1];
		syn[i]=y[i]<y[syn[i+1]]?i:syn[i+1];
	}
}

int main(){
	int idx=0;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=m;++i)	cin>>b[i];
	init();
	do{
		if(x[1]>y[1])	SWAP();
		++idx;
		get_ps();
		int ax=pxx[n],ix=pxn[n],ay=pyx[m],iy=pyn[m];
		if(y[ay]<=x[ax]||y[iy]<=x[ix])	cout<<0;
		else if(pre(ix-1,ay-1)&&suf(ix+1,ay+1))	cout<<1;
		else	cout<<0;
		if(flag)	swap(n,m);
		if(q<=0)	return 0;
		init();
		cin>>kx>>ky;
		for(int i=1;i<=kx;++i)	cin>>px>>py, x[px]=py;
		for(int i=1;i<=ky;++i)	cin>>px>>py, y[px]=py;
		--q;
	}while(true);
	return 0;
}
