class Solution {
public:
    int func(int n){
        int product = 1;
        while(n>0){
            int digit = n%10;
            product*=digit;
            n/=10; 
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int pro = func(n);
            if(pro%t==0){
                return n;
            }
            n++;
        }   
    }
};