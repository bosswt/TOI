#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int M,N;
int visited[4][4];
double land[4][4];
void calc(int row,int col,double &price)
{
        double money = (10/100)*price;
        land[row][col] += money;
        if(row < 0 || row >= M || col < 0 || col >=N || visited[row][col]) return;
        visited[row][col] = 1;
        printf("%d %d %lf\n",row,col,price);
        calc(row-1,col-1,money);
        calc(row-1,col,money);
        calc(row-1,col+1,money);
        calc(row,col+1,money);
        calc(row+1,col+1,money);
        calc(row+1,col,money);
        calc(row+1,col-1,money);
        calc(row,col-1,money);
}
int main()
{
        scanf("%d %d",&M,&N);
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) scanf("%lf",&land[i][j]);
        for(int i=0; i<M; i++) for(int j=0; j<N; j++)
                {
                        memset(visited,0,sizeof(visited));
                        calc(i,j,land[i][j]);
                }
}
