#include <cstdio>
#include <vector>
using namespace std;
int lane[102][42],m,n,t,visited[102][42];
vector<int>vec;
void dfs(int i,int j)
{
        if(i == t)
        {
                for(auto i:vec) printf("%d\n",i);
                return;
        }
        if(j-1>0 && !visited[i+1][j-1] && !lane[i+1][j-1])
        {
                vec.push_back(1);
                visited[i+1][j-1] = 1;
                dfs(i+1,j-1);
                vec.pop_back();
        }
        if(j+1<=m && !visited[i+1][j+1] && !lane[i+1][j+1])
        {
                vec.push_back(2);
                visited[i+1][j+1] = 1;
                dfs(i+1,j+1);
                vec.pop_back();
        }
        if(!visited[i+1][j] && !lane[i+1][j])
        {
                vec.push_back(3);
                visited[i+1][j] = 1;
                dfs(i+1,j);
                vec.pop_back();
        }
}
int main()
{
        scanf("%d %d %d",&m,&n,&t);
        for(int i=1; i<=t; i++) for(int j=1; j<=m; j++) scanf("%d",&lane[i][j]);
        dfs(0,n);
}
