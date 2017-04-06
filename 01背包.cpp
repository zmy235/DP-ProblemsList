01背包
有N件物品和一个容量为V的背包。第i件物品的大小是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。
用DP[I][J] 表示前I件物品放入一个容量为J的背包可以获得的最大价值。则
DP[I][J]= DP[I-1][J]                               ,J<C[I]
MAX（DP[I-1][J]，DP[I-1][J-C[I]]+W[I]）  , J>=C[I]

这样实现的空间复杂度为O(VN)，实际上可以优化到O（V）。以下是代码：
const int MAXW=13000;    //最大重量
const int MAXN=3450;     //最大物品数量

int c[MAXN];     //物品的存放要从下标1开始
int w[MAXN];     //物品的存放要从下标1开始
int dp[MAXW];

//不需要将背包装满，则将DP数组全部初始化为0
//要将背包装满，则初始化为DP[0]=0，DP[1]…DP[V]=-1(即非法状态)
int Packet(int n,int v) 
{
  int i,j;
  memset(dp,0,sizeof(dp));
  for(i=1;i<=n;++i) 
  {
    for(j=v;j>=c[i];--j) 
{  //这里是倒序，别弄错了
  dp[j]=MAX(dp[j],dp[j-c[i]]+w[i]);
}
}

return dp[v];} 