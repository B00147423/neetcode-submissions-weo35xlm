class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        row = len(matrix)
        col = len(matrix[0])

        left = 0
        right = row * col - 1




        while left <= right:
            mid = left+ (right - left) // 2
            r = mid // col
            c = mid % col
            if matrix[r][c] < target:
                left = mid+1
            elif matrix[r][c] > target:
                right = mid-1
            else:
                return  True
        return False

