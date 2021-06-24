# Light Weight "First Come, First Served" Scheduler in C (Work in Progress)

[![Build Status](https://www.travis-ci.com/TSonono/embedded-fcfs.svg?branch=main)](https://www.travis-ci.com/TSonono/embedded-fcfs)
[![codecov](https://codecov.io/gh/TSonono/embedded-fcfs/branch/main/graph/badge.svg?token=QUAP8N8V1H)](https://codecov.io/gh/TSonono/embedded-fcfs)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/TSonono/embedded-fcfs.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/TSonono/embedded-fcfs/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/TSonono/embedded-fcfs.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/TSonono/embedded-fcfs/context:cpp)


This library is a generic "first come, first served" scheduler written in C, optimized for embedded. It follows the C99 standard, and only has one dependency (a fifo library).

## Goals
- Generic - The library should be useable in Soc:s from different vendors
- No dynamic memory allocation
- Low memory footprint
- Minimal performance overhead

## Contributing
Submit a pull request. Please format your code using the .clang-format file, follow C99 and ensure that the code compiles and is tested.
