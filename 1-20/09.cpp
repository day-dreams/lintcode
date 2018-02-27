class Solution:
    """
    @param n: An integer
    @return: A list of strings.
    """
    def fizzBuzz(self, n):
#write your code here

        if n==0:
            return []


        rv=[]
        
        
        for i in range(1,n+1):
            
            if i%3==0 and i%5==0:
                rv.append("fizz buzz")
            elif i%3==0:
                rv.append("fizz")
            elif i%5==0:
                rv.append("buzz")
            else:
                rv.append(str(i))
                
        return rv
