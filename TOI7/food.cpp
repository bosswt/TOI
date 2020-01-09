#include <iostream>
#include <vector>
using namespace std;
vector<int>res;
int x[10],visited[10];
int n,m,f;
void per(int l,int N)
{
        if(N == 0)
        {
                for(auto i:res) cout<<i<<" ";
                cout<<"\n";
                return;
        }
        for(int i=1; i<=n; i++)
        {
                if(visited[i]) continue;
                visited[i] = 1;
                res.push_back(i);
                per(i,N-1);
                res.pop_back();
                visited[i] = 0;
        }
}
int main()
{
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
                cin>>f;
                x[f] = 1;
        }
        for(int i=1; i<=n; i++)
        {
                if(x[i]) continue;
                visited[i] = 1;
                res.push_back(i);
                per(i,n-1);
                res.pop_back();
                visited[i] = 0;
        }
}
