#include <iostream>
using namespace std;
int m,n,cmd,score;
char map[6][6];
void print()
{
        for(int i=0; i<m; i++)
        {
                for(int j=0; j<n; j++)
                        cout<<map[i][j]<<" ";
                cout<<endl;
        }
}
void fall()
{
        for(int i=0; i<m; i++)
        {
                for(int j=0; j<n; j++)
                {
                        if(map[i][j] != '-' && map[i][j] != '#')
                        {
                                int r=i,c=j;
                                while(map[r+1][c] == '-')
                                {
                                        map[r+1][c] = map[r][c];
                                        map[r][c] = '-';
                                        r++;
                                }
                        }
                }
        }
}
int check(int r,int c)
{
        bool change  = false;
        if(map[r-1][c] == map[r][c])
        {
                //cout<<"Above"<<endl;
                score += 5;
                map[r-1][c] = '-';
                change = true;
        }
        if(map[r][c+1] == map[r][c])
        {
                //cout<<"Right"<<endl;
                score +=5;
                map[r][c+1] = '-';
                change = true;
        }
        if(map[r+1][c] == map[r][c])
        {
                //cout<<"Below"<<endl;
                score+=5;
                map[r+1][c] = '-';
                change = true;
        }
        if(map[r][c-1] == map[r][c])
        {
                //cout<<"Left"<<endl;
                score+=5;
                map[r][c-1] = '-';
                change = true;
        }
        if(change) return 1;
        else return 0;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>m>>n;
        for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                        cin>>map[i][j];
        cin>>cmd;
        for(int i=0; i<cmd; i++)
        {
                int r,c,ch=0;
                char dir;
                cin>>r>>c>>dir;
                if(map[r][c] == '-' || map[r][c] == '#')
                        score-=5;
                else
                {
                        if(dir == 'L')
                        {
                                if(map[r][c-1] == '#' || c-1 < 0)
                                        score-=5;
                                else
                                {
                                        map[r][c-1] = map[r][c];
                                        map[r][c] = '-';
                                        c=c-1;
                                        while(map[r+1][c] == '-')
                                        {
                                                map[r+1][c] = map[r][c];
                                                map[r][c] = '-';
                                                r++;
                                        }
                                        //  cout<<r<<" "<<c<<endl;
                                        //  print();
                                        ch = check(r,c);
                                        if(ch)
                                        {
                                                score+=5;
                                                map[r][c] = '-';
                                                fall();
                                        }
                                }
                        }
                        else
                        {
                                if(map[r][c+1] == '#' || c+1  >= n)
                                        score-=5;
                                else
                                {

                                        map[r][c+1] = map[r][c];
                                        map[r][c] = '-';
                                        c=c+1;
                                        while(map[r+1][c] == '-')
                                        {
                                                map[r+1][c] = map[r][c];
                                                map[r][c] = '-';
                                                r++;
                                        }
                                        //  cout<<r<<" "<<c<<endl;
                                        //print();
                                        ch = check(r,c);
                                        if(ch)
                                        {
                                                score+=5;
                                                map[r][c] = '-';
                                                fall();
                                        }
                                }
                        }
                        //cout<<endl<<endl;
                        //print();
                        //cout<<score<<endl;
                }
        }
        cout<<score<<endl;
        print();
}
