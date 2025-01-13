class Solution:
    def minimumLength(self, s: str) -> int:
        # 13.01.25 potd
        return sum(1 if x%2 else 2 for x in Counter(s).values())