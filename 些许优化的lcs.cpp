/*5：Pku acm 1159 Palindrome  回文串 带有些许优化的lcs*/
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;
int a[5005],b[5005];
int c[3],d[3];
string s1,s2;
int main()
{
int m,n=0;
int i,j;
while(cin>>n)
{  
if(n==0)  break;
cin>>s1;
s2=s1;
reverse(s2.begin(),s2.end());
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
for(i=0;i<n;i++)
{
b[0]=0;
for(j=0;j<n;j++)
{
if(s1[i]==s2[j])
{
b[j+1]=a[j]+1; 
}
else   if(b[j]>a[j+1])
{ 
b[j+1]=b[j];
}
else  if(b[j]<a[j+1])
{   
b[j+1]=a[j+1];
}
}
for(j=0;j<=n;j++)
a[j]=b[j];
}
printf("%d\n",n-b[n]);
}
}