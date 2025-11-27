/*Write a Program for Transposing the Matrix..
Prasannaa.V
CH.SC.U4CSE24138

*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int rows,columns;
    printf("Enter the Rows: ");
    scanf("%d",&rows);
    printf("Enter the COlumns: ");
    scanf("%d",&columns);
    int arr[rows][columns];

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter the %d %d Elemnt: ",i,j);
            scanf("%d",&arr[i][j]);

        }
    }
    if(rows==columns){

    for(int i=0;i<rows;i++){
        for(int j=i+1;j<columns;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;

        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n The time Complexity Of the Program is O(Rows*Columns)");

}
else{
    printf("Transpose is not Possible..\n");
}

    return 0;
}