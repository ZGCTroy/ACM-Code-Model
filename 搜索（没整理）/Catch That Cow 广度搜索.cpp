#include <stdio.h>
int head=0,tail=1,s=0,N,K,flag[200010];
struct Note
{
	int data;
	int pre;
}que[200010];

void sum(int i)
{
	s++;
	
	if (que[i].pre!=0) sum(que[i].pre);	
} 

void func()
{
	que[head].data=N;
	que[head].pre=0; 
	while (head<tail)
	{
		    if (flag[que[head].data*2]==0 && que[head].data<K)
				{
					flag[que[head].data*2]=1;
					que[tail].data=que[head].data*2;	
					que[tail].pre=head;
					if (que[tail].data==K)
						 {
							sum(tail);
							break;
						 }
					tail++;
				}
			if (flag[que[head].data+1]==0 && que[head].data+1<=K)
				{
					flag[que[head].data+1]=1;
					que[tail].data=que[head].data+1;
					que[tail].pre=head;
					if (que[tail].data==K)
				 		{
							sum(tail);
							break;
						 }
					tail++;
				}	
			if (flag[que[head].data-1]==0 && que[head].data-1>=0)
				{
					flag[que[head].data-1]=1;
					que[tail].data=que[head].data-1;
					que[tail].pre=head;
					if (que[tail].data==K)
						 {
							sum(tail);
							break;
				 		}
					tail++;
				}
	    	
			head++;
	}  
}
int main()
{
	scanf("%d%d",&N,&K);
	if (N<K) func();
	else s=N-K;
	printf("%d",s);
	return 0;
}

