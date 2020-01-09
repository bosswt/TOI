#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > point;
int max_h = -1,max_p = -1;
char mountain[11][100];
int main()
{
        memset(mountain,'.',sizeof(mountain));
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
                int s,h;
                cin>>s>>h;
                point.push_back(make_pair(s,h));
                max_h = max(max_h,h);
                max_p = max(max_p,s+2*h-1);
        }
        for(int i=0; i<n; i++)
        {
                int start = point[i].first,height = point[i].second,h=1;
                while(h<=height)
                {
                        mountain[h][start] = '/';
                        start++;
                        h++;
                }
        }
        for(int i=0; i<n; i++)
        {
                int start = point[i].first+point[i].second,h = point[i].second;
                while(h>=1)
                {
                        if(mountain[h][start] == '/')
                        {
                                mountain[h][start] = 'v';
                                break;
                        }
                        mountain[h][start] = '\\';
                        if(mountain[h][start+1] == '/') break;
                        start++;
                        h--;
                }
        }
        for(int i=max_h; i>=1; i--)
        {
                for(int j=1; j<=max_p; j++)
                {
                        if(mountain[i][j] == '/' || mountain[i][j] == 'v')
                        {
                                int start = j+1;
                                while(mountain[i][start] != '\\' && mountain[i][start] != 'v')
                                {
                                        mountain[i][start] = 'X';
                                        start++;
                                }
                        }
                }
        }
        for(int i=max_h; i>=1; i--)
        {
                for(int j=1; j<=max_p; j++)
                        cout<<mountain[i][j];
                cout<<"\n";
        }
}
