#include<stdio.h>

    int t,n,ti,ni,l[20000],b[20000],r[20000],u[20000],solvable=0,result,moveLeft=0,moveBottom=0,moveUp=0,moveRight=0, height1,height2;


void bottomOrUp(){
    if(b[ni]>b[ni+1]){
        b[ni+1]=b[ni+1]+1;
        
        moveUp++;

    } else if(b[ni]<b[ni+1]){
        b[ni+1]=b[ni+1]-1;
        moveBottom++;

    }
}


void leftOrRight(){
    if(l[ni]>l[ni+1]){
        l[ni+1]=l[ni+1]+1;
        moveRight++;
    } else if(l[ni]<l[ni+1]){
        l[ni+1]=l[ni+1]-1;
        moveLeft++;
    }
}


void match(){

   for(ni=0;ni<n;ni++){

        //bottom match
        if(b[ni]==b[ni+1]){
                while(l[0]!=l[ni+1]){

                    leftOrRight();

                }
                if(l[0]=l[ni+1]){
                    break;
                }



                }
                //left match
        if(l[ni]==l[ni+1]){
                while(b[0]!=b[ni+1]){

                    bottomOrUp();

                }
                if(b[0]=b[ni+1]){
                    break;
                }



                }


   }

}

void isSolvable(){

    height1=b[0] - u[0];

    for(ni=0;ni<n;ni++){
            height2=b[ni] - u[ni];
    if(   abs(height1)==abs(height2) ){
                        solvable++;

                }
    }

    if(solvable>1) {
         printf("Puzzle can be solved\n");
         match();
        result=moveRight+moveLeft+moveBottom+moveUp;
            printf("Steps %d", result);
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


                }


        }
            }

    } else{
        printf("Test case out of Range");
    }

    isSolvable();

    return 0;
}

