#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map> 
using namespace std;
typedef long long LL;
#define ls (rt<<1)
#define rs (rt<<1|1) 
#define lson ls,l,m
#define rson rs,m+1,r
#define root 1,1,n
const int N=1e5+2;
const int inf=0x3f3f3f3f;
int change[4*N];
bool num[N];

/***********************************************************************************
                            			SetValue
************************************************************************************/
void SetValue(int val,int rt,int l,int r) {
	color[rt]=val;
}

/***********************************************************************************
                            向下传递（懒惰算法）(区间修改时加上去）
************************************************************************************/
void PushDown(int rt,int l,int r) {
	if(change[rt]) {			//区间赋值
		SetValue(color[rt],ls);
		SetValue(color[rt],rs);
		color[rt]=0;
	}
}


/***********************************************************************************
                                区间赋值（l,r)  = val
************************************************************************************/

void interval_assign(int L,int R,int val,int rt,int l,int r) {
	if (L<=l && r<=R) {
		SetValue(val,rt,l,r);
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	if(L<=m) interval_assign(L,R,val,lson);
	if(R>m) interval_assign(L,R,val,rson);
}


/***********************************************************************************
                                    区间（L,R)求和
************************************************************************************/

void query(int l,int r,int rt) {
	if (l==r) {
		num[change[rt]]=true;
		return ;
	}
	PushDown(rt,l,r);
	int m=(l+r)>>1;
	query(lson);
	query(rson);
	return;
}


struct node{
	int l,r;
}a[N];
/*************************************************************************************************************************
                                                            主程序
**************************************************************************************************************************/
set <int> vis;
vector <int> rnk;
map <int,int> binarysearch;
void solve() {
	memset(change,0,sizeof(change));
	memset(num,false,sizeof(num));
	vis.clear();
	rnk.clear();
	int n;
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>a[i].l>>a[i].r;
		vis.insert(a[i].l);
		vis.insert(a[i].r);
	}
	rnk.push_back( *vis.begin() );
	for (set<int>::iterator it=++vis.begin();it!=vis.end();it++){
		int t=*it;
		int pre=rnk[rnk.size()-1];
		if (t>pre+1) {
			rnk.push_back(t-1);
			rnk.push_back(t);
		} else{
			rnk.push_back(t);
		}
	}
	int siz=rnk.size();
	for (int i=0;i<siz;i++){
		binarysearch[rnk[i]]=i+1;
	}
	for (int i=0;i<n;i++){
		int L=binarysearch[a[i].l];
		int R=binarysearch[a[i].r];
		interval_assign(L,R,i+1,1,siz,1);
	}
	query(1,siz,1);
	int ans=0;
	for (int i=1;i<=n;i++) if (num[i]) ans++;
	cout<<ans<<'\n';
}

int main() {
//	freopen("datain.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}

