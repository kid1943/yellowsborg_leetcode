class Solution {
public:
    bool detectCapitalUse(string word) {
        int fir_let = word[0];
        int upperCout = 0;
        int lowrCout = 0;
        
        if(fir_let <=90 && fir_let >= 65){//大写
            for(int i = 1; i < word.length(); i++){
                int let = word[i];
                if(let <= 122 && let >= 97){//小写
                    upperCout++;
                }else{
                    lowrCout++;
                }
            }
            
           if(upperCout == 0 || lowrCout == 0)
             return true;
        }
        
        if(fir_let <= 122 && fir_let >= 97){//小写
            for(int i = 1; i < word.length(); i++){
                int let = word[i];
                if(let >= 65 && let <= 90 ){
                    return false;
                }
            }
            return true;
        }
        
        return false;
    }
    
/*  bool detectCapitalUse(string word) {
		int size=word.size(),count=0;
		if(size<=1)
			return true;
		for (int i = 1; i < size; i++){
			if(word[i]>='a'&&word[i]<='z')
				count+=1;
			else
				count+=2;
		}
		if(count==size-1)
			return true;
		else if(count==2*(size-1))
			return word[0]>='A'&&word[0]<='Z';
		else 
			return false;
    }    */
    
};