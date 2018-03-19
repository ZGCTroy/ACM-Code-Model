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
const int N=2e5+2;
const int inf=0x3f3f3f3f;
int SUM[4*N];
/***********************************************************************************
                                        读入数字
************************************************************************************/
int scan() {
	int res=0;
	bool flag=false;
	int ch;
	if ( ( ch=getchar() ) == '-') flag=true;
	else if (ch>='0' && ch<='9') res=ch-'0';
	while( (ch=getchar()) >='0' && ch<='9' )
		res=res*10+ch-'0';
	return flag ? -res : res;
}

/***********************************************************************************
                                    	正数输出
************************************************************************************/
void Out(int x) {
	if (x>9) Out(x/10);
	putchar(x%10 + '0' );
}

/***********************************************************************************
                                     有负数的输出
************************************************************************************/
void print(int x) {
	if (x<0) {
		putchar('-');
		Out(-x);
	} else
		Out(x);
}/***********************************************************************************
                                        向上更新
************************************************************************************/
void PushUp(int rt) {
	SUM[rt]=SUM[rt<<1]+SUM[rt<<1 | 1];
}


/***********************************************************************************
                                        向上更新
************************************************************************************/
void build(int l,int r,int rt) {
	if (l==r){
		SUM[rt]=1;
		return;
	}
		int m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}




/***********************************************************************************
                                    区间（L,R)求和
************************************************************************************/
int pos[N],val[N],ans[N];
void update(int p,int v,int l,int r,int rt) {
	--SUM[rt];
	if (l==r){
		ans[l]=v;
		return;
	}
	int m=(l+r)>>1;
	if (SUM[rt<<1]>=p) update(p,v,lson);
	else update(p-SUM[rt<<1],v,rson);
}



/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/

void solve(int n) {
	memset(ans,0,sizeof(ans));
	build(root);
	for (int i=1; i<=n; i++){
		pos[i]=scan();
		pos[i]++;
		val[i]=scan();
	}
	for (int i=n; i>=1; i--) update(pos[i],val[i],root);
	
	for (int i=1; i<=n; i++) {
		print(ans[i]);
		putchar(' ');
	}
	putchar('\n');
}

int main() {
//	freopen("datain.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)) {
		solve(n);
	}
	return 0;
}

