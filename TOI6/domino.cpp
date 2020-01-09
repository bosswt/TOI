#include <iostream>
#include <vector>
using namespace std;
vector<bool>res;
int n;
void print(int i)
{
        if(i>=n)
        {
                for(auto i:res)
                {
                        if(i) cout<<"--\n";
                        else cout<<"||\n";
                }
                cout<<"E\n";
                return;
        }
        res.push_back(true);
        print(i+1);
        res.pop_back();
        if(i+2 <= n)
        {
                res.push_back(false);
                print(i+2);
                res.pop_back();
        }
}
int main()
{
        cin>>n;
        print(0);
}
