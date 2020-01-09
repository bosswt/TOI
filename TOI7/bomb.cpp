#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> >point;
int mark[1000001];
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
        if(a.first == b.first) return a.second > b.second;
        return a.first>b.first;
}
int main()
{
        int n,x,y;
        cin>>n;
        for(int i=0; i<n; i++)
        {
                cin>>x>>y;
                point.push_back(make_pair(x,y));
        }
        sort(point.begin(),point.end(),cmp);
        //for(auto a:point) cout<<a.first<<" "<<a.second<<"\n";
        for(int i=0; i<n; i++)
        {
                if(mark[i]) continue;
                for(int j=i+1; j<n && !mark[j]; j++)
                {
                        //if(mark[j]) continue;
                        int curx=point[i].first,cury=point[i].second;
                        if(curx > point[j].first && cury > point[j].second)
                                mark[j]=1;
                }
        }
        for(int i=0; i<n; i++)
                if(!mark[i]) cout<<point[i].first<<" "<<point[i].second<<"\n";
}
