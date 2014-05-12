"""
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
"""


class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stck = []
        op = set(['*','+', '-','/'])
        try:
            for t in tokens:
                if t not in op:
                    stck.append(int(t))
                else:
                    b = stck.pop()
                    a = stck.pop()
                    if t == '+':
                        stck.append(a + b)
                    elif t == '*':
                        stck.append(a * b)
                    elif t == '/':
                        tmp = float(a)/float(b)
                        stck.append(int(tmp))
                    elif t == '-':
                        stck.append(a - b)
        except ValueError:
            print "Invalid token"
        return stck[-1]