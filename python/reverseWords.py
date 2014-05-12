""" IMPORTANT: cant do in place reverse because strings are immutable
    IMPORTANT: slice notation is S[start: end] where the sequence is from start to end - 1
    IMPORTANT: python does not support tail recursion, so when a long string is entered it runs out of spaces
               and gives the "maximum recursion depth exceeded" error
"""
class Solution:
    # @param s, a string
    # @return a string
    """def reverseWord(self, word):
        if len(word) == 1: return wordclass python instance example
        else: return  self.reverseWord(word[1:]) + word[0]"""
    def reverseWord(self, word):
    	rword = word[::-1]
    	return rword

        
    def reverseWords(self, s):
        s = s.strip()
        if(len(s) <= 1):
            return s
            
        s = self.reverseWord(s)
        wordStart = 0
        reverseSentence = ''
        i = 0
        while i < len(s):
            if s[i] == ' ':
                #reverse the word
                word = s[wordStart : i] 
                reverseSentence += self.reverseWord(word)
                reverseSentence += ' '
                
                #find the start of the next word
                #take care of the extra spaces in between the words
                while i <= len(s) and s[i] == ' ':
                    i+=1
                wordStart = i
            i+=1
        
        #reverse the last word
        reverseSentence += self.reverseWord(s[wordStart:])
        return reverseSentence

def main(): 
	sentence = raw_input("Get a sentence: ")
	soln = Solution()
	print "test 1 %r" %soln.reverseWords(str(sentence))

if __name__ == '__main__':
	main()
