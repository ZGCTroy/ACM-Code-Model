#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100,inf=1<<30;
int W[maxn][maxn],n,lack;
int Lx[maxn],Ly[maxn];
int Left[maxn];
bool S[maxn],T[maxn];


bool match(int i) {
	S[i]=true;
	for (int j=1; j<=n; j++)
		if ( !T[j] ) {
			int t=Lx[i]+Ly[j]-W[i][j];
			if (!t) {
				T[j]=true;
				if ( !Left[j] || match( Left[j] ) ) {
					Left[j]=i;
					return true;
				}
			} else
				lack=min(lack,t);
		}
	return false;
}
void KM() {
	for (int i=1; i<=n; i++) {
		Left[i]=Lx[i]=Ly[i]=0;
		for (int j=1; j<=n; j++)
			Lx[i]=max(Lx[i],W[i][j]);
	}
	for (int i=1; i<=n; i++) {
		for (;;) {
			memset(S,false,sizeof(S));
			memset(T,false,sizeof(T));
			lack=inf;
			if (match(i)) break;
			else {
				for (int i=1; i<=n; i++) {
					if (S[i]) Lx[i]-=lack;
					if (T[i]) Ly[i]+=lack;
				}
			}
		}
	}
}
int main() {
	//freopen("data.txt","r",stdin);
	int T;
	cin>>T;
	while(T--) {
		scanf("%d",&n);

		//TODO 1：读入
		int love;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) {
				scanf("%d",&love);
				W[i][j]=love;
			}
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) {
				scanf("%d",&love);
				W[j][i]*=love;
			}


		//TODO 2： KM算法
		KM();


		//TODO 3： 累加最大权和，并输出
		int res=0;
		for (int i=1; i<=n; i++)res+=(Lx[i]+Ly[i]);
		cout<<res<<endl;
	}
	return 0;
}
