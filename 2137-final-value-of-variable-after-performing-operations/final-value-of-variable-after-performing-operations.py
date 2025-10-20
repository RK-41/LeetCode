class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        # 20.10.25 POTD
        ans = 0
        for op in operations:
            if op[1] == '-':
                ans -= 1
            else:
                ans += 1
        
        return ans