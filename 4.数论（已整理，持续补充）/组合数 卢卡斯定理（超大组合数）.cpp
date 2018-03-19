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
									组合数打表（乘法逆元，阶乘，逆元阶乘） 
********************************************************************************************/ 
LL 	inv[N],					//逆元 
	F[N],					//阶乘 
	Finv[N]; 				//逆元阶乘 
void build_comb(){
	inv[1]=F[0]=Finv[0]=1;
	for (int i=2;i<N;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (int i=1;i<N;i++){
		F[i]=F[i-1]*i%mod;
		Finv[i]=Finv[i-1]*inv[i]%mod;
	}
} 
/********************************************************************************************
										组合数 
********************************************************************************************/ 
LL comb(LL n,LL m){			//返回C n m
	if (m>n || m<0) return 0;
	return F[n]*Finv[m]%mod*Finv[n-m]%mod;
}

/********************************************************************************************
									组合数N方打表
								(当无需取模且N很小时) 
********************************************************************************************/ 
LL C[1000][1000];
void build_comb_nfang(int n){
	for (int i=0;i<n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++)
			C[i][j] =( C[i-1][j] + C[i-1][j-1] )%mod;
	}
}

/********************************************************************************************
										卢卡斯定理
						C(n, m) % p  =  C(n / p, m / p) * C(n%p, m%p) % p
********************************************************************************************/ 
LL Lucas_comb(LL n,LL m,LL p){
	if ((n/p)>p) return Lucas_comb(n/p,m/p,p)*comb(n%p,m%p)%p;
	else		 return comb(n/p,m/p)*comb(n%p,m%p)%p;
} 







/********************************************************************************************
										主程序 
********************************************************************************************/ 

void solve() {
	LL n,m;
	cin>>n>>m;
	cout<<comb(n,m)<<endl;
	cout<<Lucas_comb(n,m,1003)<<endl;
	if (n<1000 && m<1000) cout<<C[n][m]<<endl; 
}
int main() {
//文件读入 
//	freopen("datain.txt","r",stdin);

//取消缓冲，加速读入 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//正文 
	build_comb();
	build_comb_nfang(1000);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
