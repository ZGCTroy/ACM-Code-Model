#include <iostream>
#include <cstring>
using namespace std;
int n,maxsum=0,vis[105],p[105][105],q[105][105],a[105],res[105];
int dfs(int i,int sum)
{
	if (i==n+1)
	{
		if (sum>maxsum){
			maxsum=sum;
			for (int j=1;j<=n;j++) res[j]=a[j];
		}
	}
	else
	{
			for (int j=1; j<=n; j++)
			{
				if (!vis[j])
				{
					vis[j]=1;
					a[i]=j;
					dfs(i+1,sum+p[i][j]*q[j][i]);
					vis[j]=0;
				}
			}
	}
}
int main()
{
	int T;
	freopen("data.txt","r",stdin);
//不要脸的算法，大家不要抄啊，仅限oj的小数据，大数据是完全过不了的，这只是为了过oj 
	cin>>T;
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		maxsum=0;
		cin>>n;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				scanf("%d",&p[i][j]);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				scanf("%d",&q[i][j]);
		dfs(1,0);
		for (int i=1;i<=n;i++) cout<<res[i]<<" ";
		cout<<endl;
		cout<<maxsum<<endl;
	}
}
