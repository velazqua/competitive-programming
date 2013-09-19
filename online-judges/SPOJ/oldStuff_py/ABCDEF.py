S=[1,-1]
counter=0
for a in S:
	for b in S:
		for c in S:
			for d in S:
				for e in S:
					for f in S:
						if (a*b+c == (f+e)*d):
							print str(a)+"*"+str(b)+"+"+str(c)+"= ("+str(f)+"+"+str(e)+") *"+str(d) 
							counter+=1
							
print counter
