---
title: Counting Arrays 题解
date: 2024-7-1 21:30:21
tags: 题解笔记
mathjax: true
---

# Counting Arrays

## 题意

给定数 $x,y$ 求序列 $a_y$ 的个数使得 $\prod_{i=1}^ya_i=x$。

## Solution

### 前置

要将 $n$ 个完全一样的小球放进 $m$ 个盒子里面，要求不能有空盒子，就可以在 $n-1$ 个缝隙中插入 $m-1$ 个板子将 $n$ 分成 $m$ 份，于是容易得到方案数为 $\binom{n-1}{m-1}$。

但如果每个盒子中可以为空，就可以再加入 $m$ 个小球使得每个盒子必然被分到一个，然后在这 $n+m$ 个小球中插入 $m-1$ 块板子，于是最后答案就变成 $\binom{n+m-1}{m-1}$.

### 正文

设 $x=\prod_{i=1}^kp_i^{\alpha_i}$，那么我们可以将这 $\sum\alpha_i$ 个质因数扔给 $y$ 个盒子，注意到这些质因子可能不同，因此不能整体使用插板法求方案数，而应该每个 $\alpha_i$ 分别做一次插板再乘起来。即答案为：

$$\prod \binom{\alpha_i+y-1}{y-1}$$

但注意到 $a_i$ 可以为负数，这样我们就可以令前 $y-1$ 个数可以正也可以负，最后一个来决定整个乘积的正负性，即答案有多乘以 $2^{y-1}$。

于是最终的答案就是:

$$2^{y-1}\times \prod\binom{\alpha_i+y-1}{y-1}$$

## CODE

```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
const int M = 2e5 + 10;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int t,x,y,fact[N],infact[N],p[N],prime[N],cnt,minn[N];

int ksm(int x,int m){
	int ans=1;
	while(m){
		if(m&1)	ans=ans*x%MOD;
		x=x*x%MOD; m>>=1;
	}
	return ans;
}

int C(int n,int m){
	if(n<m)	return 0;
	if(m==0)	return 1;
	return fact[n]*infact[n-m]%MOD*infact[m]%MOD;
}

void Prime(){
	for(int i=2;i<=1000000;++i){
		if(!prime[i])	prime[++cnt]=i, minn[i]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=1000000;++j){
			prime[i*prime[j]]=1;
			minn[i*prime[j]]=prime[j];
			if(i%prime[j]==0)	break;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Prime();
	fact[0]=1;
	for(int i=1;i<=N-10;++i)	fact[i]=fact[i-1]*i%MOD;
	infact[N-10]=ksm(fact[N-10],MOD-2);
	for(int i=N-11;i>=0;--i)	infact[i]=infact[i+1]*(i+1)%MOD;
	p[0]=1;
	for(int i=1;i<=1000000;++i)	p[i]=p[i-1]*2%MOD;
	cin>>t;
	while(t--){
		cin>>x>>y;
		int ans=p[y-1];
		while(x>1){
			int sum=0, xx=x;
			while(xx%minn[x]==0)	xx/=minn[x], ++sum;
			ans=ans*C(sum+y-1,y-1)%MOD;
			x=xx;
		}
		if(x!=1)	ans=ans*C(y,y-1)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
```