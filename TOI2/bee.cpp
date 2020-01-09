#include <iostream>
#include <vector>
using namespace std;
vector<int>sol;
void Bee(int years)
{
        string parent;
        vector<char> child;
        int s=0;
        child.push_back('Q');
        child.push_back('W');
        parent = "QW";
        for(int i=0; i<years; i++)
        {
                int length = parent.length();
                for(int j=0; j<length; j++)
                {
                        if(parent[j] == 'Q')
                                child.push_back('W');
                        else if(parent[j] == 'W')
                                child.push_back('S');
                        else if(parent[j] == 'S')
                        {
                                child.push_back('W');
                                //vector<char>::iterator it;
                                //it = child.begin()+j;
                                child[j] = 'A';
                                s++;
                                //cout<<"/"<<length<<"/";
                        }
                }
                parent = "";
                for(int i=0; i<child.size(); i++)
                        parent+=child[i];
        }
        int W=0;
        for(int i=0; i<child.size(); i++)
        {
                //cout<<child[i];
                if(child[i] == 'W')
                        W++;
        }
        //cout<<W<<" "<<child.size()-s;
        sol.push_back(W);
        sol.push_back(child.size()-s);
}
int main()
{
        int years;
        do
        {
                cin>>years;
                if(years != -1)
                        Bee(years);
        } while(years != -1);
        int l=0;
        for(int i=0; i<sol.size(); i++)
        {
                cout<<sol[i]<<" ";
                l++;
                if(l==2)
                {
                        cout<<endl;
                        l = 0;
                }
        }
}
