import sys
import math

# 
# Prints out a new version of a text file justified to the given line length justify_length
#
def justify(file_name, justify_length):

	file = open(file_name, 'r')
	# iterate over lines
	for line in file:
		words = line.split()
		
		out_words = []
		num_chars = 0
		
		# iterate over words, writing new lines when necessary
		for k in xrange(len(words)):
			word = words[k]
			if (len(word) > justify_length):
				print("")
				exit("ERROR: Remaining text contains a word longer than the justify length")
			if k == (len(words) - 1):
				chars_to_add = len(word)
			else:
				chars_to_add = len(word) + 1
			# if adding word does not exceed the size of the line
			if (chars_to_add + num_chars <= justify_length):
				# add word to out_words
				out_words.append(words[k])
				num_chars += chars_to_add
				
			else:
				num_rem_spaces = justify_length - num_chars + len(out_words)
			 	# write new line
				for i in xrange(len(out_words)):
					out_word = out_words[i]
					
					# write word					
					for char in out_word:
						sys.stdout.write(char)
					# write spaces
					num_rem_words = len(out_words) - i - 1
					if (num_rem_words > 0):
						num_bw_spaces = int(math.ceil(1.0 * num_rem_spaces / num_rem_words))	
						for i in xrange(num_bw_spaces):
							sys.stdout.write(' ')	
						num_rem_spaces -= num_bw_spaces	
				# create a fresh new line
				print('')
				
				if k == (len(words) - 1):
					num_chars = len(word)
				else:
					num_chars = len(word) + 1
				out_words = [words[k]]

	 	# write new line
		num_rem_spaces = justify_length - num_chars + (len(out_words) - 1)
		for i in xrange(len(out_words)):
			out_word = out_words[i]
			# write word					
			for char in out_word:
				sys.stdout.write(char)
			# write spaces
			num_rem_words = len(out_words) - i - 1
			if (num_rem_words > 0):
				num_bw_spaces = int(math.ceil(1.0 * num_rem_spaces / num_rem_words))	
				for i in xrange(num_bw_spaces):
					sys.stdout.write(' ')
				num_rem_spaces -= num_bw_spaces		
		print('')

	
			

		



# Program justifies text contents of a given file
# This is the actual code that gets run when the
# program is run. 
#
# DO NOT EDIT BELOW HERE.
if __name__ == "__main__":

    file_name = ''
    length = -1

    # Parse command line arguments
    try:
        for i in range(len(sys.argv)):
            if sys.argv[i] == '-f':
                file_name = sys.argv[i+1]
            elif sys.argv[i] == '-l':
                length = int(sys.argv[i+1])
    except:
        exit('Input error. Example input: justifytext -f mytextfile -l 80')

    if file_name == '' or length < 1:
        exit('Input error. Example input: justifytext -f mytextfile -l 80')
        
    justify(file_name, length)







