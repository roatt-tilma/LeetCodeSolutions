class Solution {
public:
    
    bool minIndexFunc(vector<int>& gas, vector<int>& cost, int min_index, int n){
        int tank = 0;
        for (int i = min_index; i < min_index + n; i++){
            tank = tank+gas[i%n]-cost[i%n];
            if (tank < 0) return false;
            if (tank == 0 && ((i+1)%n != min_index)) return false;
        }
        
        return true;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> min_index;
        int min_cost = *min_element(cost.begin(), cost.end());
        int max_gas = *max_element(gas.begin(), gas.end());
        
        for (int i = 0; i < n; i++){
            if (cost[i] == min_cost || gas[i] == max_gas) min_index.push_back(i);
        }
        
        bool check = false;
        for (auto i:min_index){
            check = minIndexFunc(gas, cost, i, n); 
            if(check) return i;
        }
        
        return -1;        
    }
};