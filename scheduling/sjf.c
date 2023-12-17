#include<stdio.h>
struct process{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[20],temp;
void main(){
    printf("\nEnter number of processes : ");
    int n;
    scanf("%d",&n);
    printf("\nEnter processes : ");
    for(int i=0;i<n;i++){
        printf("\nEnter at and bt: ");
        scanf("%d %d",&p[i].at,&p[i].bt);
    }
    //sorting based on arrival time
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                swapped=1;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

            }
        }
        if(swapped==0){
            break;
        }
    }
    int sum=0;
    int total_tat=0;
    int total_wt=0;
    int done=0;
    int check[n];
    for(int i=0;i<n;i++){
        check[i]=0;
    }
    while(done<n){
        int low=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=sum){
                if((low==-1 || p[i].bt<p[low].bt ) && check[i]==0){
                    low=i;
                }
            }
        }
        if(low==-1){
            sum++;
            continue;
        }
        sum+=p[low].bt;
        check[low]=1;
        p[low].ct=sum;
        p[low].tat=p[low].ct-p[low].at;
        p[low].wt=p[low].tat-p[low].bt;
        total_tat+=p[low].tat;
        total_wt+=p[low].wt;
        done++;
    }
    printf("Pno\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("total tat : %f",(float)total_tat/n);
    printf("\ntotal wt : %f",(float)total_wt/n);
}