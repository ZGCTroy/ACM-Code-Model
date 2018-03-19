#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson  ls,l,m
#define rson  rs,m+1,r
#define root 1,1,n
const LL N=1e5+5;
const LL inf=0x3f3f3f3f;
LL a[N];
LL SUM[N<<2],Origin[N<<2],color[N<<2]; 
void PushUp(LL rt,LL l,LL r){
	SUM[rt]=SUM[ls]+SUM[rs];
	Origin[rt]=Origin[ls]+Origin[rs];
}

void build(LL rt,LL l,LL r){
	if (l==r){
		cin>>SUM[rt];
		Origin[rt]=SUM[rt];
		return;
	}
	LL m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt,l,r);
}

void PushDown(LL rt,LL l,LL r){
	LL m=(l+r)>>1;
	if (color[rt]!=-1){
		color[ls]	=	color[rt];
		color[rs]	=	color[rt];
		SUM[ls]		=	color[rt]*(m-l+1);
		SUM[rs]		=	color[rt]*(r-m);
		color[rt]	=	-1;
	} 
}
LL query(LL L,LL R,LL rt,LL l,LL r){
	if (L<=l && r<=R){
		return Origin[rt]-SUM[rt];
	}
	PushDown(rt,l,r);
	LL m=(l+r)>>1;
	LL ans=0;
	if (m>=L) ans+=query(L,R,lson);
	if (m<R)  ans+=query(L,R,rson);
	PushUp(rt,l,r);
	return ans;
}


LL update(LL num,LL L,LL R,LL rt,LL l,LL r){
	LL ans=0;
	if (L<=l && r<=R){
		if (SUM[rt]<=num) {
			ans+=SUM[rt];
			SUM[rt]=0;
			color[rt]=0;
			return ans;
		}
		if (l==r && SUM[rt]>num) {
			SUM[rt]-=num;
			return num;
		} 
	} 
	PushDown(rt,l,r);
	LL m=(l+r)>>1;
	if (m>=L) ans+=update(num,L,R,lson);
	if (m<R && ans<num)  ans+=update(num-ans,L,R,rson);
	PushUp(rt,l,r);
	return ans;
}

void solve(){
	LL n,q;
	cin>>n>>q;
	build(root);
	memset(color,-1,sizeof(color));
	while(q--){
		LL cmd;
		cin>>cmd;
		if (cmd==1){
			LL x,num;
			cin>>x>>num;
			LL tmp=update(num,x,n,root);
			if (tmp<num) cout<<"overflow"<<endl;
		}else{
			LL k;
			cin>>k;
			cout<<query(1,k,root)<<endl;
		} 
	}
}
int main(){
	freopen("datain.txt","r",stdin);
	freopen("dataout.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL T;
	cin>>T;
	while(T--){
		solve();
	}
}
