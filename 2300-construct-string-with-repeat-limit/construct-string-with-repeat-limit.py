class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        # 17.12.24 potd
        ans = []
        freq = 1
        ptr = 0

        chars = sorted(s, reverse=True)
        for i in range(len(chars)):
            if ans and ans[-1] == chars[i]:
                if freq < repeatLimit:
                    ans.append(chars[i])
                    freq += 1
                else:
                    ptr = max(ptr, i+1)
                    while ptr < len(chars) and chars[ptr] == chars[i]:
                        ptr += 1
                    
                    if ptr < len(chars):
                        ans.append(chars[ptr])
                        chars[i], chars[ptr] = chars[ptr], chars[i]
                        freq = 1
                    else:
                        break

            else:
                ans.append(chars[i])
                freq = 1
            
        return ''.join(ans)