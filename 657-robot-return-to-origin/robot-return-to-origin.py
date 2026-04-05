class Solution:
    def judgeCircle(self, moves: str) -> bool:
        # 05.04.26 POTD
        i, j = 0, 0

        for m in moves:
            match m:
                case 'U':
                    i -= 1
                case 'R':
                    j += 1
                case 'D':
                    i += 1
                case 'L':
                    j -= 1
        
        return [i,j] == [0,0]
