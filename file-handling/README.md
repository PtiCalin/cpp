# File Handling

Examples for reading from and writing to files with basic persistence logic.

## Contents

- [`file-handling.cpp`](file-handling.cpp) — Comprehensive file I/O library (~1000 lines, requires C++17) covering:
  - Reading: full file, line-by-line, binary, CSV, first/last N lines, line ranges
  - Writing: overwrite, append, line-by-line, binary, CSV
  - File operations: copy, move/rename, delete, compare, merge, split
  - Directory operations: list files, recursive listing, create, delete, copy
  - File info: existence, size, extension, name, parent, absolute path, permissions
  - Search & replace: text search, regex search, find files by name/extension/content
  - Statistics: line/word/character count, word frequency
  - Path manipulation: join, normalize, relative, change extension
  - Advanced: temp files, mutex locking, file watch, checksum, timestamped backup, config read/write

> Source: IFT1969 / IFT1166 course notes
