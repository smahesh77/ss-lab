struct process{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[20],temp;
void fcfs(struct process *  p,int n){
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                flag=1;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
        if(!flag){
            break;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        while(sum<p[i].at)sum++;
        sum+=p[i].bt;
        p[i].ct=sum;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    printf("pno\tat\tbt\tct\ttat\twt\n");
    for(int i=0;i<n;i++)
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}
void main(){
    int n;
    printf("\nEnter number of processes : ");
    scanf("%d",&n);
    printf("\nEnter for proceses : \n");
    for(int i=0;i<n;i++){
        printf("Enter arrival time: ");
        scanf("%d\n",&p[i].at);
        printf("Enter burst time : ");
        scanf("%d\n",&p[i].bt);
    }
    fcfs(p,n);
}
