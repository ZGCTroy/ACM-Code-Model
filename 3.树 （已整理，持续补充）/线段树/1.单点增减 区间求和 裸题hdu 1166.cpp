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
const LL N=1e5+2;
const LL inf=0x3f3f3f3f;
LL SUM[4*N],MAX[4*N],MIN[4*N],add[4*N],change[4*N];
/***********************************************************************************
 										向上更新
 ************************************************************************************/
void PushUp(LL rt) {
    SUM[rt]=SUM[rt<<1]+SUM[rt<<1 | 1];
}


/***********************************************************************************
 						build(一边读入一边构建)
 ************************************************************************************/
void build(LL l,LL r,LL rt) {    //
    if (l==r) {
        cin>>SUM[rt];
        return ;
    }
    LL m=(l+r)>>1;
    build(lson);      //构建左子树
    build(rson);      //构建右子树
    PushUp(rt);       //构建完左右两颗子树后，更新当前子树
}





/***********************************************************************************
 								单点增减 p位置+add
 ************************************************************************************/

void point_add(LL p,LL add,LL l,LL r,LL rt) {
    if (l==r) {
        SUM[rt]+=add;
        return ;
    }
    LL m=(l+r)>>1;
    if (p<=m) point_add(p,add,lson);
    else      point_add(p,add,rson);
    PushUp(rt);
}


/***********************************************************************************
 								区间（L,R)求和
 ************************************************************************************/

LL query_SUM(LL L,LL R,LL l,LL r,LL rt) {
    if (L<=l && r<=R) {
        return SUM[rt];
    }
    LL m=(l+r)>>1;
    LL res=0;
    if (L<=m) res+=query_SUM(L,R,lson);
    if (R>m)  res+=query_SUM(L,R,rson);
    return res;
}




/*************************************************************************************************************************
 										主程序
 **************************************************************************************************************************/
void solve() {
    LL n;
    cin>>n;
    build(root);
    string order;
    while(cin>>order) {
        //cout<<order<<endl;
        if (order[0]=='A' ) {
            LL p,addv;
            cin>>p>>addv;
            point_add(p,addv,root);
        }else if (order[0]=='S'){
            LL p,addv;
            cin>>p>>addv;
            point_add(p,-addv,root);
        }else if (order[0]=='Q'){
            LL l,r;
            cin>>l>>r;
            //cout<<l<<" "<<r<<endl;
            cout<<query_SUM(l,r,root)<<endl;
        }else return;
    }
}

int main() {
    //    freopen("datain.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL T;
    cin>>T;
    for (int cas=1;cas<=T;cas++){
        cout<<"Case "<<cas<<":"<<endl;
        solve();
    }
    return 0;
}
