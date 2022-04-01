class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = s.size()-1;
        char tmp;
        for(int i = 0; i<s.size()/2; ++i){
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            --j;
        }
    }
};