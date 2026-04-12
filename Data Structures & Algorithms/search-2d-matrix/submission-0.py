class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:  # Loop through rows
            if row[0] <= target <= row[-1]:  # Check if target is within this row's range
                l, r = 0, len(row) - 1  # Now `row` is defined

                while l <= r:  # Binary search inside the row
                    mid = (l + r) // 2
                    if row[mid] == target:
                        return True
                    elif row[mid] < target:
                        l = mid + 1
                    else:
                        r = mid - 1
        
        return False  # If not found, return False
