#!/usr/bin/ksh

print 499
print 1 
for i in {1..497}
do
   echo "$((100000000000000-$i))"
done
echo "-1"
