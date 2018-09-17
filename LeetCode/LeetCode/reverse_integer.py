class Solution(object):
    def reverse(self, x):
        if x < 0:
            return -self.reverse(-x)
        result = 0
        while x:
            result = result * 10 + x % 10
            x //= 10
        return result if result <= 0x7ffffff else 0

    def reverse2(self,x):
        if x < 0:
            x = int(str(x)[::-1][-1] + str(x)[::-1][-1])
        else:
            x = int(str(x)[::-1])
        x = 0 if abs(x) > 0x7fffffff else x
        return x

    def reverse3(self,x):
        s=cmp(x,0)
        r=int(repr(s*x)[::-1])
        return s*r*(r<2**31)

if __name__=="__main__":
    print(Solution().reverse(103))
    print(Solution().reverse2(103))
    print(Solution().reverse3(103))
