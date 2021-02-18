#include<stdio.h>

    int t,n,ti,ni,l[20000],b[20000],r[20000],u[20000],solvable=0,result,moveLeft=0,moveBottom=0,moveUp=0,moveRight=0, height1,height2,sumOfRect=0;

    /* this function is for a type of case where the value of left points matches with other rectangles,
    then to solve the puzzle we have to move the rectangle either bottom or up
    */
void bottomOrUp(){
    
    /* b[ni] is the value to campare with the value of other rectangles bottom point which is used as b[n+1]
    if other rectangles bottom point is less than the comparing rectangle's bottom point, it will move up
    */
    if(b[ni]>b[ni+1]){
        b[ni+1]=b[ni+1]+1;
        
        moveUp++;

    } // if other rectangles bottom point is greater than the comparing rectangle's bottom point, it will move bottom 
    else if(b[ni]<b[ni+1]){
        b[ni+1]=b[ni+1]-1;
        moveBottom++;

    }
}

    /* this function is for a type of case where the value of bottom points matches with other rectangles,
    then to solve the puzzle we have to move the rectangle either left or right
    */

void leftOrRight(){
    /* l[ni] is the value to campare with the value of other rectangles left point which is used as l[n+1]
    if other rectangles left point is less than the comparing rectangle's left point, it will move on the right
    */
    if(l[ni]>l[ni+1]){ 
        l[ni+1]=l[ni+1]+1;
        moveRight++;
    } // if other rectangles left point is greater than the comparing rectangle's left point, it will move on the left 
    else if(l[ni]<l[ni+1]){
        l[ni+1]=l[ni+1]-1;
        moveLeft++;
    }
}

    /* for each number of points of a rectangle,
    this function checks if there is any point value that matches with other rectangle's point value
    */
void match(){

   for(ni=0;ni<n;ni++){

        //if the bottom point matches then it the loop wil continue for further operations
        if(b[ni]==b[ni+1]){
            //if the left point is not same then the while loop will continue until it matches both left point
                while(l[0]!=l[ni+1]){
            /*as bottom point is same so we only need to move left or right, 
                    so the leftOrRight() function is called to do that operation
              */
                    leftOrRight();

                }
            //if the left points are matched then it will go out of the loop
                if(l[0]=l[ni+1]){
                    break;
                }
        }
       
        //if the left point matches then it the loop wil continue for further operations
        if(l[ni]==l[ni+1]){
            //if the bottom point is not same then the while loop will continue until it matches both bottom points
                while(b[0]!=b[ni+1]){
            /*as left point is same so we only need to move bottom or up, 
                    so the bottomOrUp() function is called to do that operation
              */
                    bottomOrUp();

                }
            //if the bottom points are matched then it will go out of the loop
                if(b[0]=b[ni+1]){
                    break;
                }
        }

        /*there can be a type of case where neither left nor bottom will match,
            for such cases this loop will do the operations to solve the puzzle
       */
        if(l[ni]!=l[ni+1] && b[ni]!=b[ni+1]){
            
            //this while loop  will continue until the left points are matched
            while(l[0]!=l[ni+1]){

                    leftOrRight();

                }
            //this while loop  will continue until the bottom points are matched
                while(b[0]!=b[ni+1]){

                    bottomOrUp();

                }
        }


   }

}

/* this function is to check if the puzzle is solved or not
*/
void isSolvable(){
    
    /* to solve the puzzle the difference of the bottom and up point
        must be the same value for each rectangle in one tese case
     */
    
    
    //height1 is assigned to store the difference of the first rectangle
    height1=b[0] - u[0];

    for(ni=0;ni<n;ni++){
            //height2 is assigned to store the difference of the following rectangles
            height2=b[ni] - u[ni];
        //the value of height can have same value but positive or negative depending on its position in the plane
        //so taking the absolute value of the difference to compare
    if(   abs(height1)==abs(height2) ){
        //if the value is same then the puzzle can be solved
        //thus solvable variable is incremented
                        solvable++;

                } //if the value is not same then the puzzle can't be solved 
                    else{
                printf("Puzzle can't be solved\n");
                return 0;
                }

    }
    
    //user could take only 1 rectangle to play but it can't have any move
    //so we consider the puzzle can be solved if value of solvable is greater than 1
    if(solvable>1) {
         printf("\nPuzzle can be solved\n");
        //as the puzzle can be solved now the goal is to take steps and match the poitns to solve it
        //so the match() function is called
         match();
        //result holds the value of the total steps made to solve the puzzle
        result=moveRight+moveLeft+moveBottom+moveUp;
        //this prints the required number of steps
            printf("\nSteps required %d\n", result);
    }

}

void rectOutOfRange(){
    //if the sum of tangles exceeds 1000000 then it will show this message
    if(sumOfRect>1000000){
        printf("Total number of Rectangles is out of Range\n");
    }
//it prints the total number of rectangles used throughout the test cases
    printf("\nTotal number of Rectangles: %d", sumOfRect);
}


int main(){


    // taking the number of test case from user and assigning the value in varibale t
    
    printf("Enter the number of test case: ");
    scanf("%d", &t);

    // if value of t fulfills the condition, it will enter the for loop for further operations
    if(t>=1 && t<=200000){
        // this for loop will run until number of test case
            for(ti=0;ti<t;ti++){
                    printf("\n************************************\n");
                //this line shows for which number of test case the user will be giving the number of rectangles
                    printf("For the Test Case %d,\n",ti+1);
        //taking the number of rectangles from user and assigning the value in varibale n
        printf("Enter the number of Rectangles: ");
        scanf("%d", &n);

        //sumOfRect counts the number of variables used in over all test cases 
        sumOfRect=sumOfRect+n;

            // if value of n fulfills the condition, it will enter the for loop for further operations
            if(n>=1 && n<=200000){
                
                // this for loop will run until number of rectangles
                for(ni=0;ni<n;ni++){
                
                    /*taking input from the user for the rectangles points
                        left, bottom, rigth and up and assigning the values in l[ni], b[ni], r[ni] and u[ni]
                        using array so that we can store values of the points for each rectangle*/
                    
                   printf("Enter the points of the rectangle %d: (sequentially left, bottom, right and up)\n", ni+1);
                  scanf("%d %d %d %d", &l[ni],&b[ni], &r[ni], &u[ni]);
                    
        /*if the values of the points is less than -109 ang greater that 109 then the puzzle can't be solved
            thus it will jump out of the loop*/
                    
                    if( l[ni] <=-109 || l[ni]>=109 ){
                   printf("Rectangle Point out of Range\n");
                   break;
            }
             if( b[ni] <=-109 || b[ni]>=109 ){
                   printf("Rectangle Point out of Range\n");
                   break;
            }
            if( r[ni] <=-109 || r[ni]>=109 ){
                   printf("Rectangle Point out of Range\n");
                   break;
            }
            if( u[ni] <=-109 || u[ni]>=109 ){
                   printf("Rectangle Point out of Range\n");
                   break;
            }

                }


        }   //if the number of rectangle is out of range then it will show this message as the puzzle can't be solved 
                else{
                printf("Number of Rectangle is out of Range\n");
            }
                //after taking all the points of each rectangle isSolvable() function is called to check if it can be solved
            isSolvable();
        }



    }   //if the number of test case is out of range then it will show this message as the puzzle can't be solved
        else{
        printf("Test case out of Range\n");
    }

    //this function is to check if the number of rectangle is out of range and print the total number of rectangles
    rectOutOfRange();

    return 0;
}

