#include <iostream>
int table[22][22],maxtemp=-6,x,y,visited[22][22];
using namespace std;
void walk(int sx,int sy,int temp)
{
        if(!visited[sx][sy])
        {
                //printf("cmount[%d][%d] : %d temp : %d max : %d\n",sx,sy,table[sx][sy],temp,maxtemp);
                if(table[sx][sy] <= temp)
                        return;
                if(table[sx][sy] == 100)
                        return;
                if(maxtemp < table[sx][sy])
                        maxtemp = table[sx][sy];
                visited[sx][sy] = 1;
                walk(sx-1,sy,table[sx][sy]);
                walk(sx+1,sy,table[sx][sy]);
                walk(sx,sy-1,table[sx][sy]);
                walk(sx,sy+1,table[sx][sy]);
        }
}
int main()
{
        int M;
        cin>>M;
        cin>>y>>x;
        for(int i=1; i<=M; i++)
                for(int j=1; j<=M; j++)
                        cin>>table[i][j];
        walk(x,y,-6);
        cout<<maxtemp;
}
