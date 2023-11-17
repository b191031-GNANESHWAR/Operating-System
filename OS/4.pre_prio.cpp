#include<bits/stdc++.h>
using namespace std;

struct process{
    int pri,at,bt,temp_bt,ct,tat,wt,vis;
};

bool comp(process p1,process p2)
{
     return (p1.at < p2.at);
}

int main()
{
   cout<<"Enter no.of processes: ";
   int n;  cin>>n;
   
   struct process p[n];
   priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
   
   cout<<"Enter the priority, at & bt:"<<endl;
   for(int i=0;i<n;i++)
   {
      cin>>p[i].pri>>p[i].at>>p[i].bt;
      pq.push({p[i].pri,i});
      
      p[i].temp_bt=p[i].bt;
      p[i].ct=0;
      p[i].tat=0;
      p[i].wt=0;
      p[i].vis=0;
   }
   
   sort(p,p+n,comp);

   int i=0,sum=p[0].at;
   while(!pq.empty())
   {
     
     if(p[i].temp_bt==0)
     {
       p[i].ct=sum;
       p[i].tat=p[i].ct-p[i].at;
       p[i].wt=p[i].tat-p[i].bt; 
       p[i].vis=1;
       
       pq.pop();
       if(!pq.empty())
       {
         i=pq.top().second;
         sum+=1;
         p[i].temp_bt-=1;
       }
     }
     
     else
     {
 	sum+=1;
     	p[i].temp_bt-=1;
     }
     
     int j=0;
     while(j<n && p[j].at<=sum)
     {
       if(p[j].vis==0 && p[j].pri<p[i].pri)
       {
         i=j;
         break;
       }
       j++;
     }
     
   }
   
   cout<<"AT\tBT\tCT\tTAT\tWT"<<endl;
   for(int i=0;i<n;i++)
      printf("%d\t%d\t%d\t%d\t%d\n",p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
   
} 
     
