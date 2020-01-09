#include "/Users/boss_wt/stdc++.h"
using namespace std;
struct info
{
        int i,j,walk;
} t;
int n,m;
char table[2001][2001];
int visited[2001][2001],dist,pick;
int row[4] = {0,0,1,-1};
int col[4] = {-1,1,0,0};
queue<info >q;
int main()
{
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
                scanf("%s",table[i]);
        for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                        if(table[i][j] == 'X') q.push({i,j,0});
        while(!q.empty())
        {
                t = q.front();
                q.pop();
                if(table[t.i][t.j] == 'A')
                {
                        dist+=t.walk*2;
                        pick++;
                }
                for(int i=0; i<4; i++)
                {
                        if(t.i + row[i] >=0 && t.i+row[i] < n && t.j+col[i] >=0 && t.j + col[i] < m)
                        {
                                if(table[t.i+row[i]][t.j+col[i]] != 'W' && !visited[t.i+row[i]][t.j+col[i]])
                                {
                                        visited[t.i+row[i]][t.j+col[i]] = 1;
                                        q.push({t.i+row[i],t.j+col[i],t.walk+1});
                                }
                        }
                }
        }
        printf("%d %d",pick,dist);
}
