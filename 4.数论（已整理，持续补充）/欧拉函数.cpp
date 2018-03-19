``=-9#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N=1e6+5;
const int mod=1e9+7;

/*********************************************************************************************
										欧拉函数O(n) 
*********************************************************************************************/ 
void build_phi(){
	memset(phi,0,sizeof(phi));
	phi[i]=1;
	for (int i=2;i<=N;i++) {
		if (!phi[i]) {
			primes.push_back(i);
			phi[i]=i-1;
		}
		for (int j=0;j<primes.size() && i*primes[j]<N;j++){
			if (i%primes[j]){
				phi[i*primes[j]]=phi[i]*(primes[j]-1);
			}else{
				phi[i*primes[j]]=phi[i]*primes[j];
				break;
			}
		}
	}
}










/*********************************************************************************************
										主程序
*********************************************************************************************/ 

void solve() {
	LL a,p;
	cin>>a>>p;
	cout<<get_inv(a,p)<<endl;
}

int main() {
//文件读入 
//	freopen("datain.txt","r",stdin);

//取消缓冲，加速读入 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//正文 
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
