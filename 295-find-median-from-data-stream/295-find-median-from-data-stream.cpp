class MedianFinder {

    priority_queue<int> first;
    priority_queue<int> second;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        first.push(num);
        second.push(-first.top());
        first.pop();
        
        if(first.size() < second.size()){
            first.push(-second.top());
            second.pop();
        }
    }
    
    double findMedian() {
            
        double ans;
        
        if(first.size() > second.size()) ans = first.top();
        else ans = (first.top() - second.top())/2.0; 
            
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */