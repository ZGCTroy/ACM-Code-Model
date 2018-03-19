#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std; 
int dis[201],num[201],A,B,n;
void bfs()
{
    queue <int> q; 
	memset(dis,-1,sizeof(dis));
	dis[A]=0;
	q.push(A);
	while(!q.empty())
	{
		int tmp=q.front();
		int up=tmp+num[tmp];
		int down=tmp-num[tmp];
		if (up<=n && up>=1)
			{
				if (dis[up]==-1 || dis[up]>=dis[tmp]+1)
					{
						dis[up]=dis[tmp]+1;
						q.push(up);	
					}	
			}
		
		if (down<=n && down>=1)
			{
				if (dis[down]==-1 || dis[down]>=dis[tmp]+1)
					{
						dis[down]=dis[tmp]+1;
						q.push(down);	
					}	
			}		
		
		q.pop();	
	}
}


int main()
{
	int i;
	scanf("%d",&n);
	while (n!=0)
	{
		scanf("%d%d",&A,&B);
		for (i=1;i<=n;i++) scanf("%d",&num[i]);
		bfs();
		printf("%d\n",dis[B]);
		scanf("%d",&n);
	}
}
