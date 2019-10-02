# Timed Message Scheduler Library

[![Build Status](https://travis-ci.org/kigster/timed-messages.svg?branch=master)](https://travis-ci.org/kigster/timed-messages)

NOTE: This library uses CMake and a CCSpec project for automated tests and uses the layout provided by the [cmake-ccspec-template](https://github.com/kigster/cmake-ccspec-template) project.

## Summary

This library allows submitting a number of textual messages that are meant to be activated only during a particular timeframe. The public API allows clients to query the "current message" for display in a public LED displays, or using as an artist schedule, etc. 

See [`FrolicSchedule.cpp`](https://github.com/kigster/timed-messages/blob/master/src/schedule/FrolicSchedule.cpp) for an example of how the schedule is defined.

### Future Enhancements

 * Read the schedule from YAML file
 * Support recurring events

## Build

### Prerequisites

 1. Please install XCode Tools: `xcode-select --install`
 2. Install HomeBrew — following the [instructions here](https://brew.sh).
 3. Install `direnv` — `brew install direnv`, and then `echo 'eval "$(direnv hook bash)"' >> ~/.bashrc`
 4. Run `source ~/.bashrc`

### Download the Sources

Run the following commands:

```bash
mkdir ~/workspace && cd ~/workspace
git clone git@github.com:kigster/timed-messages.git timed-messages
cd timed-messages
direnv allow .
```

### Building and Running The Project

There are three ways of building/running this project: 1) using bazel, 2) using cmake, and 3) using a provided shell wrapper around cmake.

#### 1. Building with Bazel
 
1. Install `bazel` using brew: `brew install bazel`. This may also download and install the JDK.
2. At the root of the project, run `bazel build //...:all`
3. To run the built binary, run `bazel run //src:scheduler '2019/08/02 21:30:00'`
4. To run the automated tests, run `bazel run //spec:scheduler_specs`

#### 2. Buiilding with CMAKE 
 
 1. Install CMake — `brew install cmake`
 2. Then run the following:

 
 ```bash
 # At the root of the project:
 git submodule init && git submodule update
 rm -rf build
 mkdir -p build 
 cd build
 cmake ..
 make -j 16 && make install
 cd ..
 # Now Run the specs and the binary:
 bin/scheduler
 bin/scheduler_specs
 ```
 
#### 3. Using Automated Build Script

You can use the provided BASH script `sbin/cmake-ctl` to build and run all the tests.

Examples (NOTE: we run `build` without `sbin/cmake-ctl` because of the `direnv` setup we did earlier.' If you skipped this part, you will need to change `build` with `sbin/cmake-ctl` below:

```bash
$ cmake-ctl
$ cmake-ctl build
$ cmake-ctl run
$ cmake-ctl clean
```

## People

 * [Konstantin Gredeskoul](/kigster)
 * [Paul Henry](/f3nry) (Bazel build)
