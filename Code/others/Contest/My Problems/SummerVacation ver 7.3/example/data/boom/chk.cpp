#include<bits/stdc++.h>

using namespace std;
//#define int long long

FILE *in, *out, *report, *score, *ans;

int l, r, k, p, phi, ansl, ansr;
int T;
bool ok = true;

int gcd(int x,int y){
	return y==0?x:gcd(y, x%y);
}
int ksm(int x,int m){
	long long ans = 1;
	for(; m; m>>=1, x=x*x%k) if(m&1) ans = ans*x%k;
	return ans;
}
int f(int x){
	if(x<phi)	x = ksm(x, x);
	else	x = ksm(x%k, x%phi+phi);
	return x ? x : k;
}

int main(int argc, char *argv[]){
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"r");
	ans = fopen(argv[3],"r");
	int user_score = atoi(argv[4]);
	score = fopen(argv[5],"w");
	report = fopen(argv[6],"w");
	fscanf(in, "%d", &T);
	while(T--){
		fscanf(in, "%d%d", &k, &p);
		fscanf(out, "%d%d", &l, &r);
		fscanf(ans, "%d%d", &ansl, &ansr);
		if(ansl == -1){
			if(l!=-1){
				ok = false;
				break;
			}
			continue;
		}
		phi = 0; --k;
		for(int i=1;i<k;++i)
			phi += (gcd(i, k) == 1);
		long long len = phi * k / gcd(k, phi), sum = 0;
		if(r<=phi + len){
			for(int i=l;i<=r;++i)	sum += f(i);
			if(sum != p){
				ok = false;
				break;
			}
		}
		else{
			long long cntr = (r-phi)/len; r = (r-phi)%len + phi;
			--cntr; r += len;
			long long cntl = (l-phi)/len; l = (l-phi)%len + phi;
			for(int i=l;i<=r;++i)	sum += f(i);
			long long _sum = 0;
			for(int i=phi+1;i<=phi+len;++i)	_sum += f(i);
			if(_sum * (cntr-cntl) + sum != p){
				ok = false;
				break;
			}
		}
	}
	if(!ok){
		fprintf(report, "Your range is not fit the request.");
		fprintf(score, "%d", user_score * 0);
	}else{
		fprintf(report, "Your answer is good enough!");
		fprintf(score, "%d", user_score * 1);
	}
	
	fclose(in), fclose(out), fclose(ans), fclose(report), fclose(score);
	return 0;
}
