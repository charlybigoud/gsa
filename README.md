# Generic Simulated Annealing #
gsa is an C++ optimization library based on the simulated annealing algorithm. This code was develop following the algorithm's description in the [wikipedia page](https://en.wikipedia.org/wiki/Simulated_annealing).

## Dependencies ##
* linux
* g++ >= 5.1
* C++14 (`-std=c++1y`).

## Usage ##
_SimulatedAnnealing_ is defined by 3 parameters:
* a start temperature
* a stop temperature
* a number of iteration per temperature step

The algorithm needs:
* a _State_ to optimize
* an _Energy_ function
* a state _Generator_

The _State_ can be defined as a variable, a `struct` or a `class`.
The other elements can be a `lambda`, a `struct` or a `class`.

Once you have defined you system you can run the optimization using `SimulatedAnnealing::operator()`.

To see some usage, please refer to the examples.

## Building ##
```
git clone git@github.com:charlybigoud/gsa.git
cd gsa
mkdir build
cd build
cmake ..
make -j
```
