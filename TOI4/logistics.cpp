#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n,dis;
char from,to;
float median,sum;
map<char,vector<pair<char,int> > > node;
map<char,int> visited;
bool pass()
{
        char curnode = 'X';
        char temp;
        while(curnode != 'Y')
        {
                int c=0;
                for(int i=0; i<node[curnode].size(); i++)
                {
                        if(visited[node[curnode][i].first])
                                c++;
                }
                if(c==node[curnode].size() || node[curnode].empty())
                {
                        return false;
                }
                for(int i=0; i<node[curnode].size(); i++)
                {
                        if(!visited[node[curnode][i].first])
                        {
                                temp = node[curnode][i].first;
                        }
                }
                visited[curnode] = 1;
                curnode = temp;
        }
        return true;
}
int main()
{
        cin>>n;
        for(int i=0; i<n; i++)
        {
                cin>>from>>to>>dis;
                node[from].push_back(make_pair(to,dis));
                node[to].push_back(make_pair(from,dis));
        }
        if(pass())
        {
                visited.clear();
                char curnode = 'X';
                char temp;
                while(curnode != 'Y')
                {
                        vector<float> med;
                        for(int i=0; i<node[curnode].size(); i++)
                        {
                                if(!visited[node[curnode][i].first])
                                { temp = node[curnode][i].first;
                                  med.push_back(node[curnode][i].second);}
                        }
                        sort(med.begin(),med.end());
                        if(med.size()%2 == 1)
                        {
                                int s = (med.size()+1)/2;
                                printf("%c %c %.1f\n",curnode,temp,med.at(s-1));
                                sum += med.at(s-1);
                        }
                        else
                        {
                                int s = (med.size()+1)/2;
                                printf("%c %c %.1f\n",curnode,temp,(med.at(s-1)+med.at(s))/2);
                                sum += (med.at(s-1)+med.at(s))/2;
                        }
                        visited[curnode] = 1;
                        curnode = temp;
                }
                printf("%.1f",sum);
        }
        else
        {
                cout<<"broken";
        }
}
