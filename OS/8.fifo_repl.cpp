#include<bits/stdc++.h>
using namespace std;

bool hit_check(int key,int page[],int n)
{
  for(int i=0;i<n;i++)
     if(key==page[i])
       return true;
  return false;
}

int main()
{
  int n;
  cout<<"Enter the input size: ";cin>>n;
  int arr[n];
  
  cout<<"Enter the inputs: ";
  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  int f;
  cout<<"Enter no.of frames: ";cin>>f;
  int page[f];
  
  int curr=0;
  while(curr!=f)
  {
    page[curr]=arr[curr];
    curr++;
  }
  
  int faults=f,hits=0;
  int top=0;
  while(curr<n)
  {
     if( hit_check(arr[curr],page,f) )
       hits++;
       
     else
     {
        page[top]=arr[curr]; 
        top++;
        
        if(top==f)
          top=0;
          
        faults++;
     }
     curr++;
  }
  
  cout<<"No.of page faults: "<<faults<<endl<<"No.of hits: "<<hits<<endl;
  cout<<"Resultant frame/last frame : "<<endl;
  int i=0;
  while(i<f)
    cout<<page[i++]<<endl;
}
     
  //0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1  #3
  //1, 3, 0, 3, 5, 6, 3
  
