# nemo

![GitHub License](https://img.shields.io/github/license/jseahos/nemo?style=flat-square)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/jseahos/nemo?style=flat-square)

nemo is an interpreter for the esoteric programming language Deadfish.

## Description

nemo is a Deadfish interpreter that takes inspiration from fellow esoteric programming language Brainfuck.
Consequently, nemo technically does not comply with the Deadfish standard (a.k.a. "the standard").
Because the standard leaves the accumulator's data type undefined,
nemo defines its accumulator as a byte, parallel to a single cell in Brainfuck.

## Getting Started

### Dependencies

- Unix-like OS (WSL for Windows may be a suitable substitute)
- make
- clang

### Installing

1. Run ```$ make all``` to build nemo.
2. Add the created `bin/` directory to your `PATH`.

## Authors

- [@jseahos](https://github.com/jseahos)

## License

nemo is licensed under the Apache 2.0 License - see [LICENSE](./LICENSE.txt) for more details.

## Acknowledgements

- [Deadfish](https://esolangs.org/wiki/Deadfish)
- [Brainfuck](https://esolangs.org/wiki/Brainfuck)
