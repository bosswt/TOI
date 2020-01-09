#include "/Users/boss_wt/stdc++.h"
using namespace std;
int n,m,f,t,d,s,e,budget,visited[10001],dis[10001],dis2[10001],nearest=1e9,nearest_node;
class cmp
{
public:
bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second>b.second;
}
};
vector<pair<int,int> >g[10001];
vector<int>unreach;
pair<int,int> temp;
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp>pq;
int main()
{
        scanf("%d %d",&n,&m);
        scanf("%d %d %d",&s,&e,&budget);
        for(int i=0; i<m; i++)
        {
                scanf("%d %d %d",&f,&t,&d);
                g[f].push_back(make_pair(t,d));
                g[t].push_back(make_pair(f,d));
        }
        pq.push(make_pair(s,0));
        while(!pq.empty())
        {
                temp = pq.top();
                pq.pop();
                if(visited[temp.first]) continue;
                visited[temp.first] = 1;
                for(int i=0; i<g[temp.first].size(); i++)
                {
                        if(!visited[g[temp.first][i].first])
                        {
                                if(temp.second + g[temp.first][i].second > budget)
                                        unreach.push_back(temp.first);
                                else if(dis[g[temp.first][i].first] == 0 || dis[g[temp.first][i].first] > temp.second + g[temp.first][i].second)
                                {
                                        dis[g[temp.first][i].first] = temp.second + g[temp.first][i].second;
                                        pq.push(make_pair(g[temp.first][i].first,dis[g[temp.first][i].first]));
                                }
                        }
                }
        }
        if(visited[e])
        {
                printf("%d %d 0",e,dis[e]);
                return 0;
        }
        pq.push(make_pair(e,0));
        memset(visited,0,sizeof(visited));
        while(!pq.empty())
        {
                temp = pq.top();
                pq.pop();
                if(visited[temp.first]) continue;
                visited[temp.first] = 1;
                for(int i=0; i<g[temp.first].size(); i++)
                {
                        if(!visited[g[temp.first][i].first])
                        {
                                if(dis2[g[temp.first][i].first] == 0 || dis2[g[temp.first][i].first] > temp.second + g[temp.first][i].second)
                                {
                                        dis2[g[temp.first][i].first] = temp.second + g[temp.first][i].second;
                                        pq.push(make_pair(g[temp.first][i].first,dis2[g[temp.first][i].first]));
                                }
                        }
                }
        }
        for(int i=0; i<unreach.size(); i++)
        {
                if(dis2[unreach[i]] < nearest)
                {
                        nearest = dis2[unreach[i]];
                        nearest_node = unreach[i];
                }
                else if(dis2[unreach[i]] == nearest)
                        nearest_node = min(nearest_node,unreach[i]);
        }
        printf("%d %d %d",nearest_node,dis[nearest_node],nearest);
}
