#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define root 1,n,1
const int N=1e5+2;
const int inf=0x3f3f3f3f;
int SUM[4*N],change[4*N];
/***********************************************************************************
                                        向上更新
************************************************************************************/
void PushUp(int rt) {
	SUM[rt]=SUM[rt<<1]+SUM[rt<<1 | 1];
}

/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if(change[rt]) {					//区间赋值
		change[rt<<1]=change[rt<<1 | 1]=change[rt];
		int m=(l+r)>>1;
		SUM[rt<<1]=(m-l+1)*change[rt];
		SUM[rt<<1 | 1]=(r-m)*change[rt];
		change[rt]=0;
	}
}



/***********************************************************************************
                                    build(一边读入一边构建)
************************************************************************************/
void build(int l,int r,int rt) {    //
	change[rt]=0;
	if (l==r) {
		SUM[rt]=1;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //构建左子树
	build(rson);      //构建右子树
	PushUp(rt);       //构建完左右两颗子树后，更新当前子树
}

/***********************************************************************************
                                区间赋值（l,r)  = val
************************************************************************************/

void interval_assign(int L,int R,int val,int l,int r,int rt) {
	if (L<=l && r<=R) {
		change[rt]=val;
		SUM[rt]=val*(r-l+1);
		return ;
	}
	PushDown(rt,l,r);
	int m=l+(r-l)/2;
	if(L<=m) interval_assign(L,R,val,lson);
	if(R>m) interval_assign(L,R,val,rson);
	PushUp(rt);
}


/***********************************************************************************
                                    区间（L,R)求和
************************************************************************************/

int query_SUM(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return SUM[rt];
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	int res=0;
	if (L<=m) res+=query_SUM(L,R,lson);
	if (R>m)  res+=query_SUM(L,R,rson);
	return res;
}


/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
void solve() {
	int n;
	cin>>n;
	build(root);
	int m;
	cin>>m;
	while(m--) {
		int a,b,val;
		cin>>a>>b>>val;
		interval_assign(a,b,val,root);
	}

}

int main() {
//	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	for (int cas=1; cas<=T; cas++) {
		solve();
		cout<<"Case "<<cas<<": The total value of the hook is "<<SUM[1]<<"."<<'\n';
	}
	return 0;
}
