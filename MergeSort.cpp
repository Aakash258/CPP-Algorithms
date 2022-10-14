#include<bits/stdc++.h>
using namespace std;

//Merge sort is a sorting algorithm based on Divide and conquer, as the name suggests vector or array
//is first divided into two equal halves and then they are combined in sorted manner.


void merge(int l, int r,int mid,  int arr[]){
    //size of left subarray
    int left_size = (mid-l+1);

    //size of right subarray;
    int right_size = (r-mid);

    //Defining left_array to store values of left subarray and right subarray after merging;
    int larr[left_size];
    int rarr[right_size];

    //copy data to arrays larr[] and rarr[]
    for(int i = 0; i < left_size; i++){
        larr[i] = arr[l+i];
    }
    for(int i = 0; i < right_size; i++){
        rarr[i] = arr[mid+1+i];
    }

    
    int li = 0;//initial index of left subarray
    int ri = 0;//initial index of right subarray
    int k = l;//intial index of merged subarray;

    //merging both arrays back in the merged array;
    while(li < left_size && ri < right_size){
        if(larr[li] <= rarr[ri]){
            arr[k] = larr[li];
            li++;
        }
        else{
            arr[k] = rarr[ri];
            ri++;
        }
        k++;

    }


    //inserting remaining elements of larr[] if any;
    while(li < left_size){
        arr[k] = larr[li];
        k++;
        li++;
    }


    //inserting elements of rarr[] if any; 
    while(ri < right_size){
        arr[k] = rarr[ri];
        k++;
        ri++;

    }

}


//Below mergesort function divides the array in two equal parts by calling the function recursively
//and keep dividing the array in two equal parts till the size of array becomes 1.
//l denotes the left index and r denotes the right index of subarray of array to be merged;

void mergesort(int l, int r, int arr[]){
    if(l == r) return;

    //it is dividing the array by finding the middle most index value;
    //it is same as (l+r)/2 but avoids overflow for large r and l
    int mid = l + ((r-l)/2);

    //Calling mergesort function to sort first half;
    mergesort(l,mid,arr);

    //Calling mergesort function to sort second half;
    mergesort(mid+1, r, arr);

    //calling merge function to finally merge both halves in sorted order;
    merge(l,r,mid,arr);
}

//function to print array
void print_arr(int arr[], int size){
    for(int i = 0; i < size; i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    
    //taking array input 
    int arr[n];
    cout<<"Enter the elements of array : ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    //calling merge sort;
    mergesort(0,n-1,arr);

    //printing sorted array
    print_arr(arr,n);

    
    return 0;
}

