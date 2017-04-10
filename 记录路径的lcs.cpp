/*4：Pku acm 2250 Compromise记录路径的lcs*/
#include "iostream"
#include "string"
using namespace std;
#define N 100
struct node 

{
string s;
}s1[N],s2[N];
int f[N][N];
int path[N][N];
string temp;
int flag;
void lcs(int i,int j)

{
if(i==0||j==0)  return ;
if(path[i][j]==1)  
{
lcs(i-1,j-1);

{ 
if(flag!=1)
{
cout<<s1[i-1].s<<endl;
flag=1;}
else
cout<<s1[i-1].s<<" ";}
}
else
if(path[i][j]==2)  lcs(i-1,j);
else lcs(i,j-1);
}
int main()

{
int i=0,j;
int len1,len2;
while(cin>>s1[0].s)

{
memset(f,0,sizeof(f));
i=1;
while(1)
{
cin>>temp;
if(temp=="#")  break;
s1[i++].s=temp;
}
len1=i;
i=0;
while(1)
{
cin>>temp;
if(temp=="#")  break;
s2[i++].s=temp;
}
len2=i;
memset(path,0,sizeof(path));
for(i=0;i<=len1;i++)
for(j=0;j<=len2;j++)
if(i==j)  f[i][j]=1;
for(i=1;i<=len1;i++)
for(j=1;j<=len2;j++)

{
if(s1[i-1].s==s2[j-1].s) 

{
f[i][j]=f[i-1][j-1]+1; 
path[i][j]=1;
}
else if(f[i-1][j]>=f[i][j-1])  

{
f[i][j]=f[i-1][j];
path[i][j]=2;
}
else

{
f[i][j]=f[i][j-1];
path[i][j]=3;
}
}
flag=1;
lcs(len1,len2);
cout<<endl;
}
}