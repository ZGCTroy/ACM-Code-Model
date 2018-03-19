/* ------------------------------------	
		by 16级ACM会长 郑光聪
		模板有错私聊我 QQ：531584268
		其余情况均不接受私聊
----------------------------------- */  
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int mod=10,maxL=1000+5; 
//可更改最长长度maxL,并可以通过更改mod压位
//mod=10表示正常10进制，mod=10000表示是1w进制，则压了4位，使空间节省了4倍 
/*********************************************************************************
								自定义高精度类 
**********************************************************************************/ 
class bign {
	public:
		int a[maxL];
		bign() {
			a[0]=0;
			memset(a,0,sizeof(a));
		}
		void in() {
			string str;
			cin>>str;
			a[0]=str.length();
			for (int i=1; i<=a[0]; i++) a[i]=str[a[0]-i]-'0';
		}
		void print() {
			for (int i=a[0]; i>=1; i--) cout<<a[i];
		}
		bign operator + (bign &x) {
			bign c;
			c.a[0]=max(a[0],x.a[0]);
			for (int i=1; i<=c.a[0]; i++) {
				c.a[i]+=a[i]+x.a[i];
				c.a[i+1]=c.a[i]/mod;
				c.a[i]%=mod;
			}
			while (c.a[c.a[0]+1]) c.a[0]++;
			return c;
		}
		bign operator + (int num) {
			bign c=*this;
			c.a[1]+=num;
			for (int i=1; i<=a[0]; i++) {
				if (c.a[i]>=0 && c.a[i]<=9) break;
				if (c.a[i]>=10) {
					c.a[i+1]+=(c.a[i]/10);
					c.a[i]%=10;
				} else {
					while(c.a[i]<0) {
						c.a[i]+=10;
						c.a[i+1]--;
					}
				}
			}
			while (c.a[c.a[0]+1]) c.a[0]++;
			while (!c.a[c.a[0]])  c.a[0]--;
			return c;
		}
		bign operator * (bign &x) {
			bign c;
			c.a[0]=a[0]+x.a[0]-1;
			for (int i=1; i<=a[0]; i++)
				for (int j=1; j<=x.a[0]; j++) {
					c.a[i+j-1]+=a[i]*x.a[j];
				}
			for (int i=1; i<=c.a[0]; i++) {
				c.a[i+1]+=c.a[i]/10;
				c.a[i]%=10;
			}
			while (c.a[c.a[0]+1]) c.a[0]++;
			return c;
		}
		bign operator * (int num) {
			bign c;
			c.a[0]=a[0];
			for (int i=1; i<=c.a[0]; i++) c.a[i]=a[i]*num;
			for (int i=1; i<=c.a[0]; i++) {
				c.a[i+1]+=c.a[i]/10;
				c.a[i]%=10;
			}
			while (c.a[c.a[0]+1]) c.a[0]++;
			return c;
		}
		bign operator / (bign x) {
			bign ans,bc=*this;
			ans.a[0]=bc.a[0]-x.a[0]+1;
			int len=ans.a[0];
			while(len>=1) {
				bign tmp;
				tmp.a[0]=bc.a[0]-len+1;
				for (int i=len; i<=bc.a[0]; i++) tmp.a[i-len+1]=bc.a[i];
				int k=1;
				while(tmp>=(x*k)) k++;
				ans.a[len]=--k;
				if (k==0) {
					len--;
					continue;
				}
				bign cs=x*k;
				for (int i=len; i<=bc.a[0]; i++) {
					bc.a[i]-=cs.a[i-len+1];
					if (bc.a[i]<0) {
						bc.a[i+1]--;
						bc.a[i]+=10;
					}
				}
				while(!bc.a[bc.a[0]]) bc.a[0]--;
				len--;
			}
			while(!ans.a[ans.a[0]]) ans.a[0]--;
			return ans;
		}
		bool operator > (bign x) {
			if (a[0]!=x.a[0]) return a[0]>x.a[0];
			for (int i=a[0]; i>=1; i--) {
				if (a[i]!=x.a[i]) return a[i]>x.a[i];
			}
			return false;
		}
		bool operator < (bign x) {
			return x>*this;
		}
		bool operator >= (bign x) {
			return !(*this<x);
		}
};


/*********************************************************************************
									 主程序
**********************************************************************************/ 
int main() {
	//取消同步,加速读入 
	ios::sync_with_stdio(false);
	cin.tie(0);
	// 
}
