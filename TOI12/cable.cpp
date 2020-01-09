#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
class cmp
{
public:
bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
}
};
int n,m,s,e,passenger,from,to,carry;
vector<pair<int,int> >node[2510];
bool visited[2510];
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;
int main()
{
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
                scanf("%d %d %d",&from,&to,&carry);
                node[from].push_back(make_pair(to,carry-1));
                node[to].push_back(make_pair(from,carry-1));
        }
        scanf("%d %d %d",&s,&e,&passenger);
        pq.push(make_pair(s,100000000));
        while(!pq.empty())
        {
                pair<int,int> t = pq.top();
                pq.pop();
                if(t.first == e)
                {
                        //printf("%d %d\n",t.first,t.second);
                        //double max_carry = (double)(t.second - 1.00);
                        double guide = (ceil)((double)passenger/(double)t.second);
                        printf("%.0f",guide);
                        break;
                }
                if(visited[t.first]) continue;
                visited[t.first] = true;
                for(int i=0; i<node[t.first].size(); i++)
                {
                        if(!visited[node[t.first][i].first])
                                pq.push(make_pair(node[t.first][i].first,min(t.second,node[t.first][i].second)));
                }
        }
}
