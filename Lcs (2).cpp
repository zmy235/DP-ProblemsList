/*3：Pku acm 1458 Common Subsequence Lcs经典*/
#include "iostream"
#include "cstring"
using namespace std;
int setmax(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
int f[8100][8100];
main()
{
    char s1[800];
    char s2[800];
    int i,j;
    int sl1,sl2;
    while(scanf("%s %s",&s1,&s2)!=EOF)
    {
        sl1=strlen(s1);
        sl2=strlen(s2);
        for(i=0; i<sl1; i++)
        {
            f[0][i]=0;
            f[i][0]=0;
        }
        for(i=1; i<sl1+1; i++)
            for(j=1; j<sl2+1; j++)
            {
                if(s1[i-1]==s2[j-1])
                    f[i][j]=f[i-1][j-1]+1;
                else
                    f[i][j]=setmax(f[i-1][j],f[i][j-1]);
            }
        printf("%d\n",f[i-1][j-1]);
    }
}
