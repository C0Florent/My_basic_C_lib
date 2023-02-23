# My basic_C_lib

## How this came to exist

This C library is entirely home made and mainly inspired by the EPITECH C pool which consists, among other things, in recreating some functions from the standard C library, as well as some other functions for learning purposes, all that as `write` being the only standard function allowed.
This C pool concluded by remaking the `printf` function, only from the functions we had crafted so far, plus `malloc` and `free`.

Over the course of my first academic year (which I am still in as I write these words), I have wanted to craft a well-organised and subdivided library containing all my functions from the C pool, and some more I write along the way, for all purposes I may encounter during my projects.
At some point, I also made a proper Makefile system to hold properly my library and make it easy to take some sub-libraries but not others, and compile all that with some project-specific source files for each given project, since for each project, most of the time we only have one binary to produce.
And this is where I'm at right now.



## Quick description of each lib

- my:  
Functions made during the C pool, plus a few personal functions made during my first month at Epitech


- newmy:  
All-purpose functions that I now cannot live without. They are in the spirit of C pool, but made from personal involvement and perform more complex tasks such as handling string arrays.  
-- Needs 'my'


- my_printf:  
Reproduction of the standard function printf, without buffer handling, and excluding %g and %a conversions. Also contains internal functions used to make my_printf() work  
-- Needs 'my' and 'newmy'


- mysys:  
Actually only contains one function, to return the size of any given file using stat


- my_math:  
A few functions and macros used for all math projects  
-- Uses standard printf() and variants


- my_vector:  
Minimalist implementation of vectors, with only functions to allocate, free, and show coordinates of vectors.  
-- Uses standard printf()


- my_matrix:  
Proper implementation of matrices in C, with functions to allocate and free, show values with several display modes, set or reset values, and perform operations on matrices such as scalar, product and inverse.  
-- Almost without any standard C functions, and mostly compliant with Epitech's coding style (soon to come)


- my_graphics:  
Basic functions to facilitate the use of the CSFML library, and (still in development) a tool to create and easily manipulate slidebars, to make nice UI


## What you could benefit from this

If you are a beginner with the C language, perhaps reading these functions could help you understand some things about how the C language works. Or perhaps you are struggling to write a specific function which I have done, and you could check how I did it to see a way of doing it.
Except from that, there might be no use, because this lirary is nothing revolutionary as it is now. Anyway, everything written here (perhaps except for the my library) is written to be clean and understandable, even for complex tasks, so it shouldn't be any negative to read or use some of my functions in your projects.


## Documentation ?

As of now, there is no proper documentation, but for functions that require explaining, you can find a descritption in the header file associated with the sub-library the function is in. Anyway, there is not really anything there that requires documentation


## Testing ?

For the most part, testing is something I have yet to do, but for now, the my_printf function is properly tested, and the libmy is tested 40% (in terms of line coverage)  
Check the tests in the `tests` folder if you are curious
