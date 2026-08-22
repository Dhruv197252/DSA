class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        long add = 0;
        long product=1;
        while(n>0){
            add += (n%10);
            product = product* (n%10);
            n=n/10;
        }
        int sum = add + product;
        if(m%sum==0){
            return true;
        }
        return false;
    }
};