#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e5+5;
const int MAXV=1e3+5;		//背包最大容量 
const int MAXM=1e3+5;		//最大可用费用 
typedef long long LL;


/*********************************************************************************************
										二维费用的背包 
								V容量背包，M元费用 
								每个物品v[i]容量，m[i]费用，w[i]价值 
								问在V,M下可获得的最大价值 
*********************************************************************************************/
LL dp[MAXV][MAXM],v[N],m[N],w[N];
LL KnapSack(int n,int V,int M) {
	for(int i=0; i<n; i++)
		for(int j=w[i]; j<V; j++)
			for(int k=m[i]; k<=M; k++)
				dp[j][k]=max(dp[j][k],dp[j-v[i]][k-m[i]]+w[i]);
	return dp[V][M];
}





/*********************************************************************************************
										主程序
*********************************************************************************************/
void solve() {
	int n,V,M;
	cout<<"请输入背包的物品数和最大容量和总可用费用:"<<endl;
	cin>>n>>V>>M;
	cout<<"请依次输入物品容量与花费与价值"<<endl;
	for(int i=0; i<n; i++) cin>>v[i]>>m[i]>>w[i];
	cout<<"最大物品价值为:"<<KnapSack(n,V,M)<<endl;
}
int main() {
	//文件读入 与 取消同步加速读入
	//freopen("datain.txt","r",stdin);	文件入读
	ios::sync_with_stdio;
	cin.tie(0);

	//正文
	int T;		//T组数据
	cin>>T;
	while(T--) {
		solve();
	}

	return 0;
}
