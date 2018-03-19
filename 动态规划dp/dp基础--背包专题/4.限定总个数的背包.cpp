#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e5+5;
const int MAXW=1e3+5;
const int MAXU=1e3+5;
typedef long long LL;


/*********************************************************************************************
										限定总个数的背包 
							V容量的背包 
							N件物品，每件物品容量v[i],价值w[i]
							每个物品最多取1次，但总共最多取K件物品 
							问背包能装的下的情况下获得的最大的价值 
*********************************************************************************************/
LL dp[MAXW][MAXU],v[N],w[N];
LL KnapSack(int n,int W,int U) {
	for(int i=0; i<n; i++)
		for(int j=w[i]; j<=W; j++)
			for(int k=1; k<=U; k++)
				dp[j][k]=max(dp[j][k],dp[j-w[i]][k-1]+v[i]);
	return dp[W][U];
}





/*********************************************************************************************
										主程序
*********************************************************************************************/
void solve() {
	int n,W,U;
	cout<<"请输入背包的物品数和最大容量和总个数:"<<endl;
	cin>>n>>W>>U;
	cout<<"请依次输入物品的重量与花费与价值"<<endl;
	for(int i=0; i<n; i++) cin>>w[i]>>v[i];
	cout<<"最大物品价值为:"<<KnapSack(n,W,U)<<endl;
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
