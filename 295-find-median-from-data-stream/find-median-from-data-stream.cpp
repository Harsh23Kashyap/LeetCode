class MedianFinder {
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    MedianFinder() {}

    void addNum(int num) {
        right.push(num);

        
        left.push(right.top());
        right.pop();

        if (left.size() > right.size()) {
            right.push(left.top());
            left.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return right.top();
    }
};