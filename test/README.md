# Testing Suite for fcfs

This directory contains an environment for writing and executing tests for the fcfs library. It supports code coverage along with different usage of sanitizers (such as ASAN and UBSAN).

## Requirements
The repository must have been built recursively for retrieval of the necessary git submodules. Further more, this testing environment requires cmake. For sanitizers you need to use a compiler which has the sanitizer dependencies availble. For coverage, you also need gcov and lcov.

## Build

```bash
cmake -DSANITIZE_ADDRESS=On -DSANITIZE_UNDEFINED=On -DFCFS_WITH_COVERAGE=On FCFS_BUILD_TESTS=On -B build
cd build
cmake --build .
```

`-DSANITIZE_ADDRESS -DSANITIZE_UNDEFINED` are optional to pass to the cmake invocation. Including is a good idea to find more potential bugs, but if you don't have sanitizer libraries in stalled in your computer you can simply discard those optional features. Same applies to `-DFCFS_WITH_COVERAGE`.

## Run tests
```bash
# From within the build directory created before
ctest
# or make test
```

## Coverage output
```bash
# From within the build directory created before
# Don't use ninja when configuring cmake if you want to run this command
make coverage
# Assuming you have google chrome installed on a linux host machine
google-chrome coverage/index.html  # To see the coverage html output
```

## Future work
Run this in a CI environment such as Travis. Pass the result and coverage output as banners in the repository.