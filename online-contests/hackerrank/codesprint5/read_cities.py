import csv
ans = ""
with open("cities.csv", "r") as csvfile:
  for country in csvfile:
    ans += '"' + country.rstrip() + '"' + ","

print ans
