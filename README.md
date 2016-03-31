
# Assignnment 1 

* Name : James Muldoon - u5796521

* Program function:
Taking a picture in BMP format, the program will output the width and height of the image (in pixels). The user can also choose to apply a threshold (black and white) filter to the image. The user can also choose to apply a sepia filter to the input image. Options for the user include specifying the threshold to be used on the picture, the file to be run on, and the name of the output file. The user may also request a help message, which gives details on use of the program.

* How to compile/run:
FOR MAC / LINUX: 
Included with the program files is a makefile. This functions of this file include: 
	* $ make : compiles the program, creating an executable called "bmpedit"
	* $ make run : compiles the program (same function as $ make), and then runs the program using the default values (i.e. using cup.bmp, not applying any filters) 
	* $ make view : displays the end product of the program on an image (assuming the image has been saved to the default "out.bmp"). **Note: user will need to have program 'feh' installed for this command to work.
	* $ make clean : deletes program executable, and "out.bmp" file (if it exists).
Should the user choose to not use the make file, the program can be compiled using:
 	gcc -o bmpedit -std=c11 -Wall bmpedit.c filters.c

FOR WINDOWS: 
Since Windows uses a different compiler, the included makefile will not work.
To compile and create the executable, run the command $ cl bmpedit.c. This will create an executable called 'bmpedit.exe'. From here, all operating systems share the same advanced use commands (although user must at ".exe" onto the end of the executable name).

If the user wishes to run the program using inputs/outputs other than the defaults, they can use these commands: 
	* -t <threshold> : specify a threshold value between 0.0-1.0 (float). This will tell the program to output a black and white image, according to the given threshold. Default output file name is "out.bmp".
	* -s : applies a sepia filter to the input image
	* -o <output_file> : specify the name of the file for the image to be saved as.
	* -h : outputs a help message, specifying the function and operating commands for the program. Upon displaying this message, the program will automatically cancel execution.
	* <input_file> : if an argument is given without a '-X' argument preceding it, the program will assume it is being given the name of the input file. Note that if more than one file name is given, the program will cease execution and return an error message.


* Testing:
Tests were applied to the cup image given in the assignment spec, as well as on another bmp image found on the internet*.
	* BMP header parser: ran on each image without applying any filters, checked given values against file properties in the file system.
	* Threshold filter: ran filter on each image, visually inspected for errors. Compared result of running a 0.5 threshold on cup.bmp with the cupth.bmp file given in the assignment spec using $ vimdiff, found no differences.
	* Sepia filter: ran on each image and visually inspected results.
	* Stdin argument parser: 
		* verified that execution ceases when more than one input image is given
		* tried setting the output file name the same as the input. The original file was successfully overwritten, however I decided not to let the user do this, so added a guard and checked again.
		* verified that -t and -s can be used in any order
		* checked -h help message is easily readable
		* checked behaviour when the threshold filter is given a value outside of 0-1.0. Execution continues as normal, and image will just turn out all black or white.

* Extensions: 
	*Implemented another image filter, Sepia. This modifies the RGB values of each pixel according to a specific formula, resulting in an image effect that looks "warmer" than a black-and-white image (i.e. original colours are dulled, but still distinct). 

* Limitations
	* Only works for one header file type. An improvement over this would be altering the logic of the program according to the type of file it is being given. For example, if the first few bytes of the header indicated it was reading a BMP, read the data in the way it currently is. If the header indicated it was a JPEG, use a method of reading suited to that file format.  
	* Makefile only works for Linux/Mac machines. An improvement over this would be a makefile which determines which operating system it is currently being run in, and runs different commands accordingly (using methods such as the ones suggested here: http://stackoverflow.com/questions/4058840/makefile-that-distincts-between-windows-and-unix-like-systems) 
	* If the user wants to use both of the filters, they will be applied in a set order, regardless of the order the arguments are given in. An improvement over this would be putting flags for each filter in an array as they are read in from standard input, and then executing them in the order they are stored in the array.
	* The 'clean' command in the make file doesn't always delete the executable. An obvious improvement over this would be altering the method of removal to one that is more reliable.



*Credit for testing image: 
Tiger: https://learn.adafruit.com/2-8-tft-touch-shield/bitmaps