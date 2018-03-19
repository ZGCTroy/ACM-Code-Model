#include <stdio.h>
struct Note
{
	int x;
	int y;
	int pre;
}que[26];

int map[6][6];
int next[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int head=0,tail=1;
void print(int i)
{
		
		if (que[i].pre!=-1) print(que[i].pre);
		printf("%d,%d\n",que[i].x,que[i].y);
}

int main()
{
	FILE *fp=NULL;
	fp=fopen("data.txt","r");
	int i,j;
	for (i=0;i<5;i++)
		for (j=0;j<5;j++)
			fscanf(fp,"%d",&map[i][j]);
	
	que[head].x=0;
	que[head].y=0;
	que[head].pre=-1;
	
	while (head<tail)
	{
		int k,tx,ty;
		for (k=0;k<4;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			if (tx<0 || tx>4 || ty<0 || ty>4 || map[tx][ty]==1)
				continue;
			else
			{
				map[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].pre=head;
				tail++;	
			}
			if (tx==4 && ty==4) print(tail-1);	
		}
		head++;
	}
	
	return 0;
	
		
}
