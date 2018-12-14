#include<stdio.h>
#include<stdbool.h>


    int x,t,n,ti,ni,l[20000],b[20000],r[20000],u[20000],solvable=0,result=0;


void left(){
    if(l[ni]>l[ni+1]){
        l[ni+1]=l[ni+1]+1;
        result++;
    } else if(l[ni]<l[ni+1]){
        l[ni+1]=l[ni+1]-1;
        result++;
    }
}

void bottom(){
    if(b[ni]>b[ni+1]){
        b[ni+1]=b[ni+1]+1;
        result++;
    } else if(b[ni]<b[ni+1]){
        b[ni+1]=b[ni+1]-1;
        result++;
    }
}
void right(){
    if(r[ni]>r[ni+1]){
        r[ni+1]=r[ni+1]+1;
        result++;
    } else if(r[ni]<r[ni+1]){
        r[ni+1]=r[ni+1]-1;
        result++;
    }
}

void up(){
    if(u[ni]>u[ni+1]){
        u[ni+1]=u[ni+1]+1;
        result++;
    } else if(u[ni]<u[ni+1]){
        u[ni+1]=u[ni+1]-1;
        result++;
    }
}

void match(){

    for(ni=0;ni<n;ni++){
        if(l[ni]==l[ni+1]){
            if(b[ni]!=b[ni+1]){
                while(b[ni]==b[ni+1]){
                bottom();
                }
            }
        }
    }
}

void isSolvable(){

    if(solvable>1) {
         printf("Puzzle can be solved\n");
         match();
         printf("%d", result);
    } else{
        printf("Puzzle can't be solved");
    }

}

int main(){



    printf("Enter the number of test case: ");
    scanf("%d", &t);

    if(t>=1 && t<=200000){
            for(ti=0;ti<t;ti++){

        printf("Enter the number of Rectangles: ");
        scanf("%d", &n);

            if(n>=1 && n<=200000){
                for(ni=0;ni<n;ni++){
                   printf("Enter the points of the rectangle %d: (sequentially left, bottom, right and up)\n", ni+1);
                  scanf("%d %d %d %d", &l[ni],&b[ni], &r[ni], &u[ni]);


                   printf("Values: %d %d %d %d\n", l[ni],b[ni], r[ni], u[ni]);
                   if( (b[ni] - u[ni])==1 || (b[ni] - u[ni])==-1){
                        printf("x:%d",b[ni] - u[ni]);
                        solvable++;
                }

                }

        }
            }

    } else{
        printf("Test case out of Range");
    }

    isSolvable();

    return 0;
}
