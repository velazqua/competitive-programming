def lucky (n):
    nums = ['2','3','5','7']
    if n <= 4:
        return nums[n-1]
    else:
        if (n/4) >=4:
            t = n%4
        else:
            t= n%4-1
        return lucky(n/4)+nums[t]


for i in xrange(1,100):
    print i, lucky(i)
