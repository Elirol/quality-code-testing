# README

This repo is dedicated to a lab assignment regarding code testing

## Cloning

To clone this repo and get the submodules, use the following command:

~~~ cmd
git clone --recurse-submodules https://github.com/Elirol/quality-code-testing.git
~~~

or, incase you already cloned it, use this command:

~~~ cmd
git submodule update --init --recursive
~~~

## Running

To build the program, enter the following commands

~~~ cmd
cmake -S . -B build -DBUILD_TESTING=TRUE -DENABLE_COVERAGE=TRUE -DENABLE_COLORED_OUTPUT=TRUE
cmake --build build
~~~

To run it, enter the following command:

~~~ cmd
./build/Main
~~~

or alternatively

~~~ cmd
cd build
./Main
~~~

To run the tests, enter the following command:

~~~ cmd

~~~
