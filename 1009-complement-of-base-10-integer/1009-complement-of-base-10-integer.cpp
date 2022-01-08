class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int power = floor(log2(n)) + 1;
        int toXORWith = pow(2, power) - 1;
        int answer = n^toXORWith;
        return answer;
    }
};