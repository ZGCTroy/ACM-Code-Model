#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e2+5;
vector <int> g[maxn];
int val[maxn],siz[maxn],son[maxn],fa[maxn],dep[maxn],top[maxn],a[maxn],id[maxn],num=0; 
int tree[maxn*4];
int dfs1(int v,int f,int d){
	if (siz[v]) return siz[v]; 
	dep[v]=d;
	fa[v]=f;
	siz[v]=1;
	son[v]=0;
	int maxson=0;
	for (int i=0;i<g[v].size();i++){
		if (g[v][i]==f) continue; 
		int tmp=dfs1(g[v][i],v,d+1);
		siz[v]+=tmp;
		if (tmp>maxson) {
			son[v]=g[v][i];
			maxson=tmp;
		}
	} 
	return siz[v];
}
int dfs2(int v,int f,int tp){
	top[v]=tp;
	a[++num]=v;
	id[v]=num;
	if (son[v]) val[v]+=dfs2(son[v],v,tp);
	for (int i=0;i<g[v].size();i++){
		if (g[v][i]==f || g[v][i]==son[v]) continue;
		val[v]+=dfs2(g[v][i],v,g[v][i]); 
	} 
	return val[v];
}
int build(int o,int l,int r){
	if (l==r) return tree[o]=val[ a[l] ];
	int mid=(l+r)/2;
	tree[o] = build(o*2,l,mid) + build(o*2+1,mid+1,r) ;
	return tree[o];
}
void update(int o,int p,int l,int r,int change){
	tree[o]+=change;
	if (l==r && l==p) {
		val[ a[p] ]+=change;
		return;
	}
	int mid=(r+l)/2;
	if (p<=mid) update(o*2,p,l,mid,change);
	else 		update(o*2+1,p,mid+1,r,change);
}
int query(int o,int l,int r,int L,int R){
	if (l>=L && r<=R) return tree[o];
	int ans=0;
	int mid=l+(r-l)/2; 
	if (mid>=L) ans+=query(o*2,l,mid,L,R);
	if (mid<R)	ans+=query(o*2+1,mid+1,r,L,R);
	return ans; 
}
int LCA(int a,int b){
	cout<<a<<" "<<top[a]<<" "<<b<<" "<<top[b]<<endl;
	if (dep[a]<dep[b]) swap(a,b);
	int ans=0;
	int tp1=top[a],tp2=top[b];
	while(tp1!=tp2){ 
		ans+=query(1,1,num,id[tp1],id[a]);
		a=fa[tp1];
		if (dep[a]<dep[b]) swap(a,b); 
		tp1=top[a];tp2=top[b];
	}

	
	if (dep[a]>dep[b]) swap(a,b); 
	ans+=query(1,1,num,id[a],id[b]);
	return ans;

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("datain.txt","r",stdin);
	
	int n,Q;
	cin>>n>>Q;
	val[0]=0;
	for (int i=1;i<=n;i++) cin>>val[i];
	for (int i=1;i<=n;i++) {
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(0,0,1);
	dfs2(0,0,1);
	build(1,1,num);

	while(Q--){
		int type,a,b;
		cin>>type>>a>>b;
		if (type==1)	update(1,id[a],1,num,b-val[a]);
		else cout<<LCA(a,b)<<endl;
	}  
} 
