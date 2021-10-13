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
        return;
}

void buildHeap(int arr[],int n){
        int startIdx = (n/2) - 1;
        for(int i = startIdx; i>=0; i--) {
                heapify(arr,n,i);
        }
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int v[] = {1,2,4,3};

        int n = sizeof(v)/sizeof(v[0]);

        buildHeap(v,n);

        for(int i = 0; i<n; i++) {
                cout<<v[i]<<" ";
        }


        return 0;
}
