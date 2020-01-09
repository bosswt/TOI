#include <cstdio>
using namespace std;
int tile[20][20],chk[20][20];
int count;
void flush(int i,int j,int &c)
{
  if(chk[i][j]) return ;
  chk[i][j] = 1;
  c++;
  if(tile[i][j] == tile[i-1][j]) flush(i-1,j,c);
  if(tile[i][j] == tile[i][j+1]) flush(i,j+1,c);
  if(tile[i][j] == tile[i+1][j]) flush(i+1,j,c);
  if(tile[i][j] == tile[i][j-1]) flush(i,j-1,c);
}
void check(int i,int j)
{
  int same = 0;
  if(tile[i][j] == 0 || chk[i][j])return ;
  if(tile[i][j] == tile[i+1][j] && tile[i][j] == tile[i][j+1] && !chk[i+1][j] && !chk[i][j+1]) flush(i,j,same);
  else if(tile[i][j] == tile[i-1][j] && tile[i][j] == tile[i][j-1] && !chk[i-1][j] && !chk[i][j-1]) flush(i,j,same);
  else if(tile[i][j] == tile[i+1][j] && tile[i][j] == tile[i][j-1] && !chk[i+1][j] && !chk[i][j-1]) flush(i,j,same);
  else if(tile[i][j] == tile[i-1][j] && tile[i][j] == tile[i][j+1] && !chk[i-1][j] && !chk[i][j+1]) flush(i,j,same);
  if(same == 3)
  count++;
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  scanf("%d",&tile[i][j]);
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  check(i,j);
  printf("%d",count);
}
