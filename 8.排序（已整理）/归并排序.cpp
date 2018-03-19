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
LL A[N],Atmp[N];

/*********************************************************************************************
										归并排序
									  1、排序左边 
									  2、排序右边
									  3、合并 
*********************************************************************************************/

void merge_sort(int L,int R) {
	//TODO 1：判断边界 
	if (L>=R) return;	
	int mid=L + (R-L)/2;
	
	//TODO 2：排序左边
	merge_sort(L,mid);
	
	//TODO 3：排序右边
	merge_sort(mid+1,R);
	
	//TODO 4: 左右两边合并,并放置于临时数组Atmp中 
	int i=L,j=mid+1;
	int t=L;
	while(i<=mid || j<=R) {
		if ( j>R || (i<=mid && A[i]<=A[j]))
			Atmp[t++]=A[i++];
		else
			Atmp[t++]=A[j++];
	} 
	//TODO 5：把辅助数组Atmp复制回A数组
	for (int i=L; i<=R; i++) A[i]=Atmp[i]; 
	return;
}









/*********************************************************************************************
										主程序
*********************************************************************************************/

void solve() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>A[i];
	merge_sort(1,n);
	for (int i=1;i<=n;i++) cout<<A[i]<<" ";
	cout<<endl; 
}

int main() {
//文件读入
	freopen("datain.txt","r",stdin);

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
