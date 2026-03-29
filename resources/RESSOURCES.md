# Resources

Curated collection of C++ resources — tutorials, references, tools, and community recommendations.

---

## Official References

| Resource | Description | Reading Notes |
|----------|-------------|:---:|
| [cppreference.com](https://en.cppreference.com/) | The go-to C++ standard library reference. | [notes](notes/cppreference.md) |
| [isocpp.org](https://isocpp.org/) | Official ISO C++ site — news, FAQ, and the C++ Core Guidelines. | [notes](notes/isocpp.md) |
| [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) | Best-practice guidelines maintained by Bjarne Stroustrup & Herb Sutter. | [notes](notes/cpp-core-guidelines.md) |

## Learning & Tutorials

| Resource | Level | Notes | Reading Notes |
|----------|-------|-------|:---:|
| [learncpp.com](https://www.learncpp.com/) | Beginner–Intermediate | Excellent free tutorial series, very thorough. | [notes](notes/learncpp.md) |
| [The Cherno — C++ playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb) | Beginner–Intermediate | Popular YouTube series covering modern C++ concepts. | [notes](notes/the-cherno-cpp.md) |
| [Programiz C++](https://www.programiz.com/cpp-programming) | Beginner | Quick reference with short runnable examples. | [notes](notes/programiz-cpp.md) |

## Books

| Title | Author(s) | Notes | Reading Notes |
|-------|-----------|-------|:---:|
| *Programming: Principles and Practice Using C++* | Bjarne Stroustrup | Great intro from the language creator himself. | [notes](notes/programming-principles-stroustrup.md) |
| *A Tour of C++* | Bjarne Stroustrup | Concise overview of modern C++. | [notes](notes/tour-of-cpp.md) |
| *Effective Modern C++* | Scott Meyers | Deep dive into C++11/14 best practices. | [notes](notes/effective-modern-cpp.md) |
| *C++ Essentials* | Sharam Hekmat | Free, 311-page intro to the C++ language — practical and to the point, no deep OOP. | [notes](notes/cpp-essentials.md) |

## Tools & Environments

| Tool | Description | Reading Notes |
|------|-------------|:---:|
| [Compiler Explorer (Godbolt)](https://godbolt.org/) | Online tool to view assembly output of C++ code in real time. | [notes](notes/godbolt.md) |
| [C++ Insights](https://cppinsights.io/) | Shows what the compiler actually does with your code (template expansion, etc.). | [notes](notes/cpp-insights.md) |
| [OnlineGDB](https://www.onlinegdb.com/) | Online C++ compiler and debugger. | [notes](notes/onlinegdb.md) |

## Community Picks

Resources shared by the online community (LinkedIn, forums, Discord servers, Reddit, etc.)

<!-- Add entries below as you discover them. Format: -->
<!-- | [Name](url) | Source | Short comment | -->

| Resource | Source | Comment |
|----------|--------|---------|
| | | |

## Topic-Specific Deep Dives

Longer articles or videos on focused topics. Tag with the relevant phase from the [ROADMAP](../ROADMAP.md).

<!-- | [Title](url) | Topic | Phase | Notes | -->

| Resource | Topic | Phase | Notes |
|----------|-------|-------|-------|
| | | | |

---

*Add new finds here as you go. A quick one-line comment on why each resource is useful helps future-you.*

---

## Community Insights

Interesting comments, advice, and perspectives shared by people in the C++ community — LinkedIn, Reddit, Discord, etc. Stored here to reflect on and revisit.

---

### On `std` and the Standard Library

> I still avoid std as much as possible. The threading abstractions are fine, but `std::vector`, `std::string` and the standard allocation system needs to be deprecated. `std::string` made sense in the 1990s when each operating system had their own incompatible character encoding without any multi-byte characters, but in hindsight its name sounds like the go-to solution for holding a string, which it is not when Unicode is the default in modern operating systems, and then you need to use `std::u32string` as a beginner or `std::u8string` as an experienced developer who knows how UTF-8 is encoded in memory.
>
> — *David Piuva*

**Takeaway:** `std::string` is not as universal as its name implies — Unicode support requires `std::u8string` or `std::u32string`. Worth keeping in mind as I move past beginner examples.

> **Q:** What replaces `std::vector`? `boost::stable_vector` has reference stability and good cyclomatic complexity, but if not needing stable references, it's far slower at growing.
>
> — *Callan Gray*

> For performance critical cases, I use a SIMD and cache aligned `Buffer` type with reference counting. Then I can fetch bound-checked pointers from the buffer to use with SIMD operations. In debug mode I get checks for out-of-bound and alignment errors. With extra safe debug settings, it catches double free, use after free, use from wrong thread, et cetera.
>
> When performance is not critical, I use a safer container that only allows access by index, to reduce the risk of accessing invalidated memory, but you can still get references to elements from the `[]` operator, because otherwise it would be useless for storing objects with side-effects in member methods.
>
> The problem with `std::vector` is that it is trying to be both at once.
>
> — *David Piuva (reply)*

**Takeaway:** `std::vector` is fine for learning but has real trade-offs in production — reference stability vs. performance. Custom containers exist for a reason. Revisit this once I hit Phase 6 (RAII, smart pointers, advanced memory).

---

### On Learning Approach and Operator Overloading

> If you are new to C++ or trying it out, I'd say try the operator overloading, creating manual arrays using constructor, freeing them in destructor with messages, `fstream`, then low level file handling, etc. Try using `struct` for data object and `class` as controllers. Just a suggestion.
>
> Operator overloading example:
> ```cpp
> struct Category {
>     int id;
>     char name[31];
>
>     friend ostream& operator<<(ostream& os, const Category& c) {
>         os << c.id << " " << c.name;
>         return os;
>     }
> };
>
> // usage:
> Category c{1, "Beverages"};
> cout << c << endl;
> ```

**Takeaway:** Good suggested learning order that aligns with my ROADMAP. The `struct` for data / `class` for controllers pattern is a clean mental model. Already covered operator overloading in Phase 3 — see [`ex13-surcharge-operateurs.cpp`](../course-work/ex13-surcharge-operateurs.cpp).

---

### On Long-Term C++ Journey and Frameworks

> I had started exploring C++ way back in 1995, but since I was a beginner then, and hence did not get opportunities. Hence stopped going ahead with it. Now that I retired from my company 4+ years ago, I thought to delve into different technologies, C++ being one of them. As you progress, you might be interested in looking at **Drogon**, C++ MVC framework.

**Takeaway:** Look into [Drogon](https://github.com/drogonframework/drogon) later — a C++ MVC web framework. Could be a fun project idea beyond IFT1166 scope (Phase 6+).
