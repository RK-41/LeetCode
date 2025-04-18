class Solution:
    def countAndSay(self, n: int) -> str:
        # 18.04.25 POTD
        if n == 1:  return '1'

        ans = '1'

        for _ in range(2, n+1):
            an = len(ans)
            curr = ''
            cnt = 1

            for i in range(1, an):
                if ans[i-1] == ans[i]:
                    cnt += 1
                else:
                    curr += (str(cnt) + ans[i-1])
                    cnt = 1

            curr += (str(cnt) + ans[an-1])
            ans = curr
            print(ans, curr)

        return ans