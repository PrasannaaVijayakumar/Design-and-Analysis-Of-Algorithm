// Prasannaa.V, CH.SC.U4CSE24138

#include<stdio.h>
#include<stdlib.h>
/*Prasannaa.V
CH.SC.U4CSE24138*/
struct Node{
    char data;
    int freq;
    struct Node *left, *right;
};

// create node
struct Node* create(char data, int freq){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->freq = freq;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// find 2 minimum nodes
void findMin(struct Node* arr[], int n, int *m1, int *m2){
    *m1 = -1;
    *m2 = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == NULL) continue;

        if(*m1 == -1 || arr[i]->freq < arr[*m1]->freq){
            *m2 = *m1;
            *m1 = i;
        }
        else if(*m2 == -1 || arr[i]->freq < arr[*m2]->freq){
            *m2 = i;
        }
    }
}

// print codes
void print(struct Node* root, int code[], int top){
    if(root->left){
        code[top] = 0;
        print(root->left, code, top+1);
    }

    if(root->right){
        code[top] = 1;
        print(root->right, code, top+1);
    }

    if(!root->left && !root->right){
        printf("%c : ", root->data);
        for(int i = 0; i < top; i++){
            printf("%d", code[i]);
        }
        printf("\n");
    }
}


// main huffman
void huffman(char data[], int freq[], int n){
    struct Node* arr[100];

    for(int i = 0; i < n; i++){
        arr[i] = create(data[i], freq[i]);
    }

    int m1, m2;
    while(1){
        findMin(arr, n, &m1, &m2);

        if(m2 == -1) break;

        struct Node* newnode = create('$',
            arr[m1]->freq + arr[m2]->freq);

        newnode->left = arr[m1];
        newnode->right = arr[m2];

        arr[m1] = newnode;
        arr[m2] = NULL;
    }

    int code[100];
    print(arr[m1], code, 0);
}

// main function
int main(){
    char str[] = "DATAANALYTICSANDINTELLIGENCELABORATORY";
    int f[256] = {0};
    for(int i = 0; str[i] != '\0'; i++){
        f[str[i]]++;
    }
    char data[100];
    int freq[100];
    int n = 0;
    for(int i = 0; i < 256; i++){
        if(f[i] > 0){
            data[n] = i;
            freq[n] = f[i];
            n++;
        }
    }

    huffman(data, freq, n);

    return 0;
}