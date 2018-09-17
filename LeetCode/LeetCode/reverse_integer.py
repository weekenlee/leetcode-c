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

if __name__=="__main__":
    print(Solution().reverse(103))
    print(Solution().reverse2(103))
