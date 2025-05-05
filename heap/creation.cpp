#include<iostream>
#include<queue>
using namespace std;
// we are solving by max heap
class heap
{
    public:
    int arr[100];
    int size;

    // constructor
    heap(){
        arr[0]=-1;
        size=0;
    }

    // in heap 1st elememt arr[o] is -1,,,
    // for node=i th index...left child=(2*i)th index ....right child =(2*i+1)th index\
    // if we follow 0 index left=2*i+1 right=2*i+2
    // for parents =index/2;
    // leaf node index range=(n/2+1) se n tk 

    void insert(int value)
    {
        size++;
        int index=size;
        arr[index]=value;
        while(index>1){
            int parents=index/2;

            if(arr[index]>arr[parents]){
                swap(arr[index],arr[parents]);
                index=parents;
            }else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deletion(){
        // in heap deletion means deleting the root node
        arr[1]=arr[size];
        // remove last element
        size--;
        
        int i=1;
        while(i<size){
            int leftINDEX=2*i;
            int rightINDEX=2*i+1;
            if(leftINDEX<size && arr[leftINDEX]>arr[i]){
                swap(arr[leftINDEX],arr[i]);
                i=leftINDEX;;
            }
            else if(rightINDEX<size && arr[rightINDEX]>arr[i]){
                swap(arr[rightINDEX],arr[i]);
                i=rightINDEX;
            }
            else{
                return;
            }
        }

    }
};
void heapify(int arr[],int n,int i){
    int largest=i;
    int right=2*i+1;
    int left=2*i;
    
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    while(n>1){
        swap(arr[n],arr[1]);
        n--;//last element at is sorted place

        heapify(arr,n,1);
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion();
    h.print();
    int arr[]={-1,54,53,55,52,50};
    int n=5;//bec we dont count 0th index
    // we are using loop for n/2 to 1 bec 0th index is not get count in heap(-1) 
    // and n/2+1 to n are having leaf node which is already in heep(leaf node does not have any child so they  form heap)
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    // if we follow loop from from 1 to n/2 then it will check till last for every node so its complexcity will be 0(n)
    // aaise 0(logn) hai
    for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
    }cout<<endl;

    heapsort(arr,n);
    cout<<"heap sort applied:"<<endl;
    for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
    }cout<<endl;

    // max heap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(4);
    pq.push(6);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    // min heap
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(5);
    minheap.push(4);
    minheap.push(6);
    cout<<minheap.top()<<endl;
    minheap.pop();
    cout<<minheap.top();
}