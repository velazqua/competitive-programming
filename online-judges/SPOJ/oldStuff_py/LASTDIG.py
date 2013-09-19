nums = {'0':[0,0,0,0], '1':[1,1,1,1], '2':[6,2,4,8], '3':[1,3,9,7], '4':[6,4,6,4], '5':[5,5,5,5],\
	'6':[6,6,6,6], '7':[1,7,9,3], '8':[6,8,4,2],'9':[1,9,1,9]}

def lastDigitY (a,b):
	if b==0:
		return 1
	elif a=='0':
		return 0
	else:	
		return nums[(str(a)[-1])][b%4]
	
T = int(raw_input())
for i in xrange(0,T):
	numbers=raw_input()
	[a,b]=numbers.split(' ')
	print lastDigitY(a,int(b))
