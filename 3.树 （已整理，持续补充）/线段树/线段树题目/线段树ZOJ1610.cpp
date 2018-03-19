#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
const int N=8e3+10;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson ls,l,m
#define rson rs,m+1,r
#define root 1,1,N 
typedef long long LL;
#define PB push_back
int color[N<<2];
vector <int> ans;
map <int,int> vis;
void init(){
	ans.clear();
	vis.clear();
	memset(color,-1,sizeof(color));
}
void PushDown(int rt,int l,int r){
	int m=(l+r)>>1;
	if (color[rt]!=-1){
		color[ls]=color[rt];
		color[rs]=color[rt];
		color[rt]=-1;
	}
	return ;
}
void update(int val,int L,int R,int rt,int l,int r){
	if (L<=l && r<=R){
		color[rt]=val;
		return;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if (L<=m) update(val,L,R,lson);
	if (R>m)  update(val,L,R,rson);
	return;
}
void query(int rt,int l,int r){
	if (color[rt]!=-1) {
		for (int i=0;i<=r-l;i++) ans.PB(color[rt]); 
		return ;
	}
	if (l==r) return;	
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	query(lson);
	query(rson);
	return ;
}
void solve(int n){

	init();

	for (int i=0;i<n;i++){
		int L,R,val;
		cin>>L>>R>>val;
		L++;R++; 
		update(val,L,R-1,root);
	}
	
	query(root);
	
	int pre=-1;
	
	for (int i=0;i<ans.size();i++){
		if (ans[i]!=pre) vis[ans[i]]++;
		pre=ans[i];
	}
	
	for (map<int,int>::iterator it=vis.begin();it!=vis.end();++it) cout<<it->first<<" "<<it->second<<endl;
	
	//cout<<endl;
}
int main(){
//	freopen("datain.txt","r",stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	while(cin>>n){
		solve(n);
	}	
} 
