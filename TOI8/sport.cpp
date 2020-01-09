#include <iostream>
#include <string>
using namespace std;
int n,win,lose;
string res;
void print(int w,int l)
{
        if(w == n || l == n)
        {
                int len = res.length();
                for(int i=0; i<len; i++) cout<<res[i]<<" ";
                cout<<"\n";
                return;
        }
        else
        {
                res += 'W';
                print(w+1,l);
                res.pop_back();
                res += 'L';
                print(w,l+1);
                res.pop_back();
        }
}
int main()
{
        cin>>n>>win>>lose;
        print(win,lose);
}
