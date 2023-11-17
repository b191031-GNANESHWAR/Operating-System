#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;cin>>n;
   vector< pair< pair<int,int>,int> >process;
   for(int i=0;i<n;i++)
   {
      int proc,size;
      cin>>proc>>size;
      process.push_back({ {proc,size},0});
   }

   vector<pair<int,int> >mem_block;
   for(int i=0;i<n;i++)
   {
   	  int size;cin>>size;
   	  mem_block.push_back({size,0});
   }
   
   for(int i=0;i<n;i++)
   {
       int idx,min=INT_MAX;
       for(int j=0;j<n;j++)
       {
          if(process[i].first.second<=mem_block[j].first && mem_block[j].first<min && mem_block[j].second==0)
          {
          	min=mem_block[j].first;
          	idx=j;
          }
       }
       process[i].second=min;
       mem_block[idx].second=1;
   }

   for(auto i: process)
   	  cout<<i.first.first<<"  "<<i.first.second<<"  "<<i.second<<endl;
}