/*10：Pku acm 2533 Longest Ordered Subsequence最长上升子序列*/
#include "iostream"
using namespace std;
int f[10000];
int a[10000];
int main()
{
	int n,i,j,max;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		memset(f,0,sizeof(f));
		max=0;
		for(i=1;i<=n;i++)
		{
			f[i]=1;
			for(j=0;j<=i;j++)
			{
				if(a[j-1]<a[i-1]&&f[j]+1>f[i])
					f[i]=f[j]+1;
				if(f[i]>max)
					max=f[i];
			}
			
		}
		printf("%d\n",max);
	}
	return 0;
}
