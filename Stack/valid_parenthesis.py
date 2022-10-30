class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        n = len(s)
        if n == 1:
            return False
        
        for i in range(n):
            if s[i] == "[" or s[i] == "{" or s[i] == "(":
                stack.append(s[i])
            else:
                if stack == [] or stack[-1] == "[" and s[i] != "]" or stack[-1] == "{" and s[i] != "}" or stack[-1] == "(" and s[i] != ")":
                    return False
                else:
                    stack.pop()
        
        print(stack)
        if stack:
            return False
        return True
