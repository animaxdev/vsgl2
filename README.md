# vsgl2
Very Simple Graphic Library 2

This library is built upon the very well known SDL2 library: the goal is to introduce beginners into graphical programming, giving a set of functions in pure C (more or less).

The library is cross-platform, so it could be used in Windows, Linux and MacOS.

# Installation
This section is about how to install SDL and VSGL2 on your platform of choice and link your programs against it.
## Installing SDL2 library
The following subsections are referred to Windows, Linux and MacOS installation process, using CodeBlocks as IDE, it is absolutely possible to use other IDEs.

### Windows
First of all it is necessary to install [CodeBlocks](http://www.codeblocks.org), which include the Mingw32 suite of tools (compiler, linker, etc.) to create C/C++ programs. Then there are three possibilities to install SDL2 (you can go [here](http://www.imparando.net/sito/introduzione_alla_programmazione_in_C/strumenti_di_sviluppo/installare%20la%20libreria%20SDL2.htm) to read the same instructions in Italian):

 - **First one** (the easiest): I have already created a big compressed file with all the stuff needed inside (compiler, Codeblocks IDE, libraries). [Download the file](http://www.imparando.net/software/codeblocks.zip), then uncompressed it on your PC. Download also [DLL files](http://www.imparando.net/software/dll.zip) and copy them inside Windows/SysWOW64 subfolder, that's it.

 - **Second one** (easy): after Codeblocks installation, download [this package](http://www.imparando.net/software/SDL_package.zip) created by me: there are three folders inside
   - **include**: it contains header files (.h), inside *SDL2* subfolder. This subfolder has to be copied inside *include* folder within Codeblocks/Mingw directory
   - **lib**: it contains the library object files, they have to be copied inside Codeblocks/Mingw/lib directory
   - **bin**: it contains the DLLs needed to execute the VSGL2 programs on the host PC. They could be copied in the same folder of each executable and it is necessary if you plan to distribute your programs, but in the development phase it is better to copy them inside Windows/SysWOW64 subfolder: in this way they will be visible system-wide. There are also other DLLs other than SDL2 DLLs: they are necessary to execute basic tasks, e.g. to load JPEG images.

- **Third one** (less easy): after installing Codeblocks, it is possible to download every single library package (SDL2, SDL2_image, SDL2_mixer, SDL2_net, SDL2_ttf), here the links:
  - **SDL2**: main library, download from [this page](https://www.libsdl.org/download-2.0.php), Development libraries, file tar.gz for Mingw.
  - **SDL2_mixer**: sound library, download from [this page](https://www.libsdl.org/projects/SDL_mixer/), Development libraries, file tar.gz for Mingw.
  - **SDL2_image**: image loading library, download from [this page](https://www.libsdl.org/projects/SDL_image/), Development libraries, file tar.gz for Mingw.
  - **SDL2_net**: network library, download from [this page](https://www.libsdl.org/projects/SDL_net/), Development libraries, file tar.gz for Mingw.
  - **SDL_ttf**: TrueType font rendering library, download from [this page](https://www.libsdl.org/projects/SDL_ttf/), Development libraries, file tar.gz for Mingw.

 After that, the procedure is the same as in the second possibility, it has to be replicated for each package, which includes i686-w64-mingw32 folder with **include**, **lib** and **bin** folders inside.  

### Linux

Installing the library with Linux is very simple, these instructions have been tested on Ubuntu 14.04, but they should work with any Debian-like distribution.
First of all, the GNU compiler collection has to be installed, if not already there:

```bash
sudo apt-get install build-essential
```

Then Codeblocks is needed

```bash
sudo apt-get install codeblocks
```

Finally, all SDL2 libraries have to be installed

```bash
sudo apt-get install libsdl2-dev libsdl2-net-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
```
and that's it.

### MacOS

To install vsgl2 on MacOS devices: 

1. Install CodeBlocks [here](http://www.codeblocks.org/downloads) if you want, but I don't recommend it because MacOS version is very unstable. Instead of using CodeBlocks you can compile using g++ in the terminal (see below) and code using a text editor like SublimeText, Atom, Vim (only for pros), Emacs...  

2. If you haven't got it, install [homebrew](https://brew.sh/index_it.html): 
 	
	```
	/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
	```	

3. Install sdl & sdl2: 

	```
	brew install sdl2 sdl2_net sdl2_image sdl2_mixer sdl2_ttf
	sudo chown root:wheel /usr/local/bin/brew
	brew link sdl2 sdl2_net sdl2_image sdl2_mixer sdl2_ttf
	```

## Installing VSGL2 library
The library is platform independent, so the steps are the same in all the platforms.
It can be done in two different ways, depending if you want to use ```git``` or not.
- Without using ```git```: download the zip file at the beginning of this page (```Clone or download button```), extract it wherever you want, it contains all the projects inside lessons, from which you can start.
- Using ```git```: in this case you have to install ```git``` first, then write the following command:
```bash
git clone https://github.com/alessandro-bugatti/vsgl2.git
```  
The advantage in using ```git``` is that it is possible to stay updated with the last releases running the following command:
```bash
git pull https://github.com/alessandro-bugatti/vsgl2.git
```

There is a **.cbp** file inside each ```lesson```, it is a good place to start using the library with Codeblocks.

If you prefer compiling in the terminal using g++:

```
g++ your/file/path vsgl2.cpp/file/path -lsdl2 -lsdl2_net -lsdl2_image -lsdl2_mixer -lsdl2_ttf  -std=c++11 -stdlib=libc++
```

And run what you've just compiled: 

```
./a.out
```

## Design
Main features:
- Simple, every functions has to be clear and easy to use

- Only functions, not classes or objects (from the user prospective, the library code uses C++)
- Not a general library to do all the things, but only to do certain things in a easy manner. If you want to have full control of all the aspects, maybe it could be better to use SDL instead.

## API documentation
The documentation can be generated using Doxygen with the Doxyfile stored in the main project folder, otherwise there is a copy online [here on GitHub pages](https://alessandro-bugatti.github.io/vsgl2/)

## Lessons
Very often programming libraries have a not so good documentation, sometimes because it is too difficult to follow, sometimes because it lacks in explaining fundamental parts.

During the development of this library the idea is to add "lessons" to explain how to use the functionalities of this library through examples. [Go to the lessons](lessons/)

## Contributing
Any help will be appreciated, some examples:
- Adding new code to the library
- Adding lessons to clarify some aspects or only to give inspiration
- I'm not a native speaker (I think it is clear), so corrections will be welcomed.
- Anything useful.
