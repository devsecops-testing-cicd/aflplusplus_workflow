# AFLPlusPlus action


## Background

AFL++ is the most popular fuzzing engine used by many software engineers and security enthusatics. 
The motivation is to create action is where the local workstation is exhausted, Github Actions can be used to fuzz the target continuously.

## Actions

### Compiling the target project with AFLPlusPlus

Use the [aflplusplus_build](./aflplusplus_build/action.yaml) to build the target with AFL++ compilers.

Currently supported build platforms
- CMake

### Fuzzing the target project with AFLPlusPlus

Use the [aflplusplus_run](./aflplusplus_run/action.yaml) to run AFL++ fuzz test.