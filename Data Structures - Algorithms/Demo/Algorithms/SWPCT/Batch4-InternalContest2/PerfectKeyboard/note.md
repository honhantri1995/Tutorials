Polycarp wants to assemble his own keyboard. Layouts with multiple rows are too complicated for him — his keyboard will consist of only one row, where all 26 lowercase Latin letters will be arranged in some order.

Polycarp uses the same password `s` on all websites where he is registered (it is bad, but he doesn't care). He wants to assemble a keyboard that will allow to type this password very easily. He doesn't like to move his fingers while typing the password, so, for each pair of adjacent characters in `s`, they should be adjacent on the keyboard.
For example, if the password is `abacaba`, then the layout `cabdefghi...` is perfect, since characters a and `c` are adjacent on the keyboard, and `a` and `b` are adjacent on the keyboard. It is guaranteed that there are no two adjacent equal characters in `s`
so, for example, the password cannot be `password` (two characters `s` are adjacent).

Can you help Polycarp with choosing the perfect layout of the keyboard, if it is possible?

Input
The first line contains one integer T (1 <= T<= 1000) — the number of test cases
Then `T` lines follow, each containing one string `s` (1 <= T<= 200) representing the test case. `s` consists of lowercase Latin letters only. There are no two adjacent equal characters in `s`

Output
For each test case, do the following
- if it is impossible to assemble a perfect keyboard, print `NO` (in upper case, it matters in this problem);
- otherwise, print `YES` (in upper case), and then a string consisting of 2626 lowercase Latin letters — the perfect layout.
Each Latin letter should appear in this string exactly once. If there are multiple answers, printany of them.

Example:
Input:
```
5
ababa
codedoca
abcda
zxzytyz
abcdefghijklmnopqrstuvwxyza
```

Output:
```
YES
bacdefghijklmnopqrstuvwxyz
YES
edocabfghijklmnpqrstuvwxyz
NO
YES
xzytabcdefghijklmnopqrsuvw
NO
```