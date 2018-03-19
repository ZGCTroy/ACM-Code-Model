#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1e5+5;		//最大物品个数 
const int MAXV=1e3+5;   //最大容量 
typedef long long LL;


/*********************************************************************************************
										分组的背包 
										
			有N件物品和一个容量为V的背包。
			第i件物品的容量是v[i]，价值是w[i]。
			这些物品被依次平均分为K组，每组中的物品互相冲突，最多选一件。
			求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
			
*********************************************************************************************/
LL dp[MAXV],w[N],v[N];
LL KnapSack(int n,int W,int K) {
	for(int k=1; k<=K; k++)						//K组
		for(int j=W; j>=0; j--)					//01背包
			for (int i=n/K*(k-1)+1; i<n/K*k+1; i++)
				dp[j]=max( dp[j], dp[ j-v[i] ]+w[i] );
	return dp[W];
}





/*********************************************************************************************
										主程序
*********************************************************************************************/
void solve() {
	int n,V,K;
	cout<<"请输入背包的物品数和最大容量和总组数:"<<endl;
	cin>>n>>V>>K;
	cout<<"请依次输入物品的容量与价值"<<endl;
	for(int i=0; i<n; i++) cin>>v[i]>>w[i];
	cout<<"最大物品价值为:"<<KnapSack(n,V,K)<<endl;
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

