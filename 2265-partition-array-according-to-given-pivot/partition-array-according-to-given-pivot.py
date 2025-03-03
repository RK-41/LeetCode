class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        # 03.03.25 POTD
        ans = []

        for x in nums:
            if x < pivot:
                ans.append(x)

        for x in nums:
            if x == pivot:
                ans.append(x)

        for x in nums:
            if x > pivot:
                ans.append(x)

        return ans