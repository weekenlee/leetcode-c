
int read4(char *buf) ;

class Solution {
    public:
        int read(char *buf, int n) {
            int i = 0;
            while (i < n) {
                if (i4_ < n4_) {
                    buf[i++] = buf4_[i4_++];
                }else if (n4_ = read4(buf4_)) {
                    i4_ = 0;
                }else {
                    break;
                }
            }
            return i;
        }

    private:
        char buf4_[4];
        int i4_ = 0, n4_ = 0;
};
