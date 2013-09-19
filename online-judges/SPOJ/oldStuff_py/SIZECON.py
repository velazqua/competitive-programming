a=input
print sum([x for x in [a() for x in range(a())] if x>0])
