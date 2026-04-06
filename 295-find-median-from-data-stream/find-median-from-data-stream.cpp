class MedianFinder {
public:
priority_queue<int, vector<int>, greater<int>> right;
priority_queue<int> left;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left.empty() and right.empty())
        right.push(num);

        else if (left.size()>right.size()){
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        else if (right.size()>left.size()){
            right.push(num);
            left.push(right.top());
            right.pop();
        }

        else{
            left.push(num);
            right.push(left.top());
            left.pop();
        }



    }
    
    double findMedian() {
        if(left.size()>right.size())
            return left.top();
        if(left.size()<right.size())
            return right.top();

        return (left.top()+right.top())/2.0;
        

        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */