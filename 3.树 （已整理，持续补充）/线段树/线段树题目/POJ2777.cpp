#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+5;
typedef long long LL;
#define ls rt<<1
#define rs rt<<1|1
#define lson ls,l,m
#define rson rs,m+1,r
#define root 1,1,N
bool vis[32];
int color[N<<2];
void PushDown(int rt,int l,int r){
    int m=(l+r)>>1;
    if (color[rt]!=-1){
        color[ls]=color[rt];
        color[rs]=color[rt];
        color[rt]=-1;
    }
}

void query(int L,int R,int rt,int l,int r){
    if (L<=l && r<=R){
        if (color[rt]!=-1) vis [ color[rt] ]=true;
        else{
            int m=(l+r)>>1;
            if (l==r) return;
            query(L,R,lson);
            query(L,R,rson);
        }
        return ;
    }
    PushDown(rt,l,r);
    int m=(l+r)>>1;
    if (L<=m) query(L,R,lson);
    if (R>m)  query(L,R,rson);
    return ;
}

void update(int val,int L,int R,int rt,int l,int r){
    if (L<=l && r<=R){
        color[rt]=val;
        return ;
    }
    PushDown(rt,l,r);
    int m=(l+r)>>1;
    if (L<=m) update(val,L,R,lson);
    if (R>m)  update(val,L,R,rson);
    return ;
}
void solve(int L,int T,int O){
    
    update(1,1,L,1,1,L);
    
    for (int i=0;i<O;i++){
        char cmd;
        cin>>cmd;
        if (cmd=='C'){
            int l,r,val;
            cin>>l>>r>>val;
            if (l>r) swap(l,r);
            update(val,l,r,1,1,L);
        }else{
            int l,r;
            cin>>l>>r;
            if (l>r) swap(l,r);
            memset(vis,false,sizeof(vis));
            query(l,r,1,1,L);
            int cnt=0;
            for (int i=1;i<=30;i++) if (vis[i]) ++cnt;
            cout<<cnt<<endl;
        }
    }
}
int main(){
    freopen("datain.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int L,T,O;
    while( cin>>L>>T>>O ){
    	solve(L,T,O);
	}
    return 0;
} 
