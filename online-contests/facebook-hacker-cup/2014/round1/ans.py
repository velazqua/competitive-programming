def nextLetter (jump, N, L, size, currentSum):
  if (N <= currSum):
    return ' '
  else:
    return L[(N-1-currSum)/jump % size]

T = input()
for i in xrange(T):
  line = raw_input()
  L, N = line.split()
  N = int(N)
  currPower = 1
  currSum = 0
  size = len(L)
  ans = ""
  while True:
    nextC = nextLetter(currPower, N, L, size, currSum)
    if (nextC != ' '):
      ans += nextC
    else:
      break
    currPower *= size
    currSum += currPower
  # reverse
  print "Case #" + str(i+1) + " " + ans[::-1]
