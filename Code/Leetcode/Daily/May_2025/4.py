class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        return sum(f*(f-1)//2 for f in Counter(min(d0*10+d1, d1*10+d0) for d0, d1 in dominoes).values())
        