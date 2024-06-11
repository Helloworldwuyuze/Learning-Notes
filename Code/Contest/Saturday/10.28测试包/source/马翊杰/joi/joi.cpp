#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int INF=0x3f3f3f3f;
int n,k;
string a;
int fl;
int nxt[N],sr[N],sro[N];
int ans[N];
int main()
{//
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>a;
	n=a.size();
	int p=0;
	int sti=-1,stj=-1,sto=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='I'&&sti==-1) sti=i;
		if(a[i]=='J'&&stj==-1) stj=i;
		if(a[i]=='O'&&sto==-1) sto=i;
	}
	for(int i=0;i<n;i++)
	{
		if(fl==0&&a[i]=='J') p++;
		if(fl==1&&a[i]=='O') p++;
		if(fl==2&&a[i]=='I') p++;
		if(p>=k) fl++,p=0;
	}
	if(fl!=3) 
	{
		printf("-1\n"); 
		return 0;
	}
	int ii=-1,ji=-1,oi=-1;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]=='I')
		{
			if(ii==-1) ii=i,nxt[i]=INF;
			else nxt[i]=ii-i-1,ii=i;
		} 
		if(a[i]=='J')
		{
			if(ji==-1) ji=i,nxt[i]=INF;
			else nxt[i]=ji-i-1,ji=i;
		} 
		if(a[i]=='O')
		{
			if(oi==-1) oi=i,nxt[i]=INF;
			else nxt[i]=oi-i-1,oi=i;
		} 
	}
	int kk=k-1;
	int ai,aj,ao;
	int si=sti,sj=stj,so=sto;
	ai=aj=ao=0;
	while(kk)
	{
		aj+=nxt[stj];
		stj=stj+nxt[stj]+1;
		ao+=nxt[sto];
		sto=sto+nxt[sto]+1;	
		ai+=nxt[sti];
		sti=sti+nxt[sti]+1;
	//	cout<<sti<<" "<<stj<<" "<<sto<<endl; 
		kk--;
	}
	sr[si]=ai,sr[sj]=aj,sr[so]=ao;
	//cout<<ai<<" "<<aj<<" "<<ao<<endl;
	for(int i=0;i<n;i++)
	{
	//	cout<<i<<" "<<ai<<" "<<nxt[si]<<" "<<nxt[sj]<<" "<<nxt[so]<<" "<<nxt[i]<<endl;
		if(sr[i]==0)
		{
			if(a[i]=='J')
			{
				if(stj>=N||stj>=N) sr[i]=aj=INF;
				else 
				{
					aj=aj-nxt[sj]+nxt[stj];
					sr[i]=aj;
					sj=sj+nxt[sj]+1;
					stj=stj+nxt[stj]+1;
				}
			}
			if(a[i]=='O')
			{
				if(sto>=N||so>=N) sr[i]=ao=INF;
				else 
				{
					ao=ao-nxt[so]+nxt[sto];
					sr[i]=ao;
					so=so+nxt[so]+1;
					sto=sto+nxt[sto]+1;
				}
			}
			if(a[i]=='I')
			{
				if(sti>N||si>N) sr[i]=ai=INF;
				else 
				{
					ai=ai-nxt[si]+nxt[sti];
					sr[i]=ai;
					si=si+nxt[si]+1;
					sti=sti+nxt[sti]+1;
				}
			}
		}
	//	cout<<"i:"<<si<<" j:"<<sj<<" o:"<<so<<endl;
//		cout<<i<<" "<<sr[i]<<endl;
	}
	int mi=INF,mii=0;
	for(int i=n-1;i>=0;i--)
	{
	//	mi++;
		if(a[i]=='I'&&mi+mii-i>sr[i])
		{
			mi=sr[i];
			mii=i;
		}
		if(a[i]=='O') sro[i]+=mi+mii-i-1;
	//	cout<<i<<" "<<sro[i]<<endl;
	}	
	int mo=INF,moi=0;
	for(int i=0;i<n;i++)
	{
		//cout<<i<<" "<<sr[i]<<endl;
	//	cout<<a[i]<<" "<<i<<" "<<sr[i]<<" "<<i+sr[i]+k-1<<" "<<sro[i+sr[i]+k-1]<<endl;
		if(a[i]=='O') 
		{
			if(i+sr[i]+k-1>=N-1) sr[i]=INF;
			else sr[i]+=sro[i+sr[i]+k-1];
		}
	//	cout<<a[i]<<" "<<i<<" "<<sr[i]<<" "<<i+sr[i]+k-1<<" "<<sro[i+sr[i]+k-1]<<endl;
	}
	for(int i=n-1;i>=0;i--)
	{
	//	mi++;
		if(a[i]=='O'&&mo+moi-i>sr[i])
		{
			mo=sr[i];
			moi=i;
		}
		if(a[i]=='J') sro[i]+=mo+moi-i-1;
	//	cout<<mo<<" "<<moi<<endl;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=='J') 
		{
			if(i+sr[i]+k-1>=N-1) sr[i]=INF;
			else sr[i]+=sro[i+sr[i]+k-1];
		}
	}
	int ans=INF;
	for(int i=0;i<n;i++)
	{
	//	cout<<i<<" "<<sr[i]<<endl;
		if(a[i]=='J'&&sr[i]<ans) ans=sr[i]; 
	}
	printf("%d\n",ans);
	return 0;
}
