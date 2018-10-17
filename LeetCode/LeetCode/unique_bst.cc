#include<climits>
#include<iostream>

class Soluiton {
    public:
        int numTrees(int n) {
            long long res = 1;
            for ( int i=1; i <= n ; ++i ) {
                res = res*2*(2*i-1)/(i+1);
            }
            return res > INT_MAX ? 0 : res;
        }
};

int main(void) {
    std::cout<<Soluiton().numTrees(3)<<std::endl;
}
