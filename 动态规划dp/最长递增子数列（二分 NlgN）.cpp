 #include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int Longest_NonDecreasing_Subsequence(int a[],int n){
	int b[n+1];
	memset(b,0,sizeof(b));
	int maxlen=0; 
	for (int i=1; i<=n; i++) {												//读入 
		if (a[i]>b[maxlen])	b[++maxlen]=a[i];						
		else {
			int pos=lower_bound(b+1,b+maxlen+1,a[i])-b;
			b[pos]=a[i];
		}
	}
	return maxlen;
}


/*********************************************************************************************
										主程序
*********************************************************************************************/ 
void solve(){
	int n;
	cin>>n; 
	int a[n+1];
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<"The max len= "<<Longest_NonDecreasing_Subsequence(a,n);
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
