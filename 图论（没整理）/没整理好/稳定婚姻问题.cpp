#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
int P[maxn][maxn],Q[maxn][maxn],next[maxn];
int husband[maxn],wife[maxn];
queue<int> q;
void init()
{
	while (!q.empty()) q.pop();
	memset(next,0,sizeof(next));
	memset(wife,0,sizeof(wife));
	memset(husband,0,sizeof(husband));
	memset(P,0,sizeof(P));
	memset(Q,0,sizeof(Q));
}
void engage(int man,int woman)
{
	int m=husband[woman];
	if (m)
	{
		wife[m]=0;
		q.push(m);
	}
	wife[man]=woman;
	husband[woman]=man;
}
struct note
{
	int data,id;
} a[105][105];
bool cmp(note a,note b)
{
	return a.data>b.data;
}

int main()
{
	int T;
	freopen("data.txt","r",stdin);
	cin>>T;
	while (T--)
	{
		init();
		int n;
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
				scanf("%d",&P[i][j]);
			next[i]=0;
			wife[i]=0;
			q.push(i);
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
				scanf("%d",&Q[i][j]);
			husband[i]=0;
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				a[i][j].data=P[i][j]*Q[j][i];
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+n+1,cmp);
		}
		cout<<endl;
		while ( !q.empty() )
		{
			int man=q.front();
			q.pop();
			int woman=a[man][++next[man]].id;
			if (!husband[woman]) engage(man,woman);
			else if( (P[man][woman]*Q[woman][man]+P[]) > 
			(P[husband[woman]][woman]*Q[woman][husband[woman]]) )  engage(man,woman);
			else q.push(man);
		}
		int maxnsum=0;
		for (int i=1; i<=n; i++)
		{
			cout<<wife[i]<<" ";
			maxnsum+=P[i][wife[i]]*Q[wife[i]][i];
		}
		cout<<maxnsum;
		if (T) printf("\n");
	}
}
