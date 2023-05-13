import os

#For mac users - install brew and use it to update required dependencies

def user_input(package, script):
	answer = raw_input("Install " + package + "?(y/n): ")

	if(answer == "y" or answer == "yes"):
		os.system(script)
	elif(answer == "n"):
		print("CANCELLED, terminating.")
	else:
		print("Please provide either yes or no.\n")

xcode_script = "xcode-select --install"

homebrew_script = "/usr/bin/ruby -e \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)\""

opencv_script = "brew install opencv"

brew_update = "brew update && brew upgrade && brew cleanup"

brew_pkg = "brew install pkg-config"

brew_imagemagick = "brew install imagemagick"

brew_ghostscript = "brew install ghostscript"

brew_ncurses = "brew install ncurses"

user_input("xcode-command-tools", xcode_script)
user_input("Homebrew", homebrew_script)
user_input("Opencv", opencv_script)
user_input("pkg", brew_pkg)
user_input("Image Magick", brew_imagemagick)
user_input("Ghost Script", brew_ghostscript)
user_input("Ncurses", brew_ncurses)
user_input("update?(optional)", brew_update)

print("Process complete, done.")
