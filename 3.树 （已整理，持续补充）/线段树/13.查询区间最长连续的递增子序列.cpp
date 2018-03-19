#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson ls,l,m
#define rson rs,m+1,r
#define root 1,1,n
const int N=1e5+2;
const int inf=0x3f3f3f3f;
int Rvalue[4*N],Lvalue[4*N],Prefix[4*N],Suffix[4*N],Middle[4*N],MAX[4*N],add[4*N];
/***********************************************************************************
                                        向上更新
************************************************************************************/
void PushUp(int rt,int l,int r) {
	int m=(l+r)>>1;
	Rvalue[rt]=Rvalue[rs];
	Lvalue[rt]=Lvalue[ls];
	
	if (Rvalue[ls]<Lvalue[ls|1]) {
		Middle[rt]=Suffix[ls]+Prefix[rs];
		if (Prefix[ls]==(m-l+1)) Prefix[rt]=Prefix[ls]+Prefix[rs];
		if (Suffix[rs]==(r-m)) Suffix[rt]=Suffix[ls]+Suffix[rs];
	} else {
		Prefix[rt]=Prefix[ls];
		Suffix[rt]=Suffix[rs];
	}
	MAX[rt]=max( Middle[rt] , max( Prefix[rt] , Suffix[rt] ) );
}

/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	int m=(l+r)>>1;
	if (add[rt]) {			//区间增减
		add[ls]		+=add[rt];
		add[rs]		+=add[rt];
		Rvalue[ls]	+=add[rt];
		Rvalue[rs]	+=add[rt];
		Lvalue[ls]	+=add[rt];
		Lvalue[rs]	+=add[rt];
		add[rt]=0;
	}
}





/***********************************************************************************
                                    build(一边读入一边构建)
************************************************************************************/
void build(int rt,int l,int r) {    //
	add[rt]=0;
	if (l==r) {
		cin>>Rvalue[rt];
		Lvalue[rt]=Rvalue[rt];
		MAX[rt]=Prefix[rt]=Suffix[rt]=Middle[rt]=1;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //构建左子树
	build(rson);      //构建右子树
	PushUp(rt,l,r);       //构建完左右两颗子树后，更新当前子树
}




/***********************************************************************************
                                区间增减（l,r)  + add
************************************************************************************/

void interval_add(int L,int R,int addv,int rt,int l,int r) {
	if (L<=l && r<=R) {
		add[rt]		+=addv;
		Rvalue[rt]	+=addv;
		Lvalue[rt]	+=addv;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_add(L,R,addv,lson);
	if(R>m)  interval_add(L,R,addv,rson);
	PushUp(rt,l,r);
}




/***********************************************************************************
                            区间（L,R)求最长连续递增子序列 
************************************************************************************/

int query_MAXLEN(int L,int R,int rt,int l,int r) {
	if (L<=l && r<=R) {
		return MAX[rt];
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	int res=0,t1=0,t2=0;
	if (L<=m) {
		res= max( res , query_MAXLEN(L,R,lson) );
		t1=min(m-L+1 , Suffix[ls] );
	}

	if (R>m) {
		res= max( res , query_MAXLEN(L,R,rson) );;
		t2=min(R-m   , Prefix[rs] );
	}
	if (Rvalue[ls]<Lvalue[rs]) res=max(res,t1+t2);
	return res;
}




/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
void solve() {
	int n,Q;
	cin>>n>>Q;
	build(root);
	while(Q--) {
		char order;
		cin>>order;
		if (order=='q') {
			int a,b;
			cin>>a>>b;
			cout<<query_MAXLEN(a,b,root)<<endl;
		} else {
			int a,b,c;
			cin>>a>>b>>c;
			interval_add(a,b,c,root);
		}
	}
}

int main() {
//	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		cout<<"Case #"<<i<<":"<<'\n';
		solve();
	}
	return 0;
}

