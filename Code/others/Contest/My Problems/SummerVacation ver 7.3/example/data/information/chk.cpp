#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

FILE *in, *out, *score, *ans, *report;
int a[N], b[N], l, r, n, user_n, x, y, c[N];

int minn[N<<2], maxx[N<<2], idmn[N<<2], idmx[N<<2];
void build(int p,int l,int r){
	if(l==r)	return (void)(minn[p] = maxx[p] = c[l], idmn[p] = idmx[p] = l);
	int mid = l+r>>1;
	build(p<<1, l, mid), build(p<<1|1, mid+1, r);
	minn[p] = min(minn[p<<1], minn[p<<1|1]);
	maxx[p] = max(maxx[p<<1], maxx[p<<1|1]);
	idmn[p] = minn[p<<1] <= minn[p<<1|1] ? idmn[p<<1] : idmn[p<<1|1];
	idmx[p] = maxx[p<<1] >= maxx[p<<1|1] ? idmx[p<<1] : idmx[p<<1|1];
}
void update(int p,int l,int r,int x,int k){
	if(l==r)	return (void)(minn[p] = maxx[p] = k, idmn[p] = idmx[p] = l);
	int mid = l+r>>1;
	if(x<=mid)	update(p<<1, l, mid, x, k);
	else	update(p<<1|1, mid+1, r, x, k);
	minn[p] = min(minn[p<<1], minn[p<<1|1]);
	maxx[p] = max(maxx[p<<1], maxx[p<<1|1]);
	idmn[p] = minn[p<<1] <= minn[p<<1|1] ? idmn[p<<1] : idmn[p<<1|1];
	idmx[p] = maxx[p<<1] >= maxx[p<<1|1] ? idmx[p<<1] : idmx[p<<1|1];
}
int query_min(int p,int l,int r,int left,int right){
	if(left<=l&&r<=right)	return idmn[p];
	int mid = l+r>>1, ls = 0, rs = 0;
	if(left<=mid)	ls = query_min(p<<1, l, mid, left, right);
	if(right>mid)	rs = query_min(p<<1|1, mid+1, r, left, right);
	if(!ls||!rs)	return ls + rs;
	return c[ls] <= c[rs] ? ls : rs;
}
int query_max(int p,int l,int r,int left,int right){
	if(left<=l&&r<=right)	return idmx[p];
	int mid = l+r>>1, ls = 0, rs = 0;
	if(left<=mid)	ls = query_max(p<<1, l, mid, left, right);
	if(right>mid)	rs = query_max(p<<1|1, mid+1, r, left, right);
	if(!ls||!rs)	return ls + rs;
	return c[ls] >= c[rs] ? ls : rs;
}

int main(int argc, char *argv[]){
	memset(minn, 0x3f, sizeof(minn));
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"r");
	ans = fopen(argv[3],"r");
	int user_score = atoi(argv[4]);
	score = fopen(argv[5],"w");
	report = fopen(argv[6],"w");
	
	fscanf(in, "%d", &n);
	for(int i=1;i<=n;++i)	fscanf(in, "%d", &a[i]), c[i] = a[i];
	for(int i=1;i<=n;++i)	fscanf(in, "%d", &b[i]);
	fscanf(out, "%d", &user_n);
	if(user_n>1000000){
		fprintf(score, "%d", user_score * 0);
		fprintf(report, "Your operations are too many.");
		return 0;
	}
	build(1, 1, n);
	while(user_n--){
		fscanf(out, "%d%d", &l, &r);
		x = query_max(1, 1, n, l, r), y = query_min(1, 1, n, l, r);
		swap(c[x], c[y]);
		update(1, 1, n, x, c[x]), update(1, 1, n, y, c[y]);
	}
	bool flag = true;
	for(int i=1;i<=n;++i)
		if(c[i]!=b[i])	flag=false;
	if(flag){
		fprintf(score, "%d", user_score * 1);
		fprintf(report, "Your construct is prefect!");
	}else{
		fprintf(score, "%d", user_score * 0);
		fprintf(report, "Your construct can not make the right changes.");
	}
	return 0;
} 
