class Solution:
    def isPalindrome(self, a: int) -> bool:
        a = str(a)
        i = 0
        j = len(a)-1
        for i in range(len(a)//2):
            if a[i] != a[j]:
                return False
            j = j-1
        return True