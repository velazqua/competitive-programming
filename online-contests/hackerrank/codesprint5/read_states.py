import csv
ans = ""
with open("states.txt", "r") as csvfile:
  for state in csvfile:
    ans += state.rstrip() + ","

print ans
