class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        # 12.12.24 POTD
        heap = []
        heapify(heap)

        for g in gifts:
            heappush(heap, -1 * g)

        while k>0:
            mx = -1 * heappop(heap)
            heappush(heap, -1 * floor(sqrt(mx)))
            k -= 1

        return -1 * sum(heap)
