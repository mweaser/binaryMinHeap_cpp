#include <vector>
#include <iostream>


template <class T>
  class MinHeap {
     public:
       MinHeap (int d);
       /* Constructor that builds a d-ary Min Heap
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/

       ~MinHeap ();

       void add (T item, int priority);
         /* adds the item to the heap, with the given priority. */

       const T & peek () const;
         /* returns the element with smallest priority.  
			Break ties however you wish.  
			Throws an exception if the heap is empty. */

       void remove ();
         /* removes the element with smallest priority.
			Break ties however you wish.
            Throws an exception if the heap is empty. */

       bool isEmpty ();
         /* returns true iff there are no elements on the heap. */

        int d;
   private:
   
    std::vector<std::pair<T, int> > heap;
    int currSize;
    int parent(int i);
    int left(int i);
    int right(int i);

    void bubbleUp(int pos);
    void trickleDown(int pos);
  };











 /* Constructor that builds a d-ary Min Heap
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/

template <class T>
MinHeap<T>::MinHeap(int d){
    currSize = 0;
    this-> d = d;
  
}      

template <class T>
MinHeap<T>::~MinHeap (){}


/* adds the item to the heap, with the given priority. */
template <class T>
void MinHeap<T>::add (T item, int priority){

    std::pair<T, int> addPair;
    addPair.first = item;
    addPair.second = priority;

    heap.push_back(addPair);
    currSize++;

    bubbleUp((int)heap.size()-1);
}


/* returns the element with smallest priority.  
	Break ties however you wish.  
	Throws an exception if the heap is empty. */
template <class T>
const T & MinHeap<T>::peek () const{

    return heap[0].first;
}

/* removes the element with smallest priority.
	Break ties however you wish.
    Throws an exception if the heap is empty. */
template <class T>
void MinHeap<T>::remove (){

    if (isEmpty()){
        throw std::invalid_argument("Heap is empty");
    }
    heap[0].first = heap[(int)heap.size()-1].first;
    heap[0].second= heap[(int)heap.size()-1].second;
    heap.pop_back();
    trickleDown(0);

}


/* returns true iff there are no elements on the heap. */
template <class T>
bool MinHeap<T>::isEmpty (){
    if (heap.size() == 0){
        return true;
    }
    else{
        return false;
    }    
}

template <class T>
void MinHeap<T>::bubbleUp(int pos){
    int parentIndex = parent(pos);
    if (parent(pos) >= 0 && heap[parent(pos)].second > heap[pos].second){

        int first = heap[pos].first;
        int second = heap[pos].second;
        heap[pos].first = heap[parentIndex].first;
        heap[pos].second = heap[parentIndex].second;
        heap[parentIndex].first = first;
        heap[parentIndex].second = second;
        
        bubbleUp(parentIndex);
    }
}

template <class T>
void MinHeap<T>::trickleDown(int pos){
    if(heap.size() <= pos) {
        return;
    }
    int leftChild = left(pos);
    int rightChild = right(pos);
    int temp = heap[leftChild].second;
    int tempPosition = leftChild;
    for (int i = leftChild; i <= rightChild; i++){
        if(i > heap.size()-1){
            break;
        }
        if (heap[i].second < temp){
            temp = heap[i].second;
            tempPosition = i;
        }
    }

    if (heap[pos].second > temp){
        int first = heap[pos].first;
        int second = heap[pos].second;
        heap[pos].first = heap[tempPosition].first;
        heap[pos].second = heap[tempPosition].second;
        heap[tempPosition].first = first;
        heap[tempPosition].second = second;

       trickleDown(tempPosition);
    }



  
}

template <class T>
int MinHeap<T>::parent(int i){
    return (i-1)/d;
}

template <class T>
int MinHeap<T>::left(int i){
    return (d*i)+1;
}

template <class T>
int MinHeap<T>::right(int i){
    return (d*i) + d;
}

