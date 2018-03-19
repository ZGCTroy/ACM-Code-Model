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
										康拓展开 
********************************************************************************************/ 
LL fac[15];
void init(){
	fac[1]=1;
	for (int i=2;i<=11;i++) fac[i]=fac[i-1]*i;
}
void cantor(int s[], LL num, int k){//康托展开，把一个数字num展开成一个数组s，k是数组长度
    int t;
    bool h[k];//0到k-1，表示是否出现过 
    memset(h, 0, sizeof(h)); 
    for(int i = 0; i < k; i ++){
        t = num / fac[k-i-1];
        num = num % fac[k-i-1];
        for(int j = 0, pos = 0; ; j ++, pos ++){
            if(h[pos]) j --;
            if(j == t){
                h[pos] = true;
                s[i] = pos + 1;
                break;
            }
        }
    }
}



/********************************************************************************************
										康拓逆展开 
********************************************************************************************/ 


void inv_cantor(int s[], LL &num, int k){//康托逆展开，把一个数组s换算成一个数字num 
    int cnt;
    num = 0;
    for(int i = 0; i < k; i ++){
        cnt = 0;
        for(int j = i + 1; j < k; j ++){
            if(s[i] > s[j]) cnt ++;//判断几个数小于它
        }
        num += fac[k-i-1] * cnt;
    }
}










/********************************************************************************************
										主程序 
********************************************************************************************/ 

void solve() {
	
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
