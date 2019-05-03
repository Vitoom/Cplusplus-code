#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int begin, int end){
    int pivot = arr[begin];
    while(begin<end){
        while(begin<end && arr[end]>=pivot) --end;
        arr[begin] = arr[end];
        while(begin<end && arr[begin]<=pivot) ++begin;
        arr[end] = arr[begin];
    }
    arr[begin] = pivot;
    return begin;
}

void quick_sort(vector<int>& arr, int begin, int end){
    if(end-begin<=1) return;
    int pos = partition(arr, begin, end);
    quick_sort(arr, begin, pos-1);
    quick_sort(arr, pos+1, end);
}

int find_kth_number(vector<int>& arr, int k) {
    assert(k>0 && k<=arr.size());
    int begin=0,end=arr.size()-1;
    int target = 0;
    while(begin<end){
        int pos = partition(arr, begin, end);
        if(pos == k-1){
            target = arr[pos];
        }
        else if(pos > k-1) end = pos - 1;
        else begin = pos + 1;
    }
    return target;
}

int swap(vector<int>& arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void three_way_partition(vector<int>& arr, int target){
    int next_less_pos=0, next_bigger_pos=arr.size()-1;
    int next_scan_pos = 0;
    while(next_scan_pos <= next_bigger_pos){
        if(arr[next_scan_pos] < target) swap(arr, next_scan_pos++, next_less_pos++);
        else if(arr[next_scan_pos > target]) swap(arr, next_scan_pos, next_bigger_pos--);
        else next_scan_pos++;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}