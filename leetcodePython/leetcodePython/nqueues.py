def solveNQueens(n):
    """
    :type n :int
    :rtype: List[List[str]]
    """
    def isqueens(depth, j):
        for i in range(depth):
            if board[i] == j or abs(depth - i) == abs(board[i] - j):
                return False
        return True

    def dfs(depth, row):
        if depth == n:
            ans.append(row)
            return
        for i in range(n):
            if isqueens(depth, i):
                board[depth] = i
                dfs(depth + 1, row + ['.' * i + 'Q' + '.' * (n - i - 1)])

    board = [-1 for i in range(n)]
    ans = []
    dfs(0, [])
    return ans


print solveNQueens(8)
