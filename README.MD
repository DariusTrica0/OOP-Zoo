# Zoo OOP 

A small project in C++17 that demonstrates object-oriented programming (OOP) using animal examples. It shows inheritance, polymorphism (virtual methods), operator overloading, and memory management via RAII with `std::unique_ptr`.

## What does the project contain?
- Abstract base class `Animal` with pure virtual methods: `species()`, `sound()`, `clone()`.
- Derived classes: `Dog`, `Eagle`, `Snake`, each with specific data and behavior.
- Container `Zoo` that stores polymorphic objects: `std::vector<std::unique_ptr<Animal>>`.
- Overloaded operators:
- for `Animal`: `<<` (display), `<` (sort), `==` (equality), `++` (prefix — aging);
- for `Zoo`: `+=` (add animal via `clone()`), `[]` (indexed access).
- Clear interface/implementation separation: headers (`.hpp`) declare **what** exists, sources (`.cpp`) define **how** it works.

## Project structure
```
.
├── include
│   ├── animal.hpp
│   ├── dog.hpp
│   ├── eagle.hpp
│   ├── snake.hpp
│   └── zoo.hpp
└── src
    ├── animal.cpp
    ├── dog.cpp
    ├── eagle.cpp
    ├── snake.cpp
    ├── zoo.cpp
    └── main.cpp
```



## How it works (in short)
- `Animal` remembers `name_` and `age_` and defines the virtual interface. It has `print(std::ostream&)`, and `operator<<` uses `print` so you can print to any stream (console, file, string).
- `Dog`, `Eagle`, `Snake` override `species()`, `sound()`, `clone()` and extend `print(...)` with their information.
- `Zoo` stores **polymorphic clones** (`a.clone()`) to avoid *object slicing* when you place derivatives into a base collection.
- `sortByAge()` uses `operator<` from `Animal`, and `operator[]` gives you access to animals by index.
