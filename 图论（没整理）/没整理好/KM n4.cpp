#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1000;
int W[maxn][maxn],n;
int Lx[maxn],Ly[maxn];
int Left[maxn];
bool S[maxn],T[maxn];

bool match(int i)
{
	S[i]=true;
	for (int j=1; j<=n; j++) if (Lx[i]+Ly[j]== W[i][j] && !T[j] )
		{
			T[j]=true;
			if ( !Left[j] || match( Left[j] ) )
			{
				Left[j]=i;
				return true;
			}
		}
	return false;
}
void update()
{
	int a=1<<30;
	for (int i=1; i<=n; i++) if (S[i])
			for (int j=1; j<=n; j++) if (!T[j])
					a=min(a,Lx[i]+Ly[j]-W[i][j]);
	for (int i=1; i<=n; i++)
	{
		if (S[i]) Lx[i]-=a;
		if (T[i]) Ly[i]+=a;
	}
}
void KM()
{
	for (int i=1; i<=n; i++)
	{
		Left[i]=Lx[i]=Ly[i]=0;
		for (int j=1; j<=n; j++)
			Lx[i]=max(Lx[i],W[i][j]);
		//	cout<<Lx[i]<<endl;
	}
	for (int i=1; i<=n; i++)
	{
		for (;;)
		{
			for (int j=1; j<=n; j++) S[j]=T[j]=0;
			if (match(i)) break;
			else update();
		}
	}
}
int main()
{
	freopen("data1.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		int c;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
			{
				scanf("%d",&c);
				W[i][j]=c;
			//	cout<<W[x][y]<<endl;
			}
		for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			scanf("%d",&c);
			W[j][i]*=c;
		}
		int res=0;
		KM();
		for (int i=1; i<=n; i++)
		
		{
			res+=(Lx[i]+Ly[i]);
			//	cout<<res;
		}
		cout<<res<<endl;
	}
	return 0;
}
