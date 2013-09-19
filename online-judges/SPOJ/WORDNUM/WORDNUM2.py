for i in range(input()):
	w=raw_input();a=w.split();r=t=q=0;h=1
	if "thousand" in a:q=1
	for j in a:
		if j[0]=='h':
			r*=100
			if h:t+=r
			continue
		if j[-2:]=="nd":r*=1000;t=r;r=h=0;continue
		l=len(j);d={5:{'v':7,'g':8,'r':40,'f':50,'x':60},3:{'e':1,'o':2,'x':6,'n':10},4:{'u':4,'v':5,'n':9,'r':0},7:{'f':15,'x':16,'v':17},8:{'i':13,'u':14,'g':18,'n':19}}
		if l in [3,5,4,7,8]:
			if j[-2:]=="ee":r+=3
			else:r+=d[l][j[2]]
		if l==6:d={'v':11,'l':12,'n':20,'r':30,'h':80,'e':90};r+=d[j[3]]
		if l==9:r+=17 
	print t+r if q else r
