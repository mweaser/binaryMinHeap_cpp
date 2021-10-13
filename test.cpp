#include "Minheap.h"
#include <iostream>

using namespace std;

int main(){
    MinHeap<int> heap(2);

    for (int i = 1; i <= 3; i++){
        heap.add(i, i);
    }

    while(heap.isEmpty() == false){
        int temp = heap.peek();
        cout << temp << endl;
        heap.remove();
    }
    // for (int i = 1; i <= 3; i++){
    //     int temp = heap.peek();
    //     cout << temp << endl;
    //     heap.remove();
    // }
	return 0;

    

}
