#include <cstdio>
#include <list>
using namespace std;
list<int>l;
list<int>::iterator it,it2;
int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++) l.push_back(i);
        m--;
        it = l.begin();
        while(!l.empty())
        {
                for(int i=0; i<m; i++)
                {
                        it++;
                        if(it == l.end())
                                it = l.begin();
                }
                printf("%d ",*it);
                it2 = it;
                it2++;
                if(it2 == l.end())
                        it2 = l.begin();
                l.erase(it);
                it = it2;
                if(it == l.end())
                        it = l.begin();
        }
}
