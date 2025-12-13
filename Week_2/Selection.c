#include<stdio.h>
#include<stdlib.h>
/*Prasannaa.V
CH.SC.U4CSE24138
Write a Program for Selection Sort??*/


void display(int n,int arr[]){
    for(int i=0;i<n;i++){
        if(i!=n-1){
            printf("%d,",arr[i]);
        }
        else{
            printf("%d",arr[i]);
        }
    }
}

void Selection(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int min=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
                
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;


        }
    }

    display(n,arr);
}
int main(){
    int n;
    printf("Enter the Number of Elements in the Array: ");
    scanf("%d",&n);


    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter %d Element:",i+1);
        scanf("%d",&arr[i]);
    }

    Selection(n,arr);
}