#include<stdio.h>
#include<stdlib.h>

struct Job{
    int id;
    int profit;
    int deadline;

};

void sort(struct Job jobs[],int n){
    for(int i=0;i<n-1;i++){
        int swap=0;
        for(int j=0;j<n-i-1;j++){
            if(jobs[j].profit<jobs[j+1].profit){
                struct Job temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
                swap=1;
            }
           
        }
         if(swap!=1){
                break;
            }
    }
}

void jobsheduling(struct Job jobs[],int n){
    sort(jobs,n);
    int slots[10];
    for(int i=0;i<n;i++){
        slots[i]=-1;
    }
    int total_profit=0;

    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline-1;j>=0;j--){
            if(slots[j]==-1){
                slots[j]=jobs[i].id;
                total_profit+=jobs[i].profit;
                break;

            }
        }
    }
    printf("The selected Jobs are:\n");
    for(int i=0;i<10;i++){
        if(slots[i]!=-1){

            printf("Job %d ",slots[i]);
        }
    }
    printf("\nThe total profit is %d",total_profit);
}



int main(){
    int n;

    printf("Enter the number of Jobs: ");
    scanf("%d",&n);
    struct Job jobs[n];
    for(int i=0;i<n;i++){
        printf("Enter the ID of Job %d: ",i+1);
        scanf("%d",&jobs[i].id);
        printf("Enter the Profit of Job %d: ",i+1);
        scanf("%d",&jobs[i].profit);
        printf("Enter the Deadline of Job %d: ",i+1);
        scanf("%d",&jobs[i].deadline);
    }
    jobsheduling(jobs,n);
    return 0;
}
