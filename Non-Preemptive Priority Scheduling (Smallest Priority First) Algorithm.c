#include<stdio.h>
#define MAX 9999;
struct proc
{
    int no,at,bt,ct,wt,tat,pri,status;
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
    printf("Enter Priority: ");
    scanf("%d",&p.pri);
    p.status=0;
    return p;
}

void main()
{
    int n,s,ct=0,remaining;
    struct proc p[10],temp;
    float avgtat=0,avgwt=0;
    printf("<--Smallest Priority First Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        p[i]=read(i+1);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)    
            if(p[j].at>p[j+1].at)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
    p[9].pri=MAX;
    remaining=n;
    printf("\nProcessNo\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n");
    for(ct=p[0].at;remaining!=0;)
    {
        s=9;
        for(int i=0;i<n;i++)
            if(p[i].at<=ct && p[i].status!=1 && p[i].pri<p[s].pri)
                s=i;
        p[s].ct=ct=ct+p[s].bt;
        p[s].tat=p[s].ct-p[s].at;
        avgtat+=p[s].tat;
        p[s].wt=p[s].tat-p[s].bt;
        avgwt+=p[s].wt;
        p[s].status=1;
        remaining--;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[s].no,p[s].at,p[s].bt,p[s].pri,p[s].ct,p[s].tat,p[s].wt,p[s].wt);
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
}