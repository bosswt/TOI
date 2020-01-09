#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> >player;
int rope;
int main()
{
        int n,pos;
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&pos),player.push_back(make_pair(pos,1));
        for(int i=0; i<n; i++) scanf("%d",&pos),player.push_back(make_pair(pos,2));
        sort(player.begin(),player.end());
        for(int i=0; i<2*n; i++)
        {
                if(player[i].second == 0) continue;
                for(int j=i+1; j<2*n; j++)
                {
                        if(player[j].second == 0) continue;
                        if(player[i].second != player[j].second)
                        {
                                rope += player[j].first-player[i].first;
                                player[i].second = 0;
                                player[j].second = 0;
                                break;
                        }
                }
        }
        printf("%d",rope);
}
