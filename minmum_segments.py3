#considering length of segments is 2.
p = [int(x) for x in input().split()]
p.sort()
c=0 
segment=[]
while(c<len(p)):
	segment.append((p[c],p[c]+2))
	key=p[c]+2
	while(c<len(p) and p[c]<=key):
		c=c+1
print(segment)

