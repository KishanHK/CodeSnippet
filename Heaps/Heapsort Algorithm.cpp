#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;

        if(l<n && arr[l]>arr[largest]) {
                largest = l;
        }
        if(r<n && arr[r]>arr[largest]) {
                largest = r;
        }

        if(largest!=i) {
                swap(arr[largest],arr[i]);
                heapify(arr,n,largest);
        }

}
void Heapsort(int arr[],int n){
        int idx = n/2 - 1;

        for(int i = idx; i>=0; i--) {
                heapify(arr,n,i);
        }

        for(int i = n-1; i>=0; i--) {
                swap(arr[0],arr[i]);
                heapify(arr,i,0);
        }
        return;
}
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int v[] = {45,23,12,24,10,11};

        int n = sizeof(v)/sizeof(v[0]);

        Heapsort(v,n);

        for(int i = 0; i<n; i++) {
                cout<<v[i]<<" ";
        }


        return 0;
}
