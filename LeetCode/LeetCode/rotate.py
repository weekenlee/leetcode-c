class Solution:
    def rotate(self, matrix):
        return [list(reversed(x)) for x in zip(*matrix)]


if __name__ == "__main__":
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(Solution().rotate(matrix))
