#include<bits/stdc++.h>
using namespace std;

struct frame{
   int val;
   int ts;//time stamp
};

int  hit_check(struct frame page[],int key,int n)
{
  for(int i=0;i<n;i++)
     if(key==page[i].val)
       return i;
  return -1;
}

int find_lru_idx(struct frame page[],int n)
{
  int mn=INT_MAX;
  int idx=0;
  for(int i=0;i<n;i++)
  {
    if(page[i].ts<mn)
    {
      mn=page[i].ts;
      idx=i;
    }
  }
  return idx;
}

int main()
{
  int n;
  cout<<"Enter the input size: ";cin>>n;
  int arr[n];
  
  cout<<"Enter the input: ";
  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  int f;
  cout<<"Enter no.of frames: ";cin>>f;
  struct frame page[f];
  
  int curr=0,time=0;
  while(curr!=f)
  {
    page[curr].val=arr[curr];
    page[curr].ts=time;
    time++;
    curr++;
  }
  
  
  int faults=f,hits=0;
  while(curr<n)
  {
     int idx=hit_check(page,arr[curr],f);
     if(idx!=-1)
     {
       page[idx].ts=time;
       time++;
       hits++;
     }
     
     else
     {
        int idx=find_lru_idx(page,f);
        page[idx].val=arr[curr];
        page[idx].ts=time;
        time++;
        faults++;
     }
     curr++;
  }
  
  cout<<"No.of page faults: "<<faults<<endl<<"No.of hits: "<<hits<<endl;
  cout<<"Resultant frame/last frame : "<<endl;
  int i=0;
  while(i<f)
    cout<<page[i++].val<<endl;
}
     
  //7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
  
