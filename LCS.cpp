最长公共子序列（LCS）
给出两个字符串a, b，求它们的最长、连续的公共字串。
这很容易就想到以DP[I][J]表示A串匹配到I，B串匹配到J时的最大长度。则：
0                       I==0 || J==0
DP[I][J]=DP[I-1][J-1]+ 1                  A[I]==B[J]
MAX（DP[I-1][J]，DP[I][J-1]）   不是以上情况 
但这样实现起来的空间复杂度为O(n^2)，而上面的方程只与第I-1行有关，所以可以用两个一维数组来代替。
以下是代码：
//最长公共子序列
const int SIZE=1001;
int dp[2][SIZE];   //两个一维数组 
//输入两个字符串，返回最大的长度
int LCS(const string& a,const string& b) 
{
  int i,j,flag;
  memset(dp,0,sizeof(dp));

  flag=1;
  for(i=1;i<=a.size();++i) 
  {
    for(j=1;j<=b.size();++j) 
    {
      if( a[i-1]==b[j-1] )      dp[flag][j]=dp[1-flag][j-1]+1;
      else         dp[flag][j]=MAX(dp[flag][j-1],dp[1-flag][j]);
    }
    flag=1-flag;
  }

  return dp[1-flag][b.size()];
} 