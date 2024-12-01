class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        # 01.12.24 POTD
        st = set()

        for a in arr:
            if a*2 in st or a/2 in st:
                return True
            
            st.add(a)

        return False