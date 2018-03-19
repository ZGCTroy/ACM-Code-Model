#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N=1e6+5;
const int mod=1e9+7;

/********************************************************************************************
									O(n)线性打素数表
********************************************************************************************/ 
bool not_prime[N];
vector <int> primes;
void build_primes(){											 
	memset(not_prime,false,sizeof(not_prime)); 
	for (int i=2;i<N;i++){
		if (!not_prime[i]) primes.push_back(i);
		for (int j=0;j<primes.size() && 1LL*i*primes[j]<N;j++){
			not_prime[i*primes[j]]=true;
			if (i%primes[j]==0) break;
		}
	}
} 

/********************************************************************************************
										单个素数判定 
********************************************************************************************/ 
bool is_prime(int x){
	if (x<=1) return false;
	if (x<N) return (not_prime[x]) ? false : true;
	int m=sqrt(x+0.5);
	for (int i=0;i<primes.size();i++){
		if (primes[i]>=m) break;
		if (x%primes[i]==0) return false;
	}
	return true;
} 










/********************************************************************************************
										主程序 
********************************************************************************************/ 

void solve() {
	int x;
	cin>>x;
	if (is_prime(x)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main() {
//文件读入 
//	freopen("datain.txt","r",stdin);

//取消缓冲，加速读入 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//正文 
	build_primes();
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
