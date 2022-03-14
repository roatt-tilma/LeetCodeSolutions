class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string temp = "";
        int one = 0;
        int two = 0;
        int three = 0;
        int count = 0;
        for (auto i:path){
            if(i == '/'){
                if (temp != "" && count != temp.size()){
                    stack.push_back(temp);
                    temp = "";
                    count = 0;
                    one = 0;
                    two = 0;
                    three = 0;
                }
                if (one) one = 0;
                if (two){
                    two = 0;
                    if(stack.size() != 0) stack.pop_back();
                }
                if (three){
                    three = 0;
                    stack.push_back("...");
                }
                temp = "";
                count = 0;
            }
            else{
                temp += i;
            }
            if (i == '.'){
                if (!one && !two && !three) one = 1;
                else if (one && !two && !three){
                    one = 0;
                    two = 1;
                }
                else if (!one && two && !three){
                    two = 0;
                    three = 1;
                }
                count++;
            }
        }
        if (temp != "" && count != temp.size()){
            stack.push_back(temp);
            temp = "";
            count = 0;
            one = 0;
            two = 0;
            three = 0;
        }
        if (one) one = 0;
        if (two){
            two = 0;
            if(stack.size() != 0) stack.pop_back();
        }
        if (three){
            three = 0;
            stack.push_back("...");
        }
        temp = "";
        for (auto i: stack){
            temp += "/";
            temp += i;
        }
        if(stack.size() == 0) temp += "/";
        return temp;
    }
};