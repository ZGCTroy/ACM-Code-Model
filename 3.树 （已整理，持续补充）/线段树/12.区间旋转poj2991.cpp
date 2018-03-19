#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long LL;
#define ls (rt<<1)
#define rs (rt<<1|1) 
#define lson ls,l,m
#define rson rs,m+1,r
#define root 1,1,n
const int N=1e4+2;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
double X[4*N],Y[4*N],add[4*N];
/***********************************************************************************
                                //������x,y)˳ʱ����תrad
************************************************************************************/
void rotate(double &x,double &y,double rad) { 
	double tx=x*cos(rad)+y*sin(rad);
	double ty=y*cos(rad)-x*sin(rad);
	x=tx;
	y=ty;
}
/***********************************************************************************
                            		���ϸ���
************************************************************************************/
void PushUp(int rt,int l,int r) {
	X[rt]=X[ls]+X[rs];
	Y[rt]=Y[ls]+Y[rs];
}

/***********************************************************************************
                            ���´��ݣ������㷨��(�����޸�ʱ����ȥ��
************************************************************************************/
void PushDown(int rt,int l,int r) {
	int m=(l+r)>>1;
	if (add[rt]) {			//��������
		rotate(X[ls],Y[ls],add[rt]);
		rotate(X[rs],Y[rs],add[rt]);
		add[ls]	+=add[rt];
		add[rs]	+=add[rt];
		add[rt]=0;
	}
}



/***********************************************************************************
                                    build(һ�߶���һ�߹���)
************************************************************************************/
void build(int rt,int l,int r) {    //
	add[rt]=0;
	if (l==r) {
		scanf("%lf",&Y[rt]);
		X[rt]=0;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);      //����������
	build(rson);      //����������
	PushUp(rt,l,r);       //�������������������󣬸��µ�ǰ����
}



/***********************************************************************************
                                ����������l,r)  + add
************************************************************************************/

void interval_add(int L,int R,double addv,int rt,int l,int r) {
	if (L<=l && r<=R) {
		rotate(X[rt],Y[rt],addv);
		add[rt]+=addv;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_add(L,R,addv,lson);
	if(R>m) interval_add(L,R,addv,rson);
	PushUp(rt,l,r);
}




/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
double pre[N];
void solve(int n,int m) {
	build(root);
	for (int i=1; i<=n; i++) pre[i]=pi;
	while(m--) {
		int x;
		double rad;
		scanf("%d%lf",&x,&rad);
		rad=rad/360*2*pi;
		interval_add(x+1,n,pre[x]-rad,root);
		pre[x]=rad;
		printf("%.2f %.2f\n",X[1],Y[1]);
	}
	printf("\n");
}
int main() {
//	freopen("datain.txt","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		solve(n,m);
	}
	return 0;
}

