#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class compare
{
public:
bool operator()(pair<int,int> &a,pair<int,int> &b)
{
        return a.first>b.first;
}
};
char table[26][26];
string str[101];
vector<pair<int,int> > position;
priority_queue<pair<int,int>,vector<pair<int,int> >,compare>pq;
int row,column;
char ch;
bool n(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r-i][c] == text[i] && r-i >= 0)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool s(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r+i][c] == text[i] && r+i < row)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool w(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r][c-i] == text[i] && c-i >= 0)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool e(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r][c+i] == text[i] && c+i < column)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool nw(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r-i][c-i] == text[i] && r-i >= 0 && c-i >= 0)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool ne(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r-i][c+i] == text[i] && r-i >= 0 && c+i < column)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool se(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r+i][c+i] == text[i] && r+i < row && c+i < column)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool sw(string text,int r,int c)
{
        int count=0;
        for(int i=0; i<text.length(); i++)
        {
                if(table[r+i][c-i] == text[i] && r+i < row && c-i >= 0)
                        count++;
                else break;
        }
        if(count == text.length()) return true;
        else return false;
}
bool find(string text,int r,int c)
{
        if(n(text,r,c))
                return true;
        else if(s(text,r,c))
                return true;
        else if(w(text,r,c))
                return true;
        else if(e(text,r,c))
                return true;
        else if(nw(text,r,c))
                return true;
        else if(ne(text,r,c))
                return true;
        else if(se(text,r,c))
                return true;
        else if(sw(text,r,c))
                return true;
        return false;
}
void check(string text)
{
        for(int i=0; i<row; i++)
        {
                for(int j=0; j<column; j++)
                {
                        if(table[i][j] == text[0])
                        {
                                if(find(text,i,j))
                                        pq.push(make_pair(i,j));
                        }
                }
        }
}
void reset(priority_queue<pair<int,int>,vector<pair<int,int> >,compare>&q)
{
        priority_queue<pair<int,int>,vector<pair<int,int> >,compare> b;
        swap( q, b );
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>row>>column;
        for(int i=0; i<row; i++)
        {
                for(int j=0; j<column; j++)
                {
                        cin>>ch;
                        table[i][j] = tolower(ch);
                }
        }
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
                cin>>str[i];
                transform(str[i].begin(), str[i].end(), str[i].begin(), ::tolower);
                check(str[i]);
                position.push_back(pq.top());
                reset(pq);
        }
        for(pair<int,int>i:position)
                cout<<i.first+1<<" "<<i.second+1<<endl;
}
/*
   8 11
   ascDEFGhigg
   hTqkComPutk
   FayUcompuTm
   FcsierMqsrc
   bkoArUePeyv
   Klcbqwekumk
   sreTNIophtb
   yUiqlxcnBje
   4
   Compute
   Queue
   stack
   Pointer
 */
