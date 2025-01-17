import io

def intin(): return int(input())
def mapin(): return list(map(int, input().split()))

t = intin();
for _ in range(t):
	n = intin()
	arr = mapin()
	for a in arr:
		print(a)