class Solution {
public:
    bool Check_sub_problem(int start, int end, string s){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }else{
                ++start;
                --end;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
       int start = 0, end = s.length()-1, cnt = 0;
        while(start <= end){
            if(s[start] != s[end]){
                return Check_sub_problem(start+1, end, s) || Check_sub_problem(start, end-1, s);
            }else{
                ++start;
                --end;
            }
        }
        return true;
    }
};