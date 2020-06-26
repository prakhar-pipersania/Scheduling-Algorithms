#include <stdio.h>
#define MIN -9999
struct proc
{
    int no,at,bt,ct,tat,wt,completed;
};
struct proc read(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n",i);
    p.no=i;
    printf("Enter Arrival Time: ");
    scanf("%d",&p.at);
    printf("Enter Burst Time: ");
    scanf("%d",&p.bt);
    p.completed=0;
    return p;
}
void main()
{
    int n,l,t,remaining;
    float hrr,temp,avgtat=0,avgwt=0;
    struct proc p[10],tmp;
    printf("<--Highest Response Ratio Next Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        p[i]=read(i+1);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)    
            if(p[j].at>p[j+1].at)
            {
            tmp=p[j];
            p[j]=p[j+1];
            p[j+1]=tmp;
            }
    remaining=n;
    printf("\n\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");
    for (t=p[0].at;remaining!=0;) 
    {
        hrr=MIN;
        for (int i=0;i<n;i++) 
            if (p[i].at<=t&&p[i].completed!=1) 
            {
                temp=(p[i].bt+(t-p[i].at))/p[i].bt;
                if (hrr<temp) 
                    hrr=temp,l=i;
            }
        t+=p[l].bt;
        p[l].ct=t;
        p[l].tat=p[l].ct-p[l].at;
        p[l].wt=p[l].tat-p[l].bt;
        p[l].completed = 1;
        remaining--;
    }
    for(int i=0;i<n;i++)
    {
        avgtat+=p[i].tat,avgwt+=p[i].wt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
}
