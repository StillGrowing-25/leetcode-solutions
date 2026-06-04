class Solution {
public:
    int check(int num){
        std::string x = to_string(num);
        int n= x.size();
        int waviness = 0;

        if(n<3)
        return 0;
        for(int i=1; i<n-1;i++){
            if((x[i]>x[i+1]&&x[i]>x[i-1])||(x[i]<x[i+1]&&x[i]<x[i-1]))
            waviness+=1;
        }
        return waviness;
        
    }
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for(int i = num1; i <= num2;i++){
            waviness += check(i);
        }
        return waviness;
    }
};
