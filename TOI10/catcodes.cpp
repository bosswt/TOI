#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n_catcodes,l_catcodes,check_str,l_str;
string catcodes[100001],str;
int main()
{
        scanf("%d %d",&n_catcodes,&l_catcodes);
        for(int i=0; i<n_catcodes; i++)
                cin>>catcodes[i];
        scanf("%d",&check_str);
        for(int i=0; i<check_str; i++)
        {
                vector<int>res;
                scanf("%d",&l_str);
                cin>>str;

                for(int i=0; i<n_catcodes; i++)
                {
                        auto found =str.find(catcodes[i]);
                        if(found != string::npos)
                                res.push_back(i+1);
                }
                if(!res.empty())
                {
                        sort(res.begin(),res.end());
                        for(auto i:res) cout<<i<<" ";
                        cout<<"\n";
                }
                else cout<<"OK\n";
        }
}
