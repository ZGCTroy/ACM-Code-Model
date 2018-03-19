//后缀数组总模板
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20000+100;
const int maxm=1000000+100;
struct SuffixArray {
    int s[maxn];
    int sa[maxn],rnk[maxn],height[maxn];
    int t1[maxn],t2[maxn],c[maxm],n;
    void build_sa(int m) {
        int i,*x=t1,*y=t2;
        for(i=0; i<m; i++) c[i]=0;
        for(i=0; i<n; i++) c[x[i]=s[i]]++;
        for(i=1; i<m; i++) c[i]+=c[i-1];
        for(i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
        for(int k=1; k<=n; k<<=1) {
            int p=0;
            for(i=n-k; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++)if(sa[i]>=k) y[p++]=sa[i]-k;
            for(i=0; i<m; i++) c[i]=0;
            for(i=0; i<n; i++) c[x[y[i]]]++;
            for(i=1; i<m; i++) c[i]+=c[i-1];
            for(i=n-1; i>=0; i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;
            x[sa[0]]=0;
            for(i=1; i<n; i++)
                x[sa[i]]= y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]? p-1:p++;
            if(p>=n) break;
            m=p;
        }
    }
    void build_height() {
        int i,j,k=0;
        for(i=0; i<n; i++) rnk[sa[i]]=i;
        for(i=0; i<n; i++) {
            if(k)k--;
            j=sa[rnk[i]-1];
            while(s[i+k]==s[j+k]) k++;
            height[rnk[i]]=k;
        }
    }
    bool check(int l,int k) { //长l的出现k次以上的串
        int cnt=0;
        for(int i=1; i<n; i++) {
            if(height[i]<l)//新的一组开始
                cnt=1;
            else {
                cnt++;
                if(cnt>=k) return true;
            }
        }
        return false;
    }
    void print(int l,int k) {
        int cnt=0;
        for(int i=1; i<n; i++) {
            if(height[i]<l)//新的一组开始
                cnt=1;
            else {
                cnt++;
                if(cnt>=k) {
                    for (int j=0;j<l;j++) printf("%c",s[sa[i-1]+j]+'a'-1);
                    printf("\n");
                    return ;
                }
            }
        }
    }
} sa;

int main() {
    //freopen("datain.txt","r",stdin);
    string str;
    while(cin>>str) {
        for(int i=0; str[i]; i++) sa.s[i]=str[i]-'a'+1;
        sa.n=str.length()+1;
        sa.s[sa.n-1]=0;
        sa.build_sa(100+2);
        sa.build_height();
        int l=0,r=sa.n,maxlen,maxnum;
        while(l<=r) {
            int mid=(l+r)/2;
            if(sa.check(2,mid)) {
                l=mid+1;
                maxnum=mid;
            } else r=mid-1;
        }
        l=0;
        r=sa.n;
        while(l<=r) {
            int mid=(l+r)/2;
            if(sa.check(mid,maxnum)) {
                l=mid+1;
                maxlen=mid;
            } else r=mid-1;
        }
        sa.print(maxlen,maxnum);
        printf("%d\n",maxnum);
    }
    return 0;
}
