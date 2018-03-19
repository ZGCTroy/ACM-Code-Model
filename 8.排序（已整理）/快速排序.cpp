/* ------------------------------------
		by 16级ACM会长 郑光聪
		模板有错私聊我 QQ：531584268
		其余情况均不接受私聊
----------------------------------- */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const int N=1e6+7;
const int mod=1e9+7;
int a[N];

/*********************************************************************************************
										快速排序
										区间L到R	
									  1.取L位置为基准数，比基准数小的放到左边，大的放在基准数的右边，最后把基准数放中间 
									  2、排序左边 
									  3、排序右边
*********************************************************************************************/

void quick_sort(int L,int R) {
	//TODO 1：判断边界 
	if (L>=R) return;
	//TODO 2：取L位置为基准数，
	int i=L,j=R;
	int mid=L+(R-L)/2;
	int base=a[L]; 	//取a[L]为基准数 
	while(i!=j){
		while(a[j]>=base && i<j) //停下时说明 a[j]<base 或者i==j
			j--;
		while(a[i]<=base && i<j) //停下时说明 a[i]>base 或者i==j
			i++;
		swap(a[i],a[j]); //交换两数 
	}
	swap(a[L],a[i]); //把基准数放到中间 
	
	//TODO 3:排序左边
	quick_sort(L,i-1);
	//TODO 4:排序右边 
	quick_sort(i+1,R);
	return;
}









/*********************************************************************************************
										主程序
*********************************************************************************************/

void solve() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	quick_sort(1,n);
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl; 
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
	while(T--) {
		solve();
	}
	return 0;
}
