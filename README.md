
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

FOR WINDOWS: 
Since Windows uses a different compiler, the included makefile will not work.
To compile and create the executable, run the command $ cl bmpedit.c. This will create an executable called 'bmpedit.exe'. From here, all operating systems share the same advanced use commands (although user must at ".exe" onto the end of the executable name).

If the user wishes to run the program using inputs/outputs other than the defaults, they can use these commands: 
	* -t <threshold> : specify a threshold value between 0-1 (float). This will tell the program to output a black and white image, according to the given threshold. Default output file name is "out.bmp".
	* -s : applies a sepia filter to the input image
	* -o <output_file> : specify the name of the file for the image to be saved as.
	* -h : outputs a help message, specifying the function and operating commands for the program. Upon displaying this message, the program will automatically cancel execution.
	* <input_file> : if an argument is given without a '-X' argument preceding it, the program will assume it is being given the name of the input file. Note that if more than one file name is given, the program will cease execution and return an error message.


* Testing:
DO SOME TESTING

* Extensions: 
DO SOME EXTENSIONS

* Limitations
Only works for one header file type.
Makefile only works for Linux/Mac machines.
Regardless of how many filters the user wishes to apply, they are always applied in a predefined order, rather than the order the user gives the arguments.