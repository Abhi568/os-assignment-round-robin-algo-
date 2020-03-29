#include<stdio.h> 
int main() 
{ 
printf ("******************************************* Code for ROUND-ROBIN****************************************************");
printf("(:        (:          (:           Wait for 5 second           :)            :)          :)");
sleep(5);
printf("\n");
int arr_time[100],burst_time[100],rt[100] ,wait_time=0,turnaround_time=0; 
int time_quantum,count,j,n,time,remain;
int flag=0; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time for Process Process Number %d :",count+1); 
    scanf("%d",&arr_time[count]); 
    printf("Enter Burst Time:");
    scanf("%d",&burst_time[count]); 
    rt[count]=burst_time[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-arr_time[count],time-arr_time[count]-burst_time[count]); 
      wait_time+=time-arr_time[count]-burst_time[count]; 
      turnaround_time+=time-arr_time[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(arr_time[count+1]<=time) 
      count++; 
    else 
      count=0; 
  }
   
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
   
  
  return 0; 
}
