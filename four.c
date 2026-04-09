#include <stdio.h>
#include <stdlib.h>
//apply quick sort for the mean filter 
int part(int arr[],int low,int high){
    int i=low+1;
    int j=high;
    int pivot=arr[low];
    int temp;
    while(i<=j){
        while(arr[i]<=pivot && i<=high){
         i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }}
        temp=arr[low];
        arr[low]=arr[j];
        arr[j]=temp;
    
    return j;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int p=part(arr,low,high);
        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
}//minimum time complexity: O(nlogn) in the average case scenario

void mean_filter(int arr[5]){
   
     quick_sort(arr,0,4);
    int window[3];
   
    for(int i=1;i<4;i++){
//mean of the three adjacent elements in array and store it in windows array
        window[i-1]=(arr[i-1]+arr[i]+arr[i+1])/3;
    }

    printf("the mean filter is:\n");
    for(int i=0;i<3;i++){
        printf("%d ",window[i]);
    }
}



//median filter method better than mean filter
void med(int arr[5])
{
    int b[3];
int window[3];
//store array elements in temporary b array for current window of 3 elements
    for(int i=1;i<4;i++)
    {
        b[0]=arr[i-1];
        b[1]=arr[i];
        b[2]=arr[i+1];
// Copy the current element and its two neighbors into the array b
        quick_sort(b,0,2);   

        window[i-1] = b[1];  //Array to hold filtered value
    }

    printf("The median filter gives:\n");

    for(int i=0;i<3;i++)
    {
        printf("%d ",window[i]);
    }
}



int main(){
    int arr[5];
    printf("enter the sensor data \n");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
   
    //mean_filter(arr);

    med(arr);
}
