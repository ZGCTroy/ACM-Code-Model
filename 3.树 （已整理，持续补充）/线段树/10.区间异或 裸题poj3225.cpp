#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const int N=65536*2+1;
const int inf=0x3f3f3f3f;
#define ls   (rt<<1)
#define rs	(rt<<1|1)
#define lson ls,l,m
#define rson rs,m+1,r
#define root 1,0,N
int color[N*4+20],XOR[N*4+20],ans[N*4+10];
/***********************************************************************************
                            		SetValue
************************************************************************************/
void SetValue(int val,int rt,int l,int r){
	color[rt]=val;
	XOR[rt]=0;
}

/***********************************************************************************
                            		异或 
************************************************************************************/
void Reversal(int rt){
	if (color[rt]!=-1) color[rt]^=1;
	else XOR[rt]^=1;
} 


/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	int m=(l+r)>>1;
	if (color[rt]!=-1) {
		SetValue(color[rt],lson);
		SetValue(color[rt],rson); 
		color[rt]=-1;
	}
	if (XOR[rt]) {
		Reversal(ls);
		Reversal(rs);
		XOR[rt]=0;
	}
}

/***********************************************************************************
                   					向上更新 
************************************************************************************/
void PushUp(int rt,int l,int r){
	return ;
}


/***********************************************************************************
                                区间赋值（l,r)  = val
************************************************************************************/
void interval_assign(int val,int L,int R,int rt,int l,int r) {
	if (L<=l && r<=R) {
		SetValue(val,rt,l,r);
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_assign(val,L,R,lson);
	if(R>m) interval_assign(val,L,R,rson);
	PushUp(rt,l,r);
}



/***********************************************************************************
                                	区间异或 
************************************************************************************/

void FXOR(int L,int R,int rt,int l,int r) {
	if (L<=l && r<=R) {
		Reversal(rt);
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) FXOR(L,R,lson);
	if(R>m) FXOR(L,R,rson);
	PushUp(rt,l,r);
}


/***********************************************************************************
                                    区间（L,R)
************************************************************************************/
void query(int rt,int l,int r) {
	if (l==r) {
		ans[l]=color[rt];
		return;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	query(lson);
	query(rson);
	return ;
}



/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
void solve() {
	memset(color,0,sizeof(color));
	memset(XOR,0,sizeof(XOR));
	memset(ans,0,sizeof(ans)); 
	char ch0,ch1,ch2;
	int L,R;
	while(scanf(" %c %c%d,%d%c",&ch0,&ch1,&L,&R,&ch2)!=EOF) {
		L<<=1;
		R<<=1;
		if (ch1=='(') L++;
		if (ch2==')') R--;
		if (L>R) {
			if (ch0=='I' || ch0=='C') {
				color[1]=XOR[1]=0;
			}
			continue;
		}
		switch(ch0) {
			case 'U': {
				interval_assign(1,L,R,root);
				break;
			}
			case 'D': {
				interval_assign(0,L,R,root);
				break;
			}
			case 'I': {
				if(L>0) interval_assign(0,0,L-1,root);
				if (R<N) interval_assign(0,R+1,N,root);
				break;
			}
			case 'S': {
				FXOR(L,R,root);
				break;
			}
			case 'C': {
				if(L>0) interval_assign(0,0,L-1,root);
				if (R<N) interval_assign(0,R+1,N,root);
				FXOR(L,R,root);
				break;
			}
		}      
	}
	query(1,0,N);
	L=0;R=-1;
	for (int i=0; i<=N; i++) {
		if (ans[i]==0 && ans[i+1]==1) L=i+1;
		if (ans[i]==1 && ans[i+1]==0) {
			R=i;
			if (L&1) printf("(%d,",L/2);
			else		  printf("[%d,",L/2);
			if (R&1) 	  printf("%d) ",R/2+1);
			else		  printf("%d] ",R/2);
		}
	}
	if (L>R)	printf("empty set\n");
	else printf("\n");
}

int main() {
//	freopen("datain.txt","r",stdin);
	solve();
	return 0;
}

