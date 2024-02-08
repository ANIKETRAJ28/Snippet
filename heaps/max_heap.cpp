#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class PriorityQueue {
    public:
    vec<int> heap;

    void display() {
        /**
         * TC = O(n)
         * SC = O(1)
        */
        cout<<"[ ";
        for(int i = 0 ; i < heap.size() ; i++) {
            cout<<heap[i]<<" ";
        }
        cout<<"]\n";
    }

    void upHeapify() {
        /**
         * TC = O(logn)
         * SC = O(1)
        */
        int ci = heap.size()-1;
        while(ci > 0) {
            // parent index
            int pi = (ci-1)/2;
            if(heap[pi] < heap[ci]) {
                swap(heap[pi], heap[ci]);
                ci = pi;
            } 
            else break;
        }
    }

    void downHeapify() {
        /**
         * TC = O(logn)
         * SC = O(1)
        */
        int pi = 0;
        while(pi < heap.size()) {
            int maxElei = pi;
            int lci = 2*pi+1;
            if(lci >= heap.size()) return; // no leaf index
            if(heap[lci] > heap[maxElei]) maxElei = lci;
            int rci = 2*pi+2;
            if(rci < heap.size() and heap[rci] > heap[maxElei]) maxElei = rci;
            if(maxElei != pi) {
                swap(heap[maxElei], heap[pi]);
                pi = maxElei;
            }
            else break;
        }
    }

    void push(int val) {
        /**
         * TC = O(logn)
         * SC = O(1)
        */
        heap.push_back(val);
        // upheapification
        upHeapify();
    }

    void pop() {
        /**
         * TC = O(logn)
         * SC = O(1)
        */
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        // downheapification
        downHeapify();
    }

    int peek() {
        /**
         * TC = O(1g)
         * SC = O(1)
        */
        return heap[0];
    }
};

int main(){
    PriorityQueue pq;
    pq.push(3);  
    pq.push(4); 
    pq.push(11);  
    pq.push(9);  
    pq.push(14);  
    pq.push(-1);  
    pq.push(30);  
    pq.push(44);  
    pq.push(50);
    pq.display();
    pq.pop();
    pq.display();    
    pq.pop();
    pq.display();    
    pq.pop();
    pq.display();    
    return 0;
}