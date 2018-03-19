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
const int N=1e6+5;
const int inf=0x3f3f3f3f;
int SUM[N<<2],MAX[N<<2],MIN[N<<2],XOR[N<<2],assign[N<<2];
/***********************************************************************************
                                       赋值
************************************************************************************/
void setvalue(int rt,int l,int r,int val){
    assign[rt]=val;
    int tmp=(r-l+1)*val;
    SUM[rt]=tmp;
    MAX[rt]=max(tmp,0);
    MIN[rt]=min(tmp,0);
    XOR[rt]=0;
}


/***********************************************************************************
                                        反转 
************************************************************************************/
void Reversal(int rt) {
	if (assign[rt]){
        assign[rt] *= -1;
        SUM[rt]    *= -1;
        XOR[rt]=0;
	}else{
        XOR[rt]	   ^=  1;
        SUM[rt]    *= -1;
	}
	int a=MAX[rt],b=MIN[rt];
	MAX[rt]=-b;
	MIN[rt]=-a;
}


/***********************************************************************************
                                        向上更新 
************************************************************************************/
void PushUp(int rt) {
	SUM[rt]= SUM[ls] + SUM[rs];
	MAX[rt]=max( MAX[ls] , SUM[ls]+MAX[rs]);
	MIN[rt]=min( MIN[ls] , SUM[ls]+MIN[rs]);    
}

/***********************************************************************************
                            		向下更新 
************************************************************************************/
void PushDown(int rt,int l,int r) {
	int m=(l+r)>>1;
	if(assign[rt]) {		
		setvalue(lson,assign[rt]);
		setvalue(rson,assign[rt]);
		assign[rt]=0;
	}
	if (XOR[rt]){
        Reversal(ls);
        Reversal(rs);
        XOR[rt]=0;
	}
}
/***********************************************************************************
                                        build
************************************************************************************/
void build(int rt,int l,int r){
    XOR[rt]=assign[rt]=0;
    if (l==r){
        char ch;
        cin>>ch;
        if (ch=='(') setvalue(rt,l,r,-1);
        else         setvalue(rt,l,r,1);
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}



/***********************************************************************************
                              			更新 
************************************************************************************/

void update(int L,int R,int val,int rt,int l,int r) {
	if (L<=l && r<=R) {
        if (val==2) Reversal(rt);
        else 		setvalue(rt,l,r,val);
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,val,lson);
	if(R>m) update(L,R,val,rson);
	PushUp(rt);
}


/***********************************************************************************
                                		查询 
************************************************************************************/

void query(int L,int R,int rt,int l,int r,int &_sum,int &_max) {
	if (L<=l && r<=R) {
		_sum=SUM[rt];
		_max=MAX[rt];
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	int lsum=0,rsum=0,lmax=0,rmax=0;
	if (L<=m) query(L,R,lson,lsum,lmax);
	if (R>m)  query(L,R,rson,rsum,rmax);
	_sum=lsum+rsum;
	_max=max(lmax,lsum+rmax);
    return ;
}





/**************************************************************************
                                       主程序              
****************************************************************************/
void solve() {
	int n;
	cin>>n;
	build(root);
	int Q;
	cin>>Q;
	while(Q--){
        string order;
        cin>>order;
        int L,R;
        cin>>L>>R;
        L++;
        R++;
        if (order[0]=='q'){
            int _sum=0,_max=0;
            query(L,R,root,_sum,_max);
			if (_sum==0 && _max==0) cout<<"YES\n";
            else					cout<<"NO\n";
        }else if (order[0]=='s'){
            char ch;
            cin>>ch;
            if (ch=='(') update(L,R,-1,root);
            else         update(L,R,1,root);
        }else{
            update(L,R,2,root);
        }
	}         
	
}

int main() {
    freopen("datain.txt","r",stdin);
    cin.tie(0);
	ios::sync_with_stdio(false);
    
	int T;
	cin>>T;
    for (int cas=1;cas<=T;cas++){
        cout<<"Case "<<cas<<":"<<'\n';
		solve();
	}
	return 0;
}


