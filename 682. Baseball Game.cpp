#include <string>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        deque<int> records;
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == "C"){
                records.pop_back();
            }else if(ops[i] == "D"){
                records.push_back(2*records[records.size()-1]);
            }else if(ops[i] == "+"){
                records.push_back(records[records.size()-1]+records[records.size()-2]);
            }else{
                records.push_back(stoi(ops[i]));
            }
        }
        for(const int & i : records){
            sum+=i;
        }
        return sum;
    }
};