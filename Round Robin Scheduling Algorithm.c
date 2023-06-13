#include<stdio.h>
struct proc
{
    int no,at,bt,ct,tat,wt,rt;
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
    p.rt=p.bt;
    return p;
}
int main()
{
    struct proc p[10],tmp;
    float avgtat=0,avgwt=0;
    int n,tq,ct=0,flag=0,remaining, iter=0;
    printf("<--Round Robin Scheduling Algorithm-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);
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
    printf("\nProcessNo\tAT\tBT\tCT\tTAT\tWT\n");
    ct = p[0].at;
    for(int i=0;remaining!=0;)
    {
	iter ++;
        if(p[i].rt<=tq&&p[i].rt>0)
        {
			ct+=p[i].rt;
			p[i].rt=0;
			remaining--;
			p[i].ct=ct;
			p[i].tat=p[i].ct-p[i].at;
			avgtat+=p[i].tat;
            		p[i].wt=p[i].tat-p[i].bt;
            		avgwt+=p[i].wt;
			printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
			iter = 0;
        }
        else if(p[i].rt>0)
        {
			iter = 0;
			p[i].rt-=tq;
			ct+=tq;
        }
        if(i!=n-1&&p[i+1].at<=ct)
			i++;
	else if(iter > n){
			i = (i+1)%n;
			ct = p[i].at;
	}
        else
			i=0;
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
}
