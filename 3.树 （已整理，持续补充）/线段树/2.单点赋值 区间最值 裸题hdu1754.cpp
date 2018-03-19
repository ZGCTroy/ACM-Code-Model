#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
const int N=222222;
const int inf=0x3f3f3f3f;
//int SUM[4*N],MIN[4*N],add[4*N],change[4*N];
int MAX[4*N];
/***********************************************************************************
 向上更新
 ************************************************************************************/
void PushUp(int rt) {
    MAX[rt]=max( MAX[rt<<1] , MAX[(rt<<1)+1]);
}


/***********************************************************************************
 build(一边读入一边构建)
 ************************************************************************************/
void build(int l,int r,int rt) {    //
    if (l==r) {
        cin>>MAX[rt];
        return ;
    }
    int m=(l+r)>>1;
    build(lson);      //构建左子树
    build(rson);      //构建右子树
    PushUp(rt);       //构建完左右两颗子树后，更新当前子树
}




/***********************************************************************************
    单点赋值 p位置=add
 ************************************************************************************/

void point_assign(int p,int val,int l,int r,int rt) {
    if (l==r) {
        MAX[rt]=val;
        return ;
    }
    int m=(l+r)>>1;
    if (p<=m) point_assign(p,val,lson);
    else      point_assign(p,val,rson);
    PushUp(rt);
}

/***********************************************************************************
 区间（L,R)求最大值
 ************************************************************************************/
int query_MAX(int L,int R,int l,int r,int rt) {
    if (L<=l && r<=R) {
        return MAX[rt];
    }
    int m=(l+r)>>1;
    int res=-inf;
    if (L<=m) res=max( res , query_MAX(L,R,lson) );
    if (R>m)  res=max( res , query_MAX(L,R,rson) );
    return res;
}




/*************************************************************************************************************************
 主程序
 **************************************************************************************************************************/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m){
        build(1,n,1) ;
        while(m--) {
            char order;
            int a,b;
            cin>>order>>a>>b;
            if (order=='U' ) {
                point_assign(a,b,1,n,1);
            } else{
                cout<<query_MAX(a,b,1,n,1)<<'\n';
            }
        }
    }
    return 0;
}
