import os
import argparse

def getSubdirs(a_dir):
    return [name for name in os.listdir(a_dir) if os.path.isdir(os.path.join(a_dir, name))]


parser = argparse.ArgumentParser(description='')
parser.add_argument('-d','--dir', help='Directory of simulation', required=True)

args = vars(parser.parse_args())

mainDir = args["dir"]
subDirs = getSubdirs(mainDir)

doc = ""
for subDir in subDirs:
	with open(mainDir+"/"+subDir+"/output", 'r') as myfile:
		doc+=myfile.read()

with open("joinedResults", 'w') as myfile:
	myfile.write(doc)