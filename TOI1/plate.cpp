#include <iostream>
#include <vector>
using namespace std;
int s[10001];
struct student
{
        int cl,id;
};
vector<student> q;
void printqueue(vector<student> temp)
{
        cout<<"---------------"<<endl;
        for(auto i=0; i!=temp.size(); i++)
        {
                cout<<temp[i].cl<<" "<<temp[i].id<<endl;
        }
        cout<<"---------------"<<endl;
}
void addqueue(student tmp)
{
        int flag = 0;
        for(int i=0; i<q.size(); i++)
        {
                if(q[i].cl == tmp.cl and q[i+1].cl != tmp.cl and i+1 < q.size())
                {
                        vector<student>::iterator it;
                        it = q.begin()+i+1;
                        q.insert(it,tmp);
                        flag = 1;
                        break;
                }
        }
        if(!flag)
                q.push_back(tmp);
}
int main()
{
        int cl,n,tclass,tid;;
        cin>>cl>>n;
        for(int i=0; i<n; i++)
        {

                cin>>tclass>>tid;
                s[tid] = tclass;
        }
        vector<int> sol;
        student tmp;
        char ch;
        do
        {
                cin>>ch;
                switch(ch)
                {
                case 'E': cin>>tid;
                        if(s[tid] != 0)
                        {
                                //  cout<<"Found"<<endl;
                                tmp.cl = s[tid];
                                tmp.id = tid;
                                s[tid] =0;
                                if(q.empty()) q.push_back(tmp);
                                else
                                        addqueue(tmp);
                        }
                        //printqueue(q);
                        break;
                case 'D': if(q.empty()) cout<<"empty";
                        else
                        {
                                vector<student>::iterator it;
                                tmp = q.front();
                                it = q.begin();
                                q.erase(it);
                                sol.push_back(tmp.id);
                        }
                        //printqueue(q);
                        break;
                default: break;
                }
        } while(ch != 'X');
        for(auto i=sol.cbegin(); i!=sol.cend(); i++)
                cout<<*i<<endl;
        cout<<"0";
}

/*
   2 6
   1 41
   1 42
   1 43
   2 201
   2 202
   2 203
   E 41
   E 201
   D
   E 202
   E 42
   E 43
   D
   E 203
   D
   D
   D
   X
 */
