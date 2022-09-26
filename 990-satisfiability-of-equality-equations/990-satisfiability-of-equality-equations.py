class Solution(object):
    def equationsPossible(self, equations):
        """
        :type equations: List[str]
        :rtype: bool
        """
        stor = {}
        def find(x):
            if x not in stor:
                return x
            else:
                return find(stor[x])
        for i in equations:
            if i[1] == "=" :   
                a = i[0]
                b = i[-1]
                x = find(a)
                y = find(b)
                if(x != y):
                    stor[y] = x;
        for i in equations:
            if i[1] == "!" and find(i[0]) == find(i[-1]):
                return False
        return True
        # parent = {}
        # def find(x):
        #     if x not in parent:
        #         return x
        #     else:
        #         return find(parent[x])
        # for i in equations:
        #     if i[1]=="=":
        #         a = i[0]
        #         b = i[-1]
        #         x = find(a)
        #         y = find(b)
        #         if x!=y:
        #             parent[y] = x
        # for i in equations:
        #     if i[1]=="!" and find(i[0])==find(i[-1]):
        #         return False
        # return True