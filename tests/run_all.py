import os
import subprocess
import sys

def run_all():
	"""
	Run all tests. Find all files with '.o' extension.
	Run the corresponding executable.
	"""
	files = os.listdir()
	
	for f in files:
		if f.endswith('.o'): # assume executable exists if object file exists
			exe_str = "./{}".format(f[:-2])
			proc = subprocess.Popen(exe_str, shell=False)
			proc.wait()

if __name__ == '__main__':
	sys.exit(run_all())

