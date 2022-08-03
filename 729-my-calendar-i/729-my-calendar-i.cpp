class MyCalendar {
    vector<pair<int,int>> books;
    
    public:

    bool book(int start, int end) {
        
        for(auto i: books){
            if(max(i.first, start) < min(i.second, end)) return false;
        }
        
        books.push_back({start,end});
        return true;
    }

};