/*Write the Program to Find the sum of squares of first Natural numbers
Prasannaa.V
CH.SC.U4CSE24138
*/

#include<stdio.h>
#include<stdlib.h>

int natural(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i*i;
    }
    return sum;

}

int main(){
    int n;
    printf("Enter the Number: ");
    scanf("%d",&n);
    int x=natural(n);
    printf("The Sum of Squares of the First %d Natural Number is %d ",n,x);
    printf("\n The Space COmplexity of this Program is O(1). ");

    return 0;

}

