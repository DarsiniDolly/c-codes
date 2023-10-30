import sys
import struct
import math
import shutil

Filename = b"workout.bin \n"
string = b"aaaaaaaaaaaaaaaaaaaaaaaa\n"
data = b"I AM JUST TRYING WHETHER I CAN  CREATE A FILE OR NOT\n"
x = len(string)
y = len(data)

print ("Number of arguments: ", len(sys.argv), "arguments.")


file = open("workout.bin","wb")

file.write(Filename)
file.write(string)
file.write(data)


print("Filename: ",Filename)
print("Filesize: ",file.tell())
print("size: ",x)
print("data size: ",y)
print("Filecontents: ",string+data)

file.close()

Filename = b"workout1.bin \n"
string = b"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb \n"
w = len(string)

file1 = open("workout1.bin","wb")

file1.write(Filename)
file1.write(string)


print("Filename: ",Filename)
print("Filesize: ",file1.tell())
print("size: ",w)
print("Filecontents: ",string)

file1.close()


def merge_files_with_shutil(file1, file2, merged_file):
	with open(merged_file, 'wb') as outfile:
		for filename in [file1, file2]:
			with open(filename, 'rb') as infile:
				shutil.copyfileobj(infile, outfile)

# Usage:
file1 = 'workout.bin'
file2 = 'workout1.bin'
merged_file = 'merged_file.bin'
merge_files_with_shutil(file1, file2, merged_file)



