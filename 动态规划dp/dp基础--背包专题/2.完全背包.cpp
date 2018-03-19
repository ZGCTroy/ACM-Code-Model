#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath> 
using namespace std; 
const int N=1e5+5;			//物品最大个数 
const int MAXV=1e5+5;		//背包最大容量 
typedef long long LL;


/*********************************************************************************************
										 完全背包
							V容量的背包 
							N件物品，每件物品容量v[i],价值w[i]
							每个物品可取无限次 
							问背包能装的下的情况下获得的最大的价值 
*********************************************************************************************/ 
LL dp[MAXV],w[N],v[N];
LL KnapSack(int n,int V) {
	for(int i=0; i<n; i++)
		for(int j=w[i]; j<=V; j++)
			 dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	return dp[V];
}





/*********************************************************************************************
										主程序
*********************************************************************************************/ 
void solve(){
	int n,V;
	cout<<"请输入背包的最大容量和物品数:"<<endl;
	cin>>V>>n;
	cout<<"请依次输入物品的容量与价值"<<endl;
	for(int i=0;i<n; i++) cin>>v[i]>>w[i];
	cout<<"最大物品价值为:"<<KnapSack(n,V)<<endl;
}
int main() {
	//文件读入 与 取消同步加速读入 
	//freopen("datain.txt","r",stdin);	文件入读
	ios::sync_with_stdio;
	cin.tie(0); 
	
	//正文  
	int T;		//T组数据 
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
