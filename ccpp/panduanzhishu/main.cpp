#include<stdio.h>
int main()
{
    int N,i;
    scanf("%d",&N);
    if(N==1||N==2){
        printf("YES");
    }
    else{
        for(i=2;i<N;i++){
            if(N%i==0){
                printf("NO");
                break;
            }
        }
       if(N==i){
           printf("YES");
       }
        
    }

    return 0;
}