#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define root 1,n,1
const int N=5e5+2;
const int inf=0x3f3f3f3f;
int SUM[4*N],MAX[N],D[N];


/***********************************************************************************
                                        读入数字
************************************************************************************/
int read_num() {
	int res=0;
	bool flag=false;
	int ch;
	while( (ch=getchar())==' ' || ch=='\n') ;
	if ( ch == '-') flag=true;
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
}


/***********************************************************************************
                                        向上更新
************************************************************************************/
void build(int l,int r,int rt) {
	SUM[rt]=r-l+1;
	if (l==r) return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}



/***********************************************************************************
                                    更新
************************************************************************************/
char name[N][15];
int val[N],ans[N];
int Delete(int k,int l,int r,int rt) {
	--SUM[rt];
	if (l==r) return l;
	int m=(l+r)>>1;
	if (SUM[rt<<1]>=k) return Delete(k,lson);
	else return Delete(k-SUM[rt<<1],rson);
}

/***********************************************************************************
                                	init(初始化)
************************************************************************************/
void init() {
	memset(D,0,sizeof(D));
	memset(MAX,0,sizeof(MAX));
	int m=sqrt(N+0.5);
	int tot=0;
	for (int i=1; i<N; i++)
		for (int j=i; j<N; j+=i)
			D[j]++;
		
	MAX[1]=1;
	for (int i=2; i<N; i++) {
		if (D[i]>D[MAX[i-1]]) MAX[i]=i;
		else MAX[i]=MAX[i-1];
	}
}

/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/

void solve(int n,int k) {
	build(root);
	for (int i=1; i<=n; i++) {
		scanf("%s",name[i]);
		val[i]=read_num();
	}
	int num=MAX[n];
	int p=0;
	val[0]=0;
	for (int i=0; i<num ; i++) {
		int mod=n-i;
		if (val[p]>0) k=((k-2+val[p])%mod+mod)%mod+1;
		else  k=((k-1+val[p])%mod+mod)%mod+1;	
		p=Delete(k,root);	
	}
	printf("%s",name[p]);
	putchar(' ');
	print(D[num]);
	putchar('\n');
}

int main() {
//	freopen("datain.txt","r",stdin);
	int n,p;
	init();
	while(~scanf("%d%d",&n,&p)) {		
		solve(n,p);
	}
	return 0;
}

