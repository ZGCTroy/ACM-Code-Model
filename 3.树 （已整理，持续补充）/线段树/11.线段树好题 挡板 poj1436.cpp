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
#define root 1,0,2*N
const int N=8000+5;
const int inf=0x3f3f3f3f;
int SUM[8*N],color[8*N];
bool mark[N+5][N+5];
/***********************************************************************************
                            ���´��ݣ������㷨��(�����޸�ʱ����ȥ��
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if(color[rt]!=-1) {			//���丳ֵ
		color[ls]=color[rs]=color[rt];
		color[rt]=-1;
	}
}


/***********************************************************************************
                            ���ϴ��� 
************************************************************************************/
void PushUp(int rt,int l,int r) {
	if(color[ls]==color[rs]) color[rt]=color[ls];
	else color[rt]=-1;
}


/***********************************************************************************
                                ���丳ֵ��l,r)  = val
************************************************************************************/
void interval_assign(int L,int R,int val,int rt,int l,int r) {
	if (L<=l && r<=R) {
		color[rt]=val;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_assign(L,R,val,lson);
	if(R>m) interval_assign(L,R,val,rson);
	PushUp(rt,l,r);
}


/***********************************************************************************
                                    ���䣨L,R)���
************************************************************************************/

void query(int curi,int L,int R,int rt,int l,int r) {
	if (L<=l && r<=R && color[rt]!=-1) {
		mark[curi][color[rt]]=true;
		return;
	}
	if (l==r) return;
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if (L<=m) query(curi,L,R,lson);
	if (R>m)  query(curi,L,R,rson);
	PushUp(rt,l,r);
	return ;
}


/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
struct line {
	int y1,y2,x;
	bool operator < (const line & t) const {
		return x<t.x;
	}
} lines[N];

void solve() {
	//TODO 1: ��ʼ��
	memset(color,-1,sizeof(color));
	memset(mark,false,sizeof(mark));
	//TODO 2: ����
	int n;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d%d",&lines[i].y1,&lines[i].y2,&lines[i].x);
		lines[i].y1<<=1;
		lines[i].y2<<=1;
	}
	//TODO 3: ��x������
	sort(lines+1,lines+n+1);
	//TODO 4�������ѯ�����串��
	for (int i=1; i<=n; i++) {
		query(i,lines[i].y1,lines[i].y2,root);
		interval_assign(lines[i].y1,lines[i].y2,i,root);
	}
	//TODO 5������n2�����
	int cnt=0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<i; j++)
			if (mark[i][j]) {
				for (int k=i+1; k<=n; k++)
					if (mark[k][i] && mark[k][j]) cnt++;
			}
	}

	printf("%d\n",cnt);
}

int main() {
//	freopen("datain.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}
