ent = input().split()
l = int(ent[0])
r = int(ent[1])

#l = l - 1
#print(int(((r * (r + 1) / 2) - (l * (l + 1) / 2)) % 1000000007))
print(int(((l + r) * (r - l + 1)) / 2))