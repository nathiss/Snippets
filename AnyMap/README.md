# AnyMap

C++'s map for storing any type.

## Usage

1. Create an object
```c++
nathiss::AnyMap map;
```

2. Store the data
```c++
map.set("string", std::string(abc));
map.set("int", 12);
map.set("bool", false);
map.set("obj_ptr", &MyObject);
```

3. Access the data
```c++
auto string_var = map.get<std::string>("string");
auto int_var = map.get<int>("int");
auto bool_var = map.get<bool>("bool");
auto obj_ptr = map.get<MyObject*>("obj_ptr");
```
