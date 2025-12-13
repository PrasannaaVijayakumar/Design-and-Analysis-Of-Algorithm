#include<stdio.h>
#include<stdlib.h>
void Display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int flag =0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;


            }
        }
        if(flag==0){
            break;
        }
    }

    Display(arr,n);

}

int main(){
    int n;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        printf("Enter the %d Element: ",i);
        scanf("%d",&arr[i]);


    }

    bubble(arr,n);
}