# CSC3022F - assignment 1 : Tag Enumeration

# Files

## [tags.h](tags.h)

hearder file defining attributes used by the application

## [tags.cpp](tags.cpp)

Implements the attributes defined by the [header](tags.h) file

## [driver.cpp](driver.cpp)

Main file to run the application

## [gitlogs.txt](gitlogs.txt)

contains logs of all git commits used for developing this application

### Build

```unix
$ make
```
### clean
Removes object files, executables and output files
```
$ make clean
```
### clean data
Removes all input files
```unix
$ make clean-data
```
### run
```unix
$ ./driver
```

## User input

The application accepts user input for different commands. The application provides details for each command.

### input commands
"r: Read and process tag file"<br> 
"p: Print all tags"<br>
"d: Dump/write tags to a data file (tag.txt)"<br>
"l: list/print tag data for a given tag"<br>
"q: quit"