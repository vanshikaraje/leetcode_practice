class Solution {
public:
bool isVowel(char c){
    c = tolower(c);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
    return true;
    }
return false;
}
    string reverseVowels(string s) {
        int left =0;
        int right = s.size()-1;
        while(left<right){
            if(!isVowel(s[left])){
                left++;
            }
            else if(!isVowel(s[right])){
                right--;
            }
            else{
                char temp = s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
        }
        return s;
    }
};