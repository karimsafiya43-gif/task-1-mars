#include <stdio.h>
#include <stdlib.h>

#define max 1000000

int main(){
    struct s{
        int inner;
        int mid;
        int outer;
        int cost;
    };

    int L1,L2,L3,w1,w2,w3;
//take inputs for the limit of the extension of each part
    printf("enter limits:\n");
    scanf("%d %d %d",&L1,&L2,&L3);
    //take inputs for the value of wear factor
    printf("enter wear factors: \n");
    scanf("%d %d %d",&w1,&w2,&w3);
//maximum difference
    int D;
    printf("difference between inner and outer: \n");
    scanf("%d",&D);
//total number of targets 
    int n;
    printf("enter the number of targets: \n");
    scanf("%d",&n);

    int target[n];
    printf("enter the target values: \n");
//value of targets distance 
    for(int i=0;i<n;i++){
        scanf("%d",&target[i]);
    }
//prev store configuration of the previous position
    //current stores the present state
    struct s prev[500];
    struct s cur[500];
//counts the number of states in previous array
    int p_count=0;
    //initialise all values with 0
   prev[0].inner=0;
   prev[0].mid=0;
   prev[0].outer=0;
   prev[0].cost=0;

   for(int i=0;i<n;i++){
    int c_count=0;
    int t=target[i];
//value to achieve in this iteration 
       //nested loop for all the combinations of the extension of each part
    for(int inner=0;inner<=L1;inner++){
        for(int mid=0;mid<=L2;mid++){
           int outer=t-inner-mid;
//calculate the outer extension needed to reach target
            //check if outer is within boundaries and condition for D
           if(outer>=0 && outer<=L3 && abs(inner-outer)<=D){
            int min_cost=max;
//initializing with maximum value 
            for(int j=0;j<=p_count;j++){
                int move_cost=abs(inner-prev[j].inner)*w1 + abs(mid-prev[j].mid)*w2 + abs(outer-prev[j].outer)*w3;
//calculating moving cost
                if(move_cost+prev[j].cost<min_cost){
                    min_cost=move_cost+prev[j].cost;
                    //current state with minimum cost then update the minimum value
                }
            }
//if a path is found for minimum cost save it into current array
            if(min_cost!=max){
                cur[c_count].inner=inner;
                cur[c_count].mid=mid;
                cur[c_count].outer=outer;
                cur[c_count].cost=min_cost;
                c_count++;
            }
           }
        }
    }
//put the value of current into previous to move to next target
    for(int k=0;k<c_count;k++){
        prev[k]=cur[k];
        p_count=c_count;
    }

    int answer=max;
//Update answer with the next lowest cost
    for(int i=0;i<p_count;i++){
        if(prev[i].cost<answer){
            answer=prev[i].cost;
        }

    }
    printf("minimum total wear cost is %d\n",answer);
   }

}
