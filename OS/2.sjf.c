#include<stdio.h>
#include<stdlib.h>
#include<climits>

struct process{
  int at,bt,vis,ct,tat,wt;
};

int find_process(struct process p[],int n,int ideal)
{
   int min=INT_MAX,min_at=0,index=-1;
   for(int i=0;i<n;i++)
   {
     if(p[i].at<=ideal && p[i].vis==0)
     {
        if(p[i].bt<min)
        {
           min=p[i].bt;
           min_at=p[i].at;
           index=i;
        }
        else if(p[i].bt==min)
        {
          if(p[i].at<min_at)
           {
            min=p[i].at;
            min_at=p[i].at;
            index=i;
           }
        }
     }
   }
   return index;
}


int main()
{
  int n;
  printf("Enter no.of proceses: ");
  scanf("%d",&n);
  
  struct process p[n];
  printf("Enter values at & bt :\n");
  
  int min=INT_MAX,min_bt=0,index=0;
  for(int i=0;i<n;i++)
  {
    scanf("%d %d",&p[i].at,&p[i].bt);
    p[i].vis=0;
    
    if(p[i].at<min)
    {
        min=p[i].at;
        min_bt=p[i].bt;
        index=i;
    }
    else if(p[i].at==min)
    {
        if(p[i].bt<min_bt)
        {
          min=p[i].at;
          min_bt=p[i].bt;
          index=i;
        }
    }
  }
  
  int ideal=p[index].at-0;
  
  p[index].ct=ideal+p[index].bt;
  p[index].vis=1;
  ideal=p[index].ct;
  p[index].tat=p[index].ct-p[index].at;
  p[index].wt=p[index].tat-p[index].bt;
  
  int ct=01;
  while(ct<n)
  {
     index=find_process(p,n,ideal);
     
     if(index!=-1)
     {
       p[index].vis=1;
       p[index].ct=ideal+p[index].bt;
       ideal=p[index].ct;
       
       p[index].tat=p[index].ct-p[index].at;
       p[index].wt=p[index].tat-p[index].bt;
       ct++;
     }
     
     else
     {
       ideal+=1;
     }
  }
  
  printf("\nAT  BT  CT  TAT  WT\n");
  for(int i=0;i<n;i++)
    printf("%d   %d   %d   %d    %d\n",p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}
       
     
  
