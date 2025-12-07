#include<iostream>
#include<vector>
#include<algorithm>



void AdjustDown(std::vector<int>& arr,int root){
    int parent = root;
    int child = parent*2+1;

    while(child<arr.size()){
        if(child+1<arr.size()&&arr[child+1]<arr[child]){
            ++child;
        }

        if(arr[child] < arr[parent]){
            std::swap(arr[child],arr[parent]);
            parent = child;
            child = parent*2+1;
        }
        else{
            break;
        }
    }
}

void AdjustUp(std::vector<int>& arr,int root){
    int parent = root;
    int child = parent*2+1;

    while(child <arr.size()){
        if(child+1<arr.size()&& arr[child+1]>arr[child]){ ++child;}
    if(arr[child] > arr[parent]){
        std::swap(arr[child],arr[parent]);
        parent = child;
        child = parent*2+1;
    }
    else{
        break;
    }
}
}

void BuildMinHeap(std::vector<int>& arr){
    for(int i = ((arr.size() - 2)/2);i>=0;--i){
        AdjustDown(arr,i);
    }
}

void BuildMaxHeap(std::vector<int>& arr){
    for(int i = ((arr.size() - 2)/2);i>=0;--i){
        AdjustUp(arr,i);
    }
}

int main(){
    std::vector<int> arr = {9,6 ,5 ,1 ,5 ,8 ,3
};
std::vector<int> num={5,6,3,8,9,4,2};

    BuildMinHeap(arr);
    // AdjustDown(arr,0);
    for(auto e : arr){
        std::cout<<e<<" ";
    }
    std::cout << std::endl;
    BuildMaxHeap(num);
    // AdjustUp(num,0);
    for(auto e : num){
        std::cout<<e<<" ";
    }
    std::cout << std::endl;
}