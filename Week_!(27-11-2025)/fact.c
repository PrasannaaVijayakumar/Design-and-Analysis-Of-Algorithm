/*Find the Factorial of a Given Number
Prasannaa.V
CH.SC.U4CSE24138
*/
#include<stdio.h>
#include<stdlib.h>

int factorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }

    return n;

}
int main(){
    int n;
    printf("Enter the Number :");
    scanf("%d",&n);
    int x=factorial(n);
    printf("%d",x);
    printf("\n The Space Complexity of the Program is :O(n)");
    
    return 0;
}