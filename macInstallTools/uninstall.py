import os

input = raw_input("Would you like to uninstall opencv?(n/y): ")
if(input == "y" or input == "yes"):
	os.system("brew uninstall opencv")
	#os.system("brew uninstall opencv3")
elif(input == "n" or input == "no"):
	print("Cancelled, nothing done.")

input2 = raw_input("Would you like to uinstall homebrew?(n/y): ")
if(input2 == "y" or input2 == "yes"):
	os.system("ruby -e \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/uninstall)\"")
elif(input2 == "n" or input2 == "no"):
	print("Cancelled, nothing done.")
