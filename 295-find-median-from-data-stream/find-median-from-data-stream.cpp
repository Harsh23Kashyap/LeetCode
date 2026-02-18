class MedianFinder {
public:
  priority_queue<int> maxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half
    MedianFinder() {
        
    }
     void addNum(int num) {
        // Step 1: Add to maxHeap
        maxHeap.push(num);

        // Step 2: Ensure ordering property
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Balance sizes
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */