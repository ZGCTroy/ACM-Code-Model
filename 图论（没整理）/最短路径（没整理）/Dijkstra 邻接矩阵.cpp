#include <stdio.h>
int main()
{
	int n,m,i,j,u,v,book[100],e[100][100],dis[100];
	
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	
	
	for (i=1;i<=n;i++) 
	{
		dis[i]=99999;
		book[i]=0;
		for (j=1;j<=n;j++) e[i][j]=99999999;
		e[i][i]=0;
	}
	

		
	for (i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			scanf("%d",&e[u][v]);
		}
	for (i=1;i<=n;i++)
	 dis[i]=e[1][i];
	book[1]=1; 		
	
	for (i=1;i<=n-1;i++)
	{
		int min=99999999;
		for (j=1;j<=n;j++)
		{
			if (book[j]==0 && dis[j]<min)
			{
				min=dis[j];
				u=j;
			} 	
		}	
		book[u]=1;
		
		
		for (v=1;v<=n;v++)
			if (dis[v]>dis[u]+e[u][v]) 
				dis[v]=dis[u]+e[u][v];
	}	
	
	for (i=1;i<=n;i++) printf("%d ",dis[i]);
}
