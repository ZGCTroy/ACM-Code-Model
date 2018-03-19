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
const int N=5e6+5;
const int inf=0x3f3f3f3f;
int Suffix[N*4],Prefix[N*4],Middle[N*4],SUM[N*4],color[N*4];
/***********************************************************************************
                                        ���ϸ���
************************************************************************************/
void PushUp(int rt,int l,int r) {
	int m=(l+r)>>1;
	
	if (Suffix[ls] && Prefix[rs])  Middle[rt]=Suffix[ls]+Prefix[rs];
	else						   Middle[rt]=0;
	
	if (Prefix[ls]==(m-l+1)) 	   Prefix[rt]=Prefix[ls]+Prefix[rs];
	else						   Prefix[rt]=Prefix[ls];
	
	if (Suffix[rs]==(r-m))   	   Suffix[rt]=Suffix[ls]+Suffix[rs];
	else						   Suffix[rt]=Suffix[rs];
	
	SUM[rt]=max(Middle[rt], max(Prefix[rt],Suffix[rt]));
}

/***********************************************************************************
                            ���´��ݣ������㷨��(�����޸�ʱ����ȥ��
************************************************************************************/
void PushDown(int rt,int l,int r) {
	int m=(l+r)>>1; 
	if(color[rt]!=-1) {			//���丳ֵ
		color[ls]=color[rs]=color[rt];
		SUM[ls]=Prefix[ls]=Suffix[ls]=Middle[ls]=(m-l+1)*color[rt];
		SUM[rs]=Prefix[rs]=Suffix[rs]=Middle[rs]=(r-m)*color[rt];
		color[rt]=-1;
	}
}

/***********************************************************************************
                                    build(һ�߶���һ�߹���)
************************************************************************************/
void build(int rt,int l,int r) {    //
	color[rt]=-1;
	SUM[rt]=Prefix[rt]=Suffix[rt]=Middle[rt]=r-l+1;
	if (l==r) {
		color[rt]=1;  
		return;
	}
	int m=(l+r)>>1;
	build(lson);      //����������
	build(rson);      //����������
//	PushUp(rt,l,r);
}


/***********************************************************************************
                                ���丳ֵ��l,r)  = val
************************************************************************************/

void update(int L,int R,int val,int rt,int l,int r) {
	if (L<=l && r<=R) {
		color[rt]=val;
		SUM[rt]=Prefix[rt]=Suffix[rt]=Middle[rt]=(r-l+1)*val;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,val,lson);
	if(R>m)  update(L,R,val,rson);
	PushUp(rt,l,r);
}


/***********************************************************************************
                                    ���䣨L,R)���
************************************************************************************/

int query(int k,int rt,int l,int r) {	

//	cout<<l<<" "<<r<<"    "<<SUM[rt]<<" "<<k<<endl;
	
	if (SUM[rt]<k) return 0; 
	
	if (l==r) {
	//	SUM[rt]=Prefix[rt]=Suffix[rt]=Middle[rt]=0;
	//	color[rt]=0;
		return l;
	}
	
	PushDown(rt,l,r);
	
	int m=(l+r)>>1;
	int res=0;
	if (SUM[ls]>=k) res=query(k,lson);
	else{
		if (Middle[rt]>=k) res=query(Suffix[ls],lson);
		else res=query(k,rson);                 
	}
	PushUp(rt,l,r);
	return res;
}



/*************************************************************************************************************************
                                                            ������
**************************************************************************************************************************/
void solve(int n,int m) {
	build(root);
	while(m--){
		int cmd;
		scanf("%d",&cmd);
		if (cmd==1){
			int a;
			scanf("%d",&a);
			if (a<0) continue;
			int start=query(a,root);
			if (start+a-1<=n) {
				update(start,start+a-1,0,root); 
				printf("%d\n",start);
			}else{
				printf("0\n");
			}
		}else{
			int a,b;
			scanf("%d%d",&a,&b);
			if (b<1) continue;
			update(a,min(a+b-1,n),1,root);
		}
	}
}

int main() {
//	freopen("datain.txt","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		solve(n,m);
	}
	return 0;
}

