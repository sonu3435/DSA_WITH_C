#include<stdio.h>
int Rprime(int);
void Lprime(int);
int prime(int);
int Lcount = 0;
int Rcount = 0;

int main(){
    int n,R;
    printf("Enter the value : ");
    scanf("%d",&n);
    
    R=prime(n);
    printf("Occurence : %d",R);

return 0;
}

int prime(int n){

    for(int i = 2; i < n; i++){
        if(n%i==0){
            Lprime(n-1);
            Rprime(n+1);
        }
    }
        if(Lcount == Rcount && Lcount == 0){
            return 0;
        }
        else if(Lcount == Rcount && Lcount != 0){
            return 2;
        }
        else if(Lcount != Rcount){
            return 1;
        }
}
int Rprime(int n){
    Rcount = Rcount+1;
    if(Rcount > Lcount){
        return 0;
    }
    for(int i = 2; i < n; i++){
        if(n%i==0){
            Rprime(n+1);
        }
    }
    return 0;
}
void Lprime(int n){
    Lcount++;
    for(int i = 2; i < n; i++){
        if(n%i==0){
            Lprime(n-1);
        }
    }
}