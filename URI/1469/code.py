from sys import stdin
from collections import defaultdict

N, M, I = map(int, stdin.readline().strip().split())
K = [None] + list(map(int, stdin.readline().strip().split()))
pos = [None] + [p+1 for p in range(N)]
who = list(pos)

direct_managers = defaultdict(list)
for m in range(M):
	X, Y = map(int, stdin.readline().strip().split())
	# X gerencia Y -> ir de Y pra X
	direct_managers[Y].append(X)


def youngest_from(posE, E):
	global direct_managers, K
	youngest_age = float('+inf')
	
	visited = set()
	to_visit = set([posE])
	while to_visit:
		u = to_visit.pop()
		for v in direct_managers[u]:
			if v in visited:
				continue

			to_visit.add(v)
			visited.add(v)

		if who[u] == E:
			continue
		
		youngest_age = min(K[who[u]], youngest_age)
	
	if youngest_age == float('+inf'):
		return '*'
	else:
		return youngest_age

for i in range(I):
	instruction = stdin.readline().strip()
	if instruction[0] == 'T':
		_, A, B = instruction.split()
		A, B = int(A), int(B)
		who[pos[A]], who[pos[B]] = who[pos[B]], who[pos[A]]
		pos[A], pos[B] = pos[B], pos[A]
	elif instruction[0] == 'P':
		_, E = instruction.split()
		E = int(E)
		print youngest_from(pos[E], E)
