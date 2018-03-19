#include <stdio.h> 
#include <string.h> 
int main()
{
	int i,k,n,m,flag,dis[100],u[100],v[100],w[100];
	freopen("data1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for (i=1;i<=n;i++)
		dis[i]=9999999;
	dis[1]=0;
	
	for (k=1;k<=n-1;k++)
	{
		flag=0;
		for (i=1;i<=m;i++)
			if (dis[v[i]]>dis[u[i]]+w[i])
				{
					dis[v[i]]=dis[u[i]]+w[i];
					flag=1;
				}
		if (flag==0) break;
	}
	
	for (i=1;i<=n;i++)
	 printf("%d ",dis[i]);
}
