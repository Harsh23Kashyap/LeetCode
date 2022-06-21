class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int> > right;
    priority_queue<int> left;
    bool first;
    double med;
    MedianFinder() 
    {
        first=false;
    }
    
    void addNum(int num) 
    {
        cout<<"For num "<<num<<endl;
        if(first==false)
        {
            med=num;
            left.push(num);
            first=true;
        }
        else
        {
            //cout<<"Left "<<left.size()<<" and right "<<right.size()<<endl;
            if(left.size()>right.size())
            {
                if(num<med)
                {
                    right.push(left.top());
                    left.pop();
                    left.push(num);
                }
                else
                {
                    right.push(num);
                }
                med=(left.top()+right.top())/2.0;
            }
            else if (left.size()==right.size())
            {
                //cout<<"For "<<num<<endl;
                if(num<med)
                {
                    left.push(num);
                    med=left.top();
                }
                else
                {
                    right.push(num);
                    med=right.top();
                }
            }
            else
            {
                if(num>med)
                {
                    left.push(right.top());
                    right.pop();
                    right.push(num);
                }
                else
                {
                    left.push(num);
                }
                med=(left.top()+right.top())/2.0;
            }
        }
        
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */