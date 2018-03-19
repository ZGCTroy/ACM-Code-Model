#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
typedef int State[9];
const int maxstate=1000000;
State st[maxstate];
State goal= {1,2,3,4,5,6,7,8,0};
int fa[maxstate][2];
const int nxt[4][2]= {-1,0,1,0,0,1,0,-1};
const char direction[4]= {'u','d','r','l'};
const int hashsize=1000003;
int head[hashsize],nxt2[maxstate];
void init_lookup_table()
{
	memset(head,0,sizeof(head));
}
int myhash(State& s)
{
	int v=0;
	for (int i=0; i<9; i++) v=v*10+s[i];
	return v%hashsize;
}
int try_to_insert(int s)
{
	int h=myhash(st[s]);
	int u=head[h];
	while (u)
	{
		if (memcmp(st[u],st[s],sizeof(st[s]))==0) return 0;
		u=nxt2[u];
	}
	nxt2[s]=head[h];
	head[h]=s;
	return 1;
}

int bfs()
{
	init_lookup_table();
	int front =1,rear=2;
	fa[front][0]=-1;
	while (front<rear)
	{
		State& s=st[front];
		if (memcmp(goal,s,sizeof(s))==0) return front;
		int z;
		for (z=0; z<9; z++) if (!s[z]) break;
		int x=z/3,y=z%3;
		for (int k=0; k<4; k++)
		{
			int tx=x+nxt[k][0];
			int ty=y+nxt[k][1];
			int tz=tx*3+ty;
			if  (tx>=0 && tx<3 && ty>=0 && ty<3)
			{
				State& t=st[rear];
				memcpy(&t,&s,sizeof(s));//复制上一个状态到一个新的状态
				t[tz]=s[z]; //0移动，交换位置
				t[z]=s[tz];
				fa[rear][0]=front;
				fa[rear][1]=k;
				if (try_to_insert(rear)) rear++;
			}
		}
		front++;
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	int i;
	char ch;
	while(scanf("%c ",&ch)==1)
	{
		if (ch!='x') st[1][0]=ch-'0';
		else st[1][0]=0;
		for (i=1; i<9; i++)
		{
			scanf("%c ",&ch);
			if (ch!='x') st[1][i]=ch-'0';
			else st[1][i]=0;
		}

		int ans=bfs();

		//输出
		if (ans>0)
		{
			char a[1000];
			int pre=ans;
			i=1;
			do
			{
				a[i]=(direction[ fa[pre][1] ]);
				i++;
				pre=fa[pre][0];
			}
			while(fa[pre][0]!=-1);
			for (i=i-1; i>=1; i--) printf("%c",a[i]);
			cout<<endl;
		}
		else printf("-1\n");
	}
	return 0;
}
