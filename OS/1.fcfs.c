#include<stdio.h>
#include<stdlib.h>
#include<climits>

struct process{
  int at,bt,ct,tat,wt,vis;
};

int find_process(struct process p[],int n,int ideal)
{
   int min=INT_MAX,index=-1;
   for(int i=0;i<n;i++)
   {
     if(p[i].at<=ideal && p[i].vis==0)
     {
        if(p[i].at<min)
        {
           min=p[i].at;
           index=i;
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
  
  for(int i=0;i<n;i++){
    scanf("%d %d",&p[i].at,&p[i].bt);
    p[i].vis=0;
  }
  
  int ideal=0,ct=0; 
  while(ct<n)
  {
     int index=find_process(p,n,ideal);
     
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
       
     
  
