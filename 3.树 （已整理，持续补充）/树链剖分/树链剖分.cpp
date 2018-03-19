#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1e4+5;
vector <int> g[maxn];
int siz[maxn],fa[maxn],dep[maxn],son[maxn],top[maxn],id[maxn],id_p[maxn],num,n;
struct edge{
	int v1,v2,p;
}e[maxn];
struct Tree{
	int l,r,maxp;
}tree[4*maxn];
void dfs1(int u,int f,int d){ //找出重链 
	siz[u]=1;
	fa[u]=f;
	dep[u]=d;
	son[u]=0;
	for (int i=0;i<g[u].size();++i) {
		int tmp=g[u][i];
		if (tmp==f) continue;
		dfs1(tmp,u,d+1);
		siz[u]+=siz[tmp]; 
		if (siz[tmp]>siz[son[u]]) son[u]=tmp;
	}
}
void dfs2(int u,int tp){ 	//连通所有重链
	 top[u]=tp;
	 id[u]=++num;
	 if (son[u]) dfs2(son[u],tp);
	 for (int i=0;i<g[u].size();++i){
	 	int tmp=g[u][i];
	 	if (tmp==fa[u] || tmp==son[u]) continue;
		dfs2(tmp,tmp);
	 }
}
#define left(x) ((x<<1))
#define right(x) ((x<<1)+1)
void build(int o,int l,int r){
	tree[o].l=l;
	tree[o].r=r;
	if (l==r){
		tree[o].maxp=id_p[l];
		return;
	}
	int mid=(l+r)>>1;
	build(left(o),l,mid);
	build(right(o),mid+1,r);
	tree[o].maxp=max(tree[left(o)].maxp,tree[right(o)].maxp);  //向上传递更新 
}
int query(int o,int l,int r){
	if (l<=tree[o].l && tree[o].r<=r) return tree[o].maxp;
	 
	int mid=(tree[o].l+tree[o].r)>>1;
	int ans=0;
	if (mid>=l) ans=max(ans,query(left(o),l,r));
	if (mid<r)  ans=max(ans,query(right(o),l,r) );
	return ans;
}
void update(int o,int v,int p){
	if (tree[o].l==tree[o].r) {
		tree[o].maxp=p;
		return;
	}
	int mid=(tree[o].l+tree[o].r)>>1;
	if (v<=mid) update(left(o),v,p);
	else		update(right(o),v,p);
	tree[o].maxp=max(tree[left(o)].maxp,tree[right(o)].maxp);
}
int LCA(int u,int v){
	int tp1=top[u],tp2=top[v];
	int ans=0;
	while(tp1!=tp2){
		if (dep[tp1]<dep[tp2]) {
			swap(tp1,tp2);
			swap(u,v);
		}
		ans=max(ans,query(1,id[tp1],id[u]));
		u=fa[tp1];
		tp1=top[u];
	} 
	if (u==v) return ans;
	if (dep[u]>dep[v]) swap(u,v);
	ans=max(ans,query(1,id[son[u]],id[v]));
	return ans;
}
void Clear(){
	for (int i=1;i<=n;++i) g[i].clear();
}
void func(){
	int T;
	cin>>T;
	while(T--){
		num=0;
		cin>>n;
		for (int i=1;i<n;++i){
			cin>>e[i].v1>>e[i].v2>>e[i].p;
			g[e[i].v1].push_back(e[i].v2);
			g[e[i].v2].push_back(e[i].v1);
		}
		dfs1(1,0,1);
		dfs2(1,1);
		for (int i=1;i<n;++i){
			if (dep[e[i].v1]<dep[e[i].v2]) swap(e[i].v1,e[i].v2);
			id_p[id[e[i].v1]]=e[i].p;
		}
		build(1,1,num);
		string str;
		while(cin>>str){
			if (str[0]=='D') break;
			int x,y;
			cin>>x>>y;
			if (str[0]=='C') update(1,id[e[x].v1],y);	
			else cout<<LCA(x,y)<<endl; 
		}
		Clear();
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	ios::sync_with_stdio(false);
	func();
}
