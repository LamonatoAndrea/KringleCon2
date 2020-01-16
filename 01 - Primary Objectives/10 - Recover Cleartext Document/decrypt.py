import os
import subprocess

i = 0
for line in open("keys.txt", "r").readlines():
	line = line.replace("\n", "").replace("\r", "")
	print ("Line [{}] [{}]".format(i, line))
	subprocess.call ("elfscrow.exe --insecure --decrypt --id={0} ElfUResearchLabsSuperSledOMaticQuickStartGuideV1.2.pdf.enc decrypted\\{0}.pdf >> dec_log.txt 2>&1 ".format(line), shell=True)
	i += 1