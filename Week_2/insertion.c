#include<stdio.h>
#include<stdio.h>

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        if(i!=n-1){
            printf("%d,",arr[i]);
        }
        else{
            printf("%d",arr[i]);
        }

    }

}


void insertion(int arr[],int n){
    //For the unsorted arrray:
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;

        //for Sorting inside the sorted array
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    display(arr,n);
}
int main(){
    int n;
    printf("Enter the number of Elements in the array: ");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        printf("Enter the %d the element: ",i);
        scanf("%d",&arr[i]);
    }
    insertion(arr,n);
    return 0;
}