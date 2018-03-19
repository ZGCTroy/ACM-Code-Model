#include <stdio.h>
int main()
{
	int que[100],dis[100],first[100],next[100],u[100],v[100],w[100],book[100];
	int head=1,tail=1,inf=99999999,n,m,i,j,k;
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	
	for (i=1;i<=n;i++) 
	{
		first[i]=-1;
		book[i]=0;
		dis[i]=inf;
	}
	dis[1]=0;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		next[i]=first[u[i]];
		first[u[i]]=i;
	}	
	
	que[tail]=1; tail++; book[1]=1;
	
	while (head<tail)
	{
		k=first[que[head]];
		while (k!=-1)
		{
			if (dis[v[k]]>dis[u[k]]+w[k])
			{
				dis[v[k]]=dis[u[k]]+w[k];
				if (book[v[k]]==0)
				{
					que[tail]=v[k];
					tail++;
					book[v[k]]=1;
				}	
			}
			k=next[k];
		}
		head++;
	}
	
	for (i=1;i<=n;i++)
		printf("%d ",dis[i]);
	
}
