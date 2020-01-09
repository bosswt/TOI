#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int but[4][4];
string w[10] = {"0","-1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
string ans;
int x,y;
void firstpress(int S,int M)
{
        float temp = S;
        y = ceil(temp/3);
        if(S%3 == 0)
                x = 3;
        else
                x = S%3;
        int pos = but[y][x];
        string word = w[pos];
        if(word == "-1")
        {
                while(M-- && !ans.empty())
                        ans.pop_back();
        }
        else
        {
                int num = M%word.length();
                if(num == 0)
                        ans += word[word.length()-1];
                else
                        ans += word[num-1];
        }
}
void press(int H,int V,int M)
{
        x+=H;
        y+=V;
        int pos = but[y][x];
        string word = w[pos];
        if(word == "-1")
        {
                while(M-- && !ans.empty())
                        ans.pop_back();
        }
        else
        {
                int num = M%word.length();
                if(num == 0)
                        ans += word[word.length()-1];
                else
                        ans += word[num-1];
        }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int k=1;
        for(int i=1; i<=3; i++)
        {
                for(int j=1; j<=3; j++)
                {
                        but[i][j] = k;
                        k++;
                }
        }
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
                int H,V,M,S;
                if(i==0)
                {
                        cin>>S>>M;
                        firstpress(S,M);
                }
                else
                {
                        cin>>H>>V>>M;
                        press(H,V,M);
                }
        }
        if(ans.empty()) cout<<"null";
        else cout<<ans;
}
