#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int N=3e5+5;
const int sigma_size=26;
const int maxnode=4e5+1;
const int MOD=20071027;
int d[N]; 
char str[N];
int ch[maxnode][sigma_size];
int val[maxnode];
int sz;
int idx(char c) {
	return c-'a';
}
void init(){
	sz=1;
	memset(d,0,sizeof(d));
	memset(ch[0],0,sizeof(ch[0]));
	memset(val,0,sizeof(val));
}
void insert(char *s,int v){
	int u=0,n=strlen(s);
	for (int i=0;i<n;i++){
		int c=idx(s[i]);		
		if (!ch[u][c]){
			memset(ch[sz],0,sizeof(ch[sz]));
			val[sz]=0;
			ch[u][c]=sz++;
		} 
		u=ch[u][c];    
	}
	val[u]=v;
}
int find(int k,int len){
	int ans=0,u=0; 
	for (int i=k;i<len;i++){
		char c=idx(str[i]);
		if (!ch[u][c]) break;
		if ( val[ ch[u][c] ] ) ans=(ans+d[i+1])%MOD; 
		u=ch[u][c];
	}
	return ans;	
}           
void solve(){
	init();
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		char words[101];
		scanf("%s",words); 		
		insert(words,1);
	}
	int len=strlen(str); 
	d[len]=1;
	for (int i=len-1;i>=0;i--)  d[i]=find(i,len);
	printf("%d\n",d[0]);     
}
int main(){
//	  freopen("datain.txt","r",stdin);
	  int cas=0;
	  while(~scanf("%s",str)){
			printf("Case %d: ",++cas);
			solve();
	  }   
} 
