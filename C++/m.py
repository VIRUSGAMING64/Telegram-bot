for _ in range(int(input())):
	s = input()
	n = len(s)
	ans = n
	for x in range(26):
		c = chr(x + ord('a'))
		i = 0
		cur = 0
		while i < n:
			j = i
			while j < n and (s[j] == c) == (s[i] == c):
				j += 1
			if s[i] != c:
				cur = max(cur, j - i)
			i = j
		if cur == 0:
			ans = 0
			break
		pw = 0
		while (1 << pw) <= cur:
			pw += 1
		ans = min(ans, pw)
	print(ans)