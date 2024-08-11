#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

FILE *in, *out, *report, *ans, *score;

int n, m, cnt, k;
vector<int> g[N];
bool vis[N];

void change(int x){
	vis[x] = true;
	for(int y:g[x]){
		vis[y] = true;
		for(int z:g[y])
			vis[z] = true;
	}
}

int main(int argc, char *argv[]){
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"r");
	ans = fopen(argv[3],"r");
	int user_score = atoi(argv[4]);
	score = fopen(argv[5],"w");
	report = fopen(argv[6],"w");
	
	fscanf(in, "%d%d%d", &n, &m, &k);
	fscanf(out, "%d", &cnt);
	if(cnt>k){
		fprintf(report, "Your point is more than the request.");
		fprintf(score, "%d", user_score * 0);
		return 0;
	}
	for(int i=1,x,y;i<=m;++i)
		fscanf(in, "%d%d", &x, &y), g[x].push_back(y), g[y].push_back(x);
	while(cnt--){
		int x;
		fscanf(out, "%d", &x);
		change(x);
	}
	bool flag=true;
	for(int i=1;i<=n;++i)	flag &= vis[i];
	if(flag){
		fprintf(report, "Your answer is perfect.");
		fprintf(score, "%d", user_score * 1);
	}else{
		fprintf(report, "Your point can not cover the whole map.");
		fprintf(score, "%d", user_score * 1);
	}
	
	fclose(in), fclose(out), fclose(ans), fclose(report), fclose(score);
	return 0;
}
