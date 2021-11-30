#include <iostream>
using namespace std;
void N2 (int a[], int n, int k);
void NlogN (int a[], int n, int k);
void quickSort (int a[], int low, int high);
int divide (int a[], int low, int high);
int main()
{
    int n, k;
    cin>>n;
    int *array=new int[n];
    for (int i=0; i<n; i++) cin>>array[i];
    cin>>k;
    N2 (array, n, k);
    cout<<endl;
    NlogN (array, n, k);
    cout<<endl;
    delete array;
    return 0;
}
void N2 (int a[], int n, int k)
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]+a[j]==k) cout<<'('<<a[i]<<','<<a[j]<<')';
}
int divide (int a[], int low, int high)
{
    int k=a[low];
    do {
        while (low<high&&a[high]>=k) --high;
        if (low<high) {a[low]=a[high]; ++low;}
        while (low<high&&a[low]<=k) ++low;
        if (low<high) {a[high]=a[low]; --high;}
    }while (low!=high);
    a[low]=k;
    return low;
}
void quickSort (int a[], int low, int high)
{
    int mid;
    if (low>=high) return;
    mid=divide(a, low, high);
    quickSort (a, low, mid-1);
    quickSort (a, mid+1, high);
}
void NlogN (int a[], int n, int k)
{
   quickSort (a, 0, n-1);
   int high=n-1, low=0;
   while (low<high)
   {
       if (a[low]+a[high]>k) --high;
       else if (a[low]+a[high]==k)
            {
                cout<<'('<<a[low]<<','<<a[high]<<')';
                low++; high--;
            }
            else ++low;
   }
}
