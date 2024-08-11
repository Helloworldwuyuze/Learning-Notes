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
const int M = 1e7 + 10;

int n,m,L,R,maxdep,ans=-INF;
int val[N];
vector<PII> g[N];

struct Seg{
    int sum[N<<2];
	vector<int> record;
	bool flag[N<<2];
    void build(int p,int l,int r){
        // cout<<p<<" "<<l<<" "<<r<<endl;
        for(int i=0;i<record.size();++i)
			sum[record[i]]=-INF, flag[record[i]]=false;
    }
    void update(int p,int l,int r,int x,int k){
		if(!flag[p])	flag[p]=true, record.pb(p);
        if(l==r){ sum[p]=max(sum[p],k); return ;}
        int mid=l+r>>1;
        if(x<=mid)  update(p<<1,l,mid,x,k);
        else    update(p<<1|1,mid+1,r,x,k);
        sum[p]=max(sum[p<<1],sum[p<<1|1]);
    }
    int query(int p,int l,int r,int left,int right){
        if(left<=l&&r<=right)   return sum[p];
        int mid=l+r>>1,res=-INF;
        if(left<=mid)   res=max(res,query(p<<1,l,mid,left,right));
        if(right>mid)   res=max(res,query(p<<1|1,mid+1,r,left,right));
        return res;
    }
};

int maxx[N],siz[N],root,sum,dep[N];
bool vis[N];
void calsiz(int x,int fa){
    // cout<<x<<" "<<fa<<endl;
    siz[x]=1, maxx[x]=0;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y]||y==fa)  continue;
        calsiz(y,x);
        siz[x]+=siz[y], maxx[x]=max(maxx[x],siz[y]);
    }
    maxx[x]=max(maxx[x],sum-siz[x]);
    if(maxx[x]<maxx[root])  root=x;
}
void caldep(int x,int fa){
    maxdep=max(maxdep,dep[x]);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        dep[y]=dep[x]+1;
        caldep(y,x);
    }
}
vector<int> sub, color, ge;
bool flag[N], flagcol[N], flagge[N];
int mx[N],mxcol[N];
void caldis(int x,int fa,int value,int l){
    dep[x]=dep[fa]+1;
    if(dep[x]>R)    return ;
	if(!flag[dep[x]])	sub.pb(dep[x]), flag[dep[x]]=true;
	mx[dep[x]]=max(mx[dep[x]],value);
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(y==fa||vis[y])   continue;
        if(z==l)    caldis(y,x,value,l);
        else    caldis(y,x,value+val[z],z);
    }
}   

Seg gene, col;
void dfz(int x){
//    cout<<"QAQ"<<endl;
    vis[x]=true;
    dep[x]=0; maxdep=0; caldep(root,0);
    // cout<<"###"<<x<<" "<<maxdep<<"###"<<endl;
    int lst=0;
    maxdep=min(maxdep,R);
    gene.build(1,0,maxdep), col.build(1,0,maxdep); color.clear();
	// cout<<"## SegTree ##"<<endl;
	// for(int i=1;i<=n<<1;++i)
		// cout<<gene.sum[i]<<" "<<gene.flag[i]<<endl;
    // cout<<gene.query(1,0,maxdep,1,1)<<endl;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        sub.clear(); caldis(y,x,val[z],z);
        // cout<<"##"<<y<<" "<<z<<"##"<<endl;
        // cout<<gene.query(1,0,maxdep,1,1)<<endl;
        for(int j=0;j<sub.size();++j)
            if(sub[j]>=L&&sub[j]<=R)  ans=max(mx[sub[j]],ans);
        if(lst!=z){
			// cout<<"type :: 1"<<endl;
            lst=z;
            for(int j=0;j<color.size();++j){
                gene.update(1,0,maxdep,color[j],mxcol[color[j]]);
				flagcol[color[j]]=false, mxcol[color[j]]=-INF;
				if(!flagge[color[j]])	ge.pb(color[j]), flagge[color[j]]=true;
			}
			// cout<<gene.query(1,0,maxdep,1,3)<<endl;
            col.build(1,0,maxdep);
            color.clear();
            for(int j=0;j<sub.size();++j){
                ans=max(ans,mx[sub[j]]+gene.query(1,0,maxdep,max(0,L-sub[j]),R-sub[j]));
				// cout<<mx[sub[j]]<<" "<<gene.query(1,0,maxdep,max(0ll,L-sub[j]),R-sub[j])<<endl;
			}
            for(int j=0;j<sub.size();++j){
                col.update(1,0,maxdep,sub[j],mx[sub[j]]);
				mxcol[sub[j]]=max(mxcol[sub[j]],mx[sub[j]]);
				if(!flagcol[sub[j]])	flagcol[sub[j]]=true, color.pb(sub[j]);
			}
        }else{
			// cout<<"type :: 2"<<endl;
            for(int j=0;j<sub.size();++j){
                ans=max(ans,mx[sub[j]]+col.query(1,0,maxdep,max(0,L-sub[j]),R-sub[j])-val[lst]);
				// cout<<mx[sub[j]]<<" "<<col.query(1,0,maxdep,max(0ll,L-sub[j]),R-sub[j])<<" "<<val[lst]<<endl;
				ans=max(ans,mx[sub[j]]+gene.query(1,0,maxdep,max(0,L-sub[j]),R-sub[j]));
			}
            for(int j=0;j<sub.size();++j){
                col.update(1,0,maxdep,sub[j],mx[sub[j]]);
				mxcol[sub[j]]=max(mxcol[sub[j]],mx[sub[j]]);
				if(!flagcol[sub[j]])	flagcol[sub[j]]=true, color.pb(sub[j]);
			}
        }
		// cout<<gene.query(1,0,maxdep,1,2)<<" "<<col.query(1,0,maxdep,1,2)<<endl;
		// cout<<"# sub #"<<endl;
        // for(int j=0;j<sub.size();++j)
        //     cout<<sub[j]<<" "<<mx[sub[j]]<<endl;
		// cout<<"# color #"<<endl;
		// for(int j=0;j<color.size();++j)
		// 	cout<<color[j]<<" "<<mxcol[color[j]]<<endl;
		// cout<<"## SegTree ##"<<endl;
		// for(int i=1;i<=n<<1;++i)
		// 	cout<<gene.sum[i]<<" "<<gene.flag[i]<<endl;
		for(int j=0;j<sub.size();++j)
			flag[sub[j]]=false, mx[sub[j]]=-INF;
        // cout<<ans<<endl;
    }
	// for(int i=0;i<ge.size();++i)
	// 	cout<<ge[i]<<" ";
	// cout<<endl;
	for(int i=0;i<ge.size();++i)	flagge[ge[i]]=false;
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i].fi, z=g[x][i].se;
        if(vis[y])  continue;
        sum=siz[y], maxx[root=0]=INF;
        calsiz(y,-1), calsiz(root,-1);
        dfz(root);
    }
}

bool cmp(PII x,PII y){ return x.se<y.se; }

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>L>>R;
    for(int i=1;i<=m;++i)   cin>>val[i];
    for(int i=1,x,y,z;i<n;++i)  cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
    for(int i=1;i<=n;++i)
        sort(g[i].begin(), g[i].end(), cmp);
    // for(int i=1;i<=n;++i){
    //     cout<<"###"<<i<<"###"<<endl;
    //     for(int j=0;j<g[i].size();++j)
    //         cout<<g[i][j].fi<<" "<<g[i][j].se<<endl;
    // }
	for(int i=1;i<=n<<2;++i)	col.sum[i]=gene.sum[i]=-INF;
	memset(mx,-0x3f,sizeof(mx));
	memset(mxcol,-0x3f,sizeof(mxcol));
    sum=n, maxx[root=0]=INF;
    calsiz(1,-1), calsiz(root,-1);
    // cout<<root<<endl;
    dfz(root);
    cout<<ans<<endl;
    return 0;
}