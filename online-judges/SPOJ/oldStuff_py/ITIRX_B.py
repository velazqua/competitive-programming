def lucky (n):
    nums = ['2','3','5','7']
    if n <= 4:
        return nums[n-1]
    else:
        if (n%4) == 0:
            t = 3
            return lucky(n/4-1) + nums[t]
        else:
            t= n%4-1
            return lucky(n/4)+nums[t]

##
##digits=[2,3,5,7]
##alex=['2','3','5','7']
##for i in seq:
##    for j in seq:
##        num = str(i)+str(j)
##        alex.append(num)
##
##for i in seq:
##    for j in seq:
##        for k in seq:
##            num = (str(i)+str(j)+str(k))
##            alex.append(num)
##
##for i in seq:
##    for j in seq:
##        for k in seq:
##            for l in seq:
##                num = (str(i)+str(j)+str(k)+str(l))
##                alex.append(num)

for i in xrange(input()):
    print lucky(input())
