#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    int roman_to_Integer(string s){
        unordered_map<char , int> mymap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}

        };
        int value = 0;
        for(int i = 0; i < s.size(); i ++ ){
            if (mymap[s[i]] < mymap[s[i + 1]]) {
                value -= mymap[s[i]];
            } else {
                value += mymap[s[i]];
            }
        }
        return value;
    }
};

int main(){
    Solution sol; 
    string s = "MCMXCIV"; // Example Roman numeral
    int result = sol.roman_to_Integer(s);
    cout << "The integer value of the Roman numeral " << s << " is: " << result << endl;   
    return 0;
}


