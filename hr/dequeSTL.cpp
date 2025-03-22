#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> d;
    //remove
    // pop until last max
    // update with new max
    
    
    for(int i = 0; i < n; ++i) {
    
        if(d.size() != 0 && d.front() == i-k) {
            d.pop_front();
        }
        
while(d.size() != 0 && arr[d.back()] <= arr[i]){
        d.pop_back();
    }
    
    d.push_back(i);
    
    if(i >= k-1) {
        cout << arr[d.front()] << " ";
    }
    }
    cout << endl;
    
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
