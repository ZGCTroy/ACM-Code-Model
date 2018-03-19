#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
//快速读入数字，字符串用scanf("%s")即可（速度差不多，代码
/***********************************************************
                     读入数字
 ***********************************************************/
int read_num() {
    int res=0;
    bool flag=false;
    int ch;
    while( (ch=getchar())==' ' || ch=='\n') ;
    if ( ch == '-') flag=true;
    else if (ch>='0' && ch<='9') res=ch-'0';
    while( (ch=getchar()) >='0' && ch<='9' )
        res=res*10+ch-'0';
    return flag ? -res : res;
}

/**********************************************************
                         正数输出
 **********************************************************/
void Out(int x) {
    if (x>9) Out(x/10);
    putchar(x%10 + '0' );
}

/***********************************************************
                     有负数的输出
 ***********************************************************/
void print(int x) {
    if (x<0) {
        putchar('-');
        Out(-x);
    } else
        Out(x);
}



/***********************************************************
                             主程序
 ***********************************************************/
void solve() {
    int n,m;
    n=read_num();
    m=read_num();
    int a[n];
    for (int i=0; i<n; i++) {
        a[i]=read_num();
        print(a[i]);
        putchar(' ');
    }
    putchar('\n');
    int left[m],right[m];
    for (int i=0;i<m;i++){
        left[i]=read_num();
        right[i]=read_num();
        print(left[i]);
        putchar(' ');
        print(right[i]);
        putchar('\n');
    }
    putchar('\n');
    putchar('\n');
}

int main() {
    freopen("FASTIO读入测试.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        solve();
    }
    return 0;
}

