/*Find the Fibanocci of a Given Number
Prasannaa.V
CH.SC.U4CSE24138
*/
#include<stdio.h>
#include<stdlib.h>

int fibanocci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fibanocci(n-1)+fibanocci(n-2);
    }

    return 0;


}


int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int x=fibanocci(n);
    printf("%d",x);
    printf("\n The Space Complexity of this Program is : O(n^2)");
    return 0;
}