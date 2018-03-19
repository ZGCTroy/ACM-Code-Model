#include<cstdio>
#include<cstring>
#include<vector>
#include <iostream>
using namespace std;

struct Max_Match {
	int p,n;
	vector<int> g[110];
	int left[310];
	bool vis[310];

	void init() {
		for(int i=0; i<110; i++) g[i].clear();
		memset(left,-1,sizeof(left));
	}

	bool match(int i) {
		for(int k=0; k<g[i].size(); k++) {
			int j=g[i][k];
			if(!vis[j]) {
				vis[j]=true;
				if(left[j]==-1 || match(left[j]) ) {
					left[j]=i;//此步相当于将增广路取反
					return true;
				}
			}
		}
		return false;
	}

	int solve() {
		int ans=0;//记录匹配边数
		for(int i=1; i<=p; i++) {
			memset(vis,0,sizeof(vis));
			if(match(i)) ans++;
		}
		return ans;
	}
} MM;

int main() {
	int T;
//	freopen("data.txt","r",stdin);
	cin>>T;
	while(T--) {
		MM.init();
		bool ok=true;
		scanf("%d%d",&MM.p,&MM.n);
		for(int i=1; i<=MM.p; i++) {
			int num;
			scanf("%d",&num);
			if(num) {
				while(num--) {
					int j;
					scanf("%d",&j);
					MM.g[i].push_back(j);
				}
			} else ok=false;
		}

		if(ok) printf("%s\n",MM.solve()==MM.p?"YES":"NO");
		else printf("NO\n");
	}
	return 0;
}

