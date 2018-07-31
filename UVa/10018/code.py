from sys import stdin

def is_palindrome(n):
	n = str(n)
	for i in range(len(n)//2):
		if n[i] != n[len(n)-i-1]:
			return False
	return True

def reverse_and_add(n):
	n = str(n)
	m = n[::-1]
	return int(n) + int(m)

_ = stdin.readline()
for line in stdin:
	n = int(line)
	c = 0
	while not is_palindrome(n):
		n = reverse_and_add(n)
		c += 1
	print(c, n)