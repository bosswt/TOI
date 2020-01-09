#include <bits/stdc++.h>
using namespace std;
int w,l;
char land[100][100];
int area[100][100],visited[100][100],max_area = -1,water,min_water=999;
void find(int i,int j)
{
        visited[i][j] = 1;
        if(i-1 >= 0 && !visited[i-1][j] && land[i-1][j] == 'P') find(i-1,j);
        if(j+1 <w && !visited[i][j+1] && land[i][j+1] == 'P') find(i,j+1);
        if(i+1 < l && !visited[i+1][j] && land[i+1][j] == 'P') find(i+1,j);
        if(j-1 >= 0 && !visited[i][j-1] && land[i][j-1] == 'P') find(i,j-1);
}
int count_water(int x,int y,int side)
{
        int water = 0;
        int si = x-side+1;
        int sj = y-side+1;
        memset(visited,0,sizeof(visited));
        for(int i=si; i<=x; i++)
        {
                for(int j=sj; j<=y; j++)
                {
                        if(land[i][j] == 'P' && !visited[i][j])
                        {
                                water++;
                                find(i,j);
                        }
                }
        }
        return water;
}
int main()
{
        cin>>w>>l;
        for(int i=0; i<l; i++)
        {
                for(int j=0; j<w; j++)
                {
                        cin>>land[i][j];
                        if(land[i][j] == 'T') area[i][j] = 0;
                        else area[i][j] = 1;
                }
        }
        for(int i=1; i<l; i++)
                for(int j=1; j<w; j++)
                        if(land[i][j] != 'T') area[i][j] = min(area[i-1][j],min(area[i-1][j-1],area[i][j-1]))+1;
        // for(int i=0; i<l; i++)
        // {
        //         for(int j=0; j<w; j++)
        //         {
        //                 cout<<area[i][j];
        //         }
        //         cout<<endl;
        // }
        for(int i=0; i<l; i++)
                for(int j=0; j<w; j++)
                        max_area = max(max_area,area[i][j]);
        for(int i=0; i<l; i++)
        {
                for(int j=0; j<w; j++)
                {
                        if(max_area == area[i][j])
                        {
                                min_water = min(min_water,count_water(i,j,max_area));
                        }
                }
        }
        cout<<max_area*max_area<<" "<<min_water;

}
