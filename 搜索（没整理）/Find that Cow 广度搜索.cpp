#include <stdio.h>
int head=0,tail=1,s=0,N,K,flag[1000000];
struct Note
{
	int data;
	int pre;
}que[20000000];

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
			if (flag[que[head].data]==0)
			{
			{
				que[tail].data=que[head].data*2;
				que[tail].pre=head;
				if (que[tail].data==K)
				 {
					sum(tail);
					break;
				 }
				tail++;
			}
			
			{
				que[tail].data=que[head].data-1;
				que[tail].pre=head;
				if (que[tail].data==K)
				 {
					sum(tail);
					break;
				 }
				tail++;
			}
			
			{
				que[tail].data=que[head].data+1;
				que[tail].pre=head;
				if (que[tail].data==K)
				 {
					sum(tail);
					break;
				 }
				tail++;
			}
		}
			head++;
	}  
}
int main()
{
	scanf("%d%d",&N,&K);
	func();
	printf("%d %d",s,tail);
	return 0;
}

