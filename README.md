# Light Weight "First Come, First Served" Scheduler in C

[![Build Status](https://www.travis-ci.com/TSonono/embedded-fcfs.svg?branch=main)](https://www.travis-ci.com/TSonono/embedded-fcfs)
[![codecov](https://codecov.io/gh/TSonono/embedded-fcfs/branch/main/graph/badge.svg?token=QUAP8N8V1H)](https://codecov.io/gh/TSonono/embedded-fcfs)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/TSonono/embedded-fcfs.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/TSonono/embedded-fcfs/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/TSonono/embedded-fcfs.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/TSonono/embedded-fcfs/context:cpp)


This library is a generic "first come, first served" scheduler written in C, optimized for embedded. It follows the C99 standard, and only has one dependency (a fifo library, [lwrb](https://github.com/MaJerle/lwrb)).

## Goals
- Generic - The library should be useable in Soc:s from different vendors, with different architectures
- No dynamic memory allocation
- Low memory footprint
- Minimal performance overhead
- Follow C99 standard

## Using the library
If you add this to your project as a submodule recursively, one way is to link it to your project using cmake by adding the root directory of this repo as a subdirectory. If your project is not cmake based, you can manually add fcfs.c and lwrb.c (fifo library) among the compiled and linked files in your project. You would also have to add the include directories inc/ and external/lwrb/lwrb/src/include.

## Build (for development)
```bash
cmake -B build
cd build
cmake --build .
```

## Contributing
Submit a pull request. Please format your code using the .clang-format file, follow C99 and ensure that the code compiles and is tested.

# Future work
- Include an optional abstraction for entering critical region, which should be used when adding event to the scheduler. This should increase the reliability of the scheduler.