#include<limits>
using namespace std;
int read4(char *buf) ;

class Solution {
    public:
        int read(char *buf, int n) {
            int read_bytes = 0;
            char buffer[4];
            for(int i = 0; i <= n/4; ++i) {
                if(int size = read4(buffer)) {
                    size = std::min(size, n - read_bytes);
                    for(int j = 0; j < size; ++j) {
                        buf[read_bytes++] = buffer[j];
                    }
                }else {
                    break;
                }
            }
            return read_bytes;
        }
};
