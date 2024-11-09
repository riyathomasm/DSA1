#include<stdio.h>

int josephus(int n, int k){
    if(n==1){
        return 1;
    }
    return(josephus(n-1,k)+k-1)%n+1;

}

int main(){
    int n,k;
    printf("enter n and k: ");
    scanf("%d %d",&n, &k);
    int survivor = josephus(n,k);
    printf("survivor is number %d\n",survivor);
    return 0;
}

