#include <iostream>
#include <bitset>
#include <stack>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int binary[16384];
priority_queue<int> jones;
string decimal[16384];
int table[10],k;
vector<string> brackets;
int kebab;
int lol;
using namespace std;
int main() {
    for(int i=0; i<16384; i++)
    {
      binary[i] = i;
    }
     
    for(int i=0; i<16384; i++)
    {
    decimal[i] = bitset<14>(binary[i]).to_string();
    }
    
    for(int i=0; i<16384; i++)
    {
      
      for(int j=0; j<14; j++)
      {
        if(decimal[i].at(j) == '0')
        lol++;
        if(decimal[i].at(j) == '1')
        {
          if(lol > 0)
            lol--;
          else
            lol=lol-100;
        }
      }
    
    if(lol == 0)
    {
      brackets.push_back(decimal[i]);
    }
    else
    {
      lol = 0;
  
    }

      
    }
   for(int i=0; i<brackets.size(); i++)
   {
      for(int j=0; j<14; j++)
     {
      if(brackets[i].at(j) == '0')
       {
         kebab++;
        }
        if(brackets[i].at(j) == '1')
       {
         jones.push(kebab);
          kebab--;
        }
     }
     kebab = 0;
      for(int j=13; j>=0; j--)
     {
      if(brackets[i].at(j) == '1')
       {
         kebab++;
        }
        if(brackets[i].at(j) == '0')
       {
         jones.push(kebab);
          kebab--;
        }
     }
      table[jones.top()]++;
      while(!jones.empty())
     jones.pop();
   }
   for(int i=1; i<=10; i++)
   {
     cout<<i<<":"<<table[i]<<endl;
   }
   cout<<endl;
   
   for(int i=0; i<brackets.size(); i++)
   {
     for(int j=0; j<14; j++)
     {
       if(brackets[i].at(j) == '0')
       cout<<"(";
       if(brackets[i].at(j) == '1')
       cout<<")";
     }
     cout<<" ";
   }
   
    
}
