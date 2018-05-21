#Output
C++ class template for "marking" output arguments.

## Usage
```cpp
  void foo(nathiss::output::Output<int&> ret) {
    ret.get() = 0;
  }
```
