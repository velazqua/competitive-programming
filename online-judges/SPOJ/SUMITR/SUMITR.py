for i in range(input()):
  l=[]
  for j in range(input()):
    x=[int(k) for k in raw_input().split()]
    l.append(x)
  for j in range(len(l)-1,0,-1):
    for k in range(j):
      l[j-1][k]+=max(l[j][k],l[j][k+1])
  print l[0][0]
