//Brute orce approach -o(n) time complexity
//Counting sort method

void sort012(int arr[], int n) {
    // code here
    int count0= 0;
    int count1= 0;
    int count2=0;
    for(int i=0; i<n; i++)
    {
       if(arr[i]== 0)
       {
           count0++;
       }
       if(arr[i]== 1)
       {
           count1++;
       }
       if(arr[i]== 2)
       {
           count2++;
       }
    }
    int index=0;
    for(int i=0;i<count0;i++)
    {
        arr[index++]=0;
    }
    for(int i=0;i<count1;i++)
    {
        arr[index++]=1;
    }
    for(int i=0;i<count2;i++)
    {
        arr[index++]=2;
    }
}

//optimal solution - o(n) Time comp - single pass approach
//Dutch national flag algo

void sort012(int arr[], int n) {
    int low=0, mid=0, high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }