/*11：Pku acm 1631 Bridging signals最长上升子序列的加强版….二分法*/
#include "iostream"
#include "string"
using namespace std;
#define N 50000
int f[N];
int a[N];
int main()
{
	int n,m,i,j,max;
	scanf("%d",&n);
	while(n--)
	{
		max=-99;
		memset(f,0,sizeof(f));
		scanf("%d",&m); 
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
// f[i]=a[i];
		}
		f[1]=a[0];
		int s=1;
		int l,r,mid;
		for(i=1;i<m;i++)
		{
			if(f[s]<a[i])
				f[++s]=a[i];
			else
			{
				l=0;
				r=s;
				mid=(l+r)>>1;
				while(l<=r)
				{
					mid=(l+r)>>1;
					f[mid]<a[i]?l=mid+1:r=mid-1;
				}
				f[l]=a[i];
			}
		}
		printf("%d\n",s);
	}
}
