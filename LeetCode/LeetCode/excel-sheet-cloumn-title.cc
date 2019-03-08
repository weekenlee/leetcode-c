#include<string>
using namespace std;
class Solution {
    public:
        string convertToTitle(int n) {
            if ( n == 0 ) {
                return "";
            }

            return convertToTitle((n - 1)/ 26) +static_cast<char>((n-1)%26 + 'A');
        }
};
