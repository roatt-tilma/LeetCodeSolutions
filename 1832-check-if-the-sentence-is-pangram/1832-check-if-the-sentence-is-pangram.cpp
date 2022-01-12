class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alphabets(26, 0);
        if (sentence.size() < 26) return false;
        for (auto c: sentence){
            if (alphabets[c-97] == 0) alphabets[c-97] = -1;
        }
        if (*max_element(alphabets.begin(), alphabets.end()) == 0) return false;
        else return true;
    }
};