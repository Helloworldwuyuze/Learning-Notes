#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
#define For for(int i=0;i<4;++i)
#define ls p<<1
#define rs p<<1|1
#define len(p) (t[p].right-t[p].left+1)
const int INF = 0x3f3f3f3f;

int n,m;
double x[N],y[N],op,l,r,S,T;

struct node{
	int left,right;
	double s[4],l[4];
	//0:sx 1:sy 2:sxp 3:sxy
	//0:sx 1:sy 2:S+i 3:T+i
}t[N<<2];

void push_up(int p){
	For	t[p].s[i]=t[ls].s[i]+t[rs].s[i];
}

double fun(double x){
	return x*(2*x+1)*(x+1)/6;
}

void down(int fa,int p){
	double l=t[p].left, r=t[p].right, ln=r-l+1, S=t[fa].l[2], T=t[fa].l[3];
//	cout<<"DOWN::"<<fa<<" "<<p<<" "<<l<<" "<<r<<" "<<ln<<" "<<S<<" "<<T<<endl;
	if(S!=INF&&T!=INF){
		t[p].s[0]=ln*(S+(l+r)/2);
		t[p].s[1]=ln*(T+(l+r)/2);
		t[p].s[2]=ln*(S*S+(l+r)*S)+fun(r)-fun(l-1);
		t[p].s[3]=ln*(S*T+S*(l+r)/2+T*(l+r)/2)+fun(r)-fun(l-1);
		t[p].l[2]=t[fa].l[2], t[p].l[3]=t[fa].l[3];
	}
	//-----------------------------------------------------
	S=t[fa].l[0], T=t[fa].l[1];
	t[p].s[2]+=2*S*t[p].s[0]+ln*S*S;
	t[p].s[3]+=S*t[p].s[1]+T*t[p].s[0]+ln*S*T;
	t[p].s[0]+=ln*S;
	t[p].s[1]+=ln*T;
	t[p].l[0]+=t[fa].l[0], t[p].l[1]+=t[fa].l[1];
	//-----------------------------------------------------
}

void push_down(int p){
	down(p,ls); down(p,rs);
	t[p].l[0]=t[p].l[1]=0, t[p].l[2]=t[p].l[3]=INF;
}

void build(int p,int left,int right){
	t[p].left=left, t[p].right=right;
	t[p].l[2]=t[p].l[3]=INF;
	if(left==right){
		t[p].l[0]=t[p].l[1]=0;
		t[p].s[0]=x[left], t[p].s[1]=y[left], t[p].s[2]=x[left]*x[left], t[p].s[3]=x[left]*y[left];
		return ;
	} 
	int mid=left+right>>1;
	build(ls,left,mid), build(rs,mid+1,right);
	push_up(p);
} 
 
void update1(int p,int left,int right,int S,int T){
	if(left<=t[p].left&&t[p].right<=right){
		t[p].s[2]+=2*S*t[p].s[0]+len(p)*S*S;
		t[p].s[3]+=S*t[p].s[1]+T*t[p].s[0]+len(p)*S*T;
		t[p].s[0]+=len(p)*S;
		t[p].s[1]+=len(p)*T;
		t[p].l[0]+=S, t[p].l[1]+=T;
		return ; 
	}
	push_down(p);
	int mid=t[p].left+t[p].right>>1;
	if(left<=mid)	update1(ls,left,right,S,T);
	if(right>mid)	update1(rs,left,right,S,T);
	push_up(p);
}

void update2(int p,int left,int right,int S,int T){
	if(left<=t[p].left&&t[p].right<=right){
		double l=t[p].left, r=t[p].right;
		t[p].s[0]=len(p)*(S+(l+r)/2);
		t[p].s[1]=len(p)*(T+(l+r)/2);
		t[p].s[2]=len(p)*(S*S+(l+r)*S)+fun(r)-fun(l-1);
		t[p].s[3]=len(p)*(S*T+S*(l+r)/2+T*(l+r)/2)+fun(r)-fun(l-1);
		t[p].l[0]=t[p].l[1]=0, t[p].l[2]=S,t[p].l[3]=T;
		return ;
	}
	push_down(p);
	int mid=t[p].left+t[p].right>>1;
	if(left<=mid)	update2(ls,left,right,S,T);
	if(right>mid)	update2(rs,left,right,S,T);
	push_up(p);
}

double query(int p,int left,int right,int f){
//	cout<<"QUERY::"<<p<<" "<<left<<" "<<right<<" "<<
	if(left<=t[p].left&&t[p].right<=right)	return t[p].s[f];
	push_down(p);
	int mid=t[p].left+t[p].right>>1;
	double res=0;
	if(left<=mid)	res+=query(ls,left,right,f);
	if(right>mid)	res+=query(rs,left,right,f);
	return res;
}

signed main(){
	freopen("relative444.in","r",stdin);
	freopen("relative.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	system("color 2");
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>x[i];
	for(int i=1;i<=n;++i)	cin>>y[i];
	build(1,1,n);
//	for(int i=1;i<=n<<1;++i)
//		printf("%lld %lld %lld %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf\n",i,t[i].left,t[i].right,t[i].s[0],t[i].s[1],t[i].s[2],t[i].s[3],t[i].l[0],t[i].l[1],t[i].l[2],t[i].l[3]);

	while(m--){
//		cout<<endl<<"-----------------------------------------"<<endl;
		cin>>op;
		if(op==1){
			cin>>l>>r;
			double len=r-l+1;
			double sx=query(1,l,r,0), sy=query(1,l,r,1), sxp=query(1,l,r,2), sxy=query(1,l,r,3);
			printf("%.10lf\n",(sxy-sx*sy/len)/(sxp-sx*sx/len));
		}else if(op==2){
			cin>>l>>r>>S>>T;
			update1(1,l,r,S,T);
		}else{
			cin>>l>>r>>S>>T;
			update2(1,l,r,S,T);
		}
//		for(int i=1;i<=n<<1;++i)
//			printf("%lld %lld %lld %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf\n",i,t[i].left,t[i].right,t[i].s[0],t[i].s[1],t[i].s[2],t[i].s[3],t[i].l[0],t[i].l[1],t[i].l[2],t[i].l[3]);
	}
	return 0;
}
/*
3 5
1 2 3
1 2 3
1 1 3
2 2 3 -3 2
1 1 2
3 1 2 2 1
1 1 3
*/
