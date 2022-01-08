class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        return (n^(int)(pow(2, (floor(log2(n)) + 1)) - 1));
    }
};