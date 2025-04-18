<h1 align=center>
	<b>FdF</b>
</h1>

<p align=center>

## Overview

The 42-FdF project is part of the 42 school's curriculum, focusing on graphics programming. The objective is to develop a program that reads a file containing a grid of height values and generates a 3D wireframe representation of the corresponding landscape. This project enhances understanding of 3D projections, transformations, and the use of graphics libraries in C.
The <b>fdf</b> program is a wireframe generator that takes .fdf format files and transforms them into tridimensional representations of relief landscapes. It manages colors and basic transformation, such as zoom, Z axis scaling. This project aims for the student to get familiarized with window management and pixel insertion on screen, using <i>MinilibX</i> library and pure C coding.  

## Screenshot
![screenshot1](01.jpg)

<h2>
Usage
</h2>

### Requirements
`fdf` requires a *gcc* compiler, MinilibX, X-Window and some standard libraries. At the moment, this particular project runs only on Linux systems. 

### Instructions

Clone this repository in your local computer:

```sh
$> git clone https://github.com/sbouaa/FdF.git path/to/fdf
```

In your local repository, run `make`

```sh
$> make 
```

> `make` suports 4 flags:
> - `make all` or simply `make` compiles fdf in its mandatory format
> - `make clean` deletes the `.o` files generated during compilation
> - `make fclean` deletes the `.o` and the `fdf` file generated
> - `make re` executes `fclean` and `all` in sequence, recompiling the program

To run `fdf`, type:
```sh
./fdf test_maps/<choose-your-map.fdf>
```
