#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

struct pos
{
	int x;
	int y;
	pos(int x=-1,int y=-1):x(x),y(y){}
};
struct sta
{
	 pos s;
	 int k; 
	 sta(pos s=pos(-1,-1),int k=0):s(s),k(k){}
};

int dp[105][105][100],key[100][100];
char map[105][105];
 int nxt[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int n,m;
pos start;

void bfs()
{
	
	memset(dp,-1,sizeof(dp));
	dp[start.x][start.y][0]=0;
	queue <sta> q;
	q.push(sta(start,0));
	
	while (!q.empty())
	{
		sta tmp=q.front();
		q.pop();
		for (int k=0;k<4;k++)
		{
			pos to=pos(tmp.s.x+nxt[k][0],tmp.s.y+nxt[k][1]);
			if (to.x<=0 || to.x>n || to.y<=0 || to.y>m) continue;
			if (map[to.x][to.y]=='#')	continue;
			
			int	sk=tmp.k;
			if (map[to.x][to.y]=='k') sk|=key[to.x][to.y];
			if (dp[to.x][to.y][sk]==-1 || dp[to.x][to.y][sk]>dp[tmp.s.x][tmp.s.y][tmp.k]+1)
				{
					q.push(sta(to,sk));
					dp[to.x][to.y][sk]=dp[tmp.s.x][tmp.s.y][tmp.k]+1;
				}
		}
		
	}
}
int main()
{
	int i,j;
	while(cin>>n>>m)
	{
	if (n==0 || m==0) break; 	
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			{
				cin>>map[i][j];
				if (map[i][j]=='@') 
				{
					start.x=i;
					start.y=j;
				}
			}
		
	int K;		
	cin>>K;
	for (i=1;i<=K;i++)
		{
			int a,b;
			cin>>a>>b;
			map[a][b]='k';
			int t=pow(2,i-1);
			key[a][b]=t;
		}
	bfs();
	int ans=-1;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			{
				int t=pow(2,K);
				if (map[i][j]!='k') continue;
				if (dp[i][j][t-1]==-1) continue;
				if (ans==-1 || ans>dp[i][j][t-1]) ans=dp[i][j][t-1];
			}
	cout<<ans<<endl;
	}
}
