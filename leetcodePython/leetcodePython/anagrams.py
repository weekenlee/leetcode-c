def groupAnagrams(strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d,ans= {},[]
        for i in strs:
            sortstr = ''.join(sorted(i))
            if sortstr in d:
                d[sortstr] += [i]
            else:
                d[sortstr] = [i]
        #print(d)
        for i in d:
            tmp = d[i];tmp.sort()
            ans += [tmp]
        return ans

print groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])