#include <iostream>
#include <queue>
int m,n,candle;
bool table[2001][2001];
char ch;
using namespace std;
queue<pair<int,int> >point;
void light(int x,int y)
{
        table[x][y] = 0;
        point.push(make_pair(x,y));
        while(!point.empty())
        {
                pair<int,int> t = point.front();
                point.pop();
                int row = t.first;
                int col = t.second;
                for(int i=-1; i<=1; i++)
                {
                        for(int j=-1; j<=1; j++)
                        {
                                if(i==0 && j==0) continue;
                                if(row+i>=0 && row+i<m && col+j>=0 && col+j<n)
                                {
                                        if(table[row+i][col+j])
                                        {
                                                table[row+i][col+j] = 0;
                                                point.push(make_pair(row+i,col+j));
                                        }
                                }
                        }
                }
        }
}
int main()
{
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++) for(int j=0; j<n; j++) scanf(" %c",&ch),table[i][j] = ch-'0';
        for(int i=0; i<m; i++)
        {
                for(int j=0; j<n; j++)
                {
                        if(table[i][j])
                        {
                                candle++;
                                light(i,j);
                        }
                }
        }
        printf("%d",candle);
}
