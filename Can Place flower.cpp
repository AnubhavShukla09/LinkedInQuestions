class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0){
            return true;
        }
        int i=0;
        int ans=0;
        int sz = flowerbed.size();
        while(i<sz-1){
            if(flowerbed[i]==1){
                i+=2;
            }
            if(flowerbed[i]==0){
                if(flowerbed[i+1]==0){
                    n--;
                    i+=2;
                }else{
                    i+=1;
                }
            }
            if(n==0){
                return true;
            }
        }
        return false;
    }
};
