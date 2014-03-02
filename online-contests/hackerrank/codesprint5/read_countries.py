import csv
ans = ""
with open("countries.csv", "r") as csvfile:
  fin = csv.reader(csvfile, delimiter= ',', quotechar='"')
  for line in fin:
    for country in line:
      ans += '"' + country[3:] + '"' + ","

print ans
