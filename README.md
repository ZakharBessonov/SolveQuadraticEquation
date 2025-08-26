# Quadratic equation solver(R) Version 1.0 26/08/2025

This program solves quadratic equations.

## GENERAL USAGE NOTES

- The program works on a set of real numbers. The accuracy is guaranteed to be at least 13 decimal places. Do not use numbers with a module greater than 99999999999 as coefficients (otherwise the program will give incorrect answers).

- When entering letters instead of coefficients, the program will require re-entry if entered from the keyboard, or will skip the erroneous line if entered from a file. However, if inf or NaN are entered as coefficients when entering from a file or from the keyboard, the program will immediately crash.

- The program has four implementations: the regular user version (quadr), a debug version (quadrDebug), a test version (quadrTest), and a version for testing in debug mode (quadrTestDebug). In debug mode, the program issues “assert” statements instead of outputting a fatal error message in words. In test mode, you can check the program’s functionality by entering your tests in the Tests.txt file. Each test consists of three coefficients, two roots to be obtained, and the number of roots. If the number of roots is infinite, enter -1 as the number. If zero roots are to be obtained, any numbers can be specified instead of roots. If one root is to be obtained, write it first, and then any other number. If two roots are to be obtained, write the smaller of the roots first.

- Please enter correct tests in test mode. I didn't bother much about the program's behavior with incorrect tests.

## Usage

- User version:
```bash
./quadr
```
- Debug version:
```bash
./quadrDebug
```
- Test version
```bash
./quadrTest
```
- Version for testing in debug mode
```bash
./quadrTestDebug
```

## Rights

All rights reserved. Just try to violate them!
