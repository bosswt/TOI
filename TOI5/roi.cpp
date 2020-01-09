#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
double constant;
struct info
{
        double profit;
        int amount;
        int price;
};
vector<info>books;
bool cmp(info &a,info &b)
{
        return a.profit<b.profit;
}
int main()
{
        scanf("%lf",&constant);
        for(int i=1000; i<=15000; i+=500)
        {
                double variant = 100 - (i/500) +2;
                double charge = constant+(variant*i);
                for(int j=74; j<=144; j++)
                {
                        double sold =((100 - (0.8569 * exp(0.09*(j-100)))) * i ) / 100;
                        //cout<<sold<<endl;
                        double income = sold * j;
                        double profit;
                        profit = income - charge;
                        //cout<<"Num : "<<i<<" Charge : "<<charge<<" Sold : "<<sold<<" At : "<<j<<" Profit : "<<profit<<"\n";
                        if(profit > 0)
                        {
                                books.push_back({profit,i,j});
                        }
                }
        }
        sort(books.begin(),books.end(),cmp);
        printf("%d\n%d\n%.2lf",books[0].amount,books[0].price,books[0].profit);
}
