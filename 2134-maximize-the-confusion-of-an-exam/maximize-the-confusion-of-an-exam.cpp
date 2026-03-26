class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int left = 0;
        int maxLen = 0;
        int countT = 0, countF = 0;
        
        for(int right = 0; right < answerKey.size(); right++){
            
            if(answerKey[right] == 'T') countT++;
            else countF++;
            
            while(min(countT, countF) > k){
                
                if(answerKey[left] == 'T') countT--;
                else countF--;
                
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};