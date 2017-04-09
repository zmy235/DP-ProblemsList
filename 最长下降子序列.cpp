/*9：Pku acm 1887 Testing the CATCHER最长下降子序列*/
#include "iostream"
using namespace std;
int a[32769],f[32769];
int main()
{
	int i,j,n,max;
	int count=0;
	while(1)
	{   
		count++;
		scanf("%d",&a[0]);
		if(a[0]==-1)  break;
		i=1;
		while(1)
		{
			scanf("%d",&a[i]);
			if(a[i]==-1)
				break;
			i++;
		}
		n=i;
		max=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{   
			f[i]=1;
			for(j=0;j<=i;j++)
			{
				if(a[j-1]>a[i-1]&&f[j]+1>f[i])
					f[i]=f[j]+1;
				if(f[i]>max)
					max=f[i];
			}
		}
		printf("Test #%d:\n",count);
		printf("  maximum possible interceptions: %d\n\n",max);
	}
	return 0;
} 
