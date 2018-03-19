#include <stdio.h>


int a[10],book[10];
void dfs(int step)
{
	
	int i,x,y,z;
	if (step==10) 
	{
		x=a[1]*100+a[2]*10+a[3];
		y=a[4]*100+a[5]*10+a[6];
		z=a[7]*100+a[8]*10+a[9];
		if (z==3*x && y==2*x) printf("%d,%d,%d\n",x,y,z);
		return 0;
	}
	
	for (i=1;i<=9;i++) 
	{
		if (book[i]==0)
		{
			book[i]=1;
			a[step]=i;
			dfs(step+1);
			book[i]=0;
		}
	}
}
int main()
{
	dfs(1);
	return 0;
}
