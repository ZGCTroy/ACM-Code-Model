//KMP总模板
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=1e4;

/**************************************************
                 构造模式串的失配函数
***************************************************/
void getFail(char *P,int *nxt){
    int m=strlen(P) ;
    nxt[0]=0;nxt[1]=0;
    for (int i=1;i<m;i++){
        int j=nxt[i];
        while(j && P[i]!=P[j]) j=nxt[j];
        nxt[i+1]= (P[i]==P[j] ? j+1 : 0 );
    }
}

/**************************************************
                     匹配查询
 ***************************************************/
void find(char *T,char *P,int *nxt){
    int n=strlen(T),m=strlen(P);
    getFail(P,nxt);
    int j=0;
    for (int i=0;i<n;i++){
        while(j && P[j]!=T[i]) j=nxt[j];
        if (P[j]==T[i]) j++;
        if (j==m) printf("%d\n",i-m+1);
    }
}
int main(){
    return 0;
}



