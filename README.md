# <img align="middle" height="115" src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/ft_printfe.png" alt="ft_printf badge"/> ft_printf

[![Common Core](https://img.shields.io/badge/-Common%20Core-24292e?style=flat&logo=data:image/svg%2Bxml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAzNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+NDI8L3RpdGxlPjxkZXNjPkxvZ28gNDIgY29uIHBhZGRpbmcgaW5mZXJpb3JlOiBHaXRIdWIgcmltdW92ZSBnbGkgYXR0cmlidXRpIHN0eWxlIGRhbCBtYXJrZG93biwgcXVpbmRpIGlsIG1hcmdpbmUgY2hlIGFsbGluZWEgbCdpY29uYSBhbCB0ZXN0byBkZWwgdGl0b2xvIGUnIGluY29ycG9yYXRvIG5lbCB2aWV3Qm94LiBJbCBnbGlmbyBvY2N1cGEgeSAzLjU3NC0yMC40MjYgZSBzb3R0byByZXN0YW5vIDEzLjU3NCB1bml0YScgdnVvdGU6IHJlc28gYSA0MnB4IGNvbiBhbGlnbj1taWRkbGUsIGlsIGdsaWZvIHN0YSB+MnB4IHNvcHJhIGxhIGJhc2VsaW5lIGRlbCB0aXRvbG8uIFBlciBhbHphcmxvIGFuY29yYSBzZXJ2b25vICsxIHVuaXRhJyBkaSB2aWV3Qm94IG9nbmkgKzEuMnB4IGRpIGhlaWdodCAoY2lyY2EgKzAuNnB4IGRpIHNvbGxldmFtZW50bywgYSBwYXJpdGEnIGRpIGRpbWVuc2lvbmUgZGVsIGdsaWZvKS48L2Rlc2M+PHN0eWxlPnBhdGh7ZmlsbDojMDAwMDAwfSBAbWVkaWEgKHByZWZlcnMtY29sb3Itc2NoZW1lOmRhcmspe3BhdGh7ZmlsbDojRkZGRkZGfX08L3N0eWxlPjxwYXRoIGQ9Ik0xOS41ODEgMTYuODUxSDI0di00LjQzOVpNMjQgMy41NzRoLTQuNDE5djQuNDJsLTQuNDE5IDQuNDE4djQuNDRoNC40MTl2LTQuNDRMMjQgNy45OTNabS00LjQxOSAwaC00LjQxOXY0LjQyem0tNi4zMjQgOC44MzhINC40MTlsOC44MzgtOC44MzhIOC44MzhMMCAxMi40MTJ2My41OTVoOC44Mzh2NC40MTloNC40MTl6Ii8+PC9zdmc+Cg==)](https://profile.intra.42.fr/users/elmondo)
![Language](https://img.shields.io/badge/language-C-blue)
![Norm](https://img.shields.io/badge/Norminette-passing-brightgreen)
[![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen)](https://projects.intra.42.fr/projects/42cursus-ft_printf)

> A from-scratch reimplementation of the C standard library's `printf`, built to master variadic functions, pointer arithmetic, and recursive number formatting — without ever calling the real `printf`.

---

## 📖 Project Description

`ft_printf` is a 42 School project that recreates the behavior of the standard C `printf` function from the ground up.

The goal isn't just to print formatted text — it's to understand exactly how `printf` works internally:

- **Variadic arguments** — parsing an unknown number of arguments at runtime with `<stdarg.h>` (`va_list`, `va_arg`, `va_start`, `va_end`).
- **Format string parsing** — scanning a string character by character to detect `%` conversion specifiers on the fly.
- **Recursive formatting** — printing multi-digit numbers and hexadecimal values through recursive helper functions instead of buffers.
- **Return value accuracy** — matching libc's contract of returning the exact number of characters written, not just `0`/`-1`.

The entire codebase strictly follows the **42 Norminette** — no more than 25 lines per function, no more than 5 functions per file, no more than 4 parameters per function, tabs-only indentation, and no forbidden C constructs (`for`, ternaries, `switch`, etc.). The project compiles as a static library (`libftprintf.a`) so it can be linked into any C project, exactly like the real `libc`.

---

## 🔤 Supported Conversions

`ft_printf` implements all **mandatory** conversions defined by the 42 subject:

| Specifier | Description                                   | Example                          | Output                  |
|:---------:|------------------------------------------------|-----------------------------------|--------------------------|
| `%c`      | Prints a single character                      | `ft_printf("%c", 'A');`           | `A`                      |
| `%s`      | Prints a string (`(null)` if `NULL`)            | `ft_printf("%s", "42");`          | `42`                     |
| `%p`      | Prints a pointer address, hex-prefixed with `0x`| `ft_printf("%p", &var);`          | `0x7ffe3a1b2c40`         |
| `%d`      | Prints a signed decimal integer                 | `ft_printf("%d", -42);`           | `-42`                    |
| `%i`      | Prints a signed decimal integer (alias of `%d`) | `ft_printf("%i", 42);`            | `42`                     |
| `%u`      | Prints an unsigned decimal integer              | `ft_printf("%u", 42u);`           | `42`                     |
| `%x`      | Prints an unsigned integer in lowercase hex      | `ft_printf("%x", 255);`           | `ff`                     |
| `%X`      | Prints an unsigned integer in uppercase hex      | `ft_printf("%X", 255);`           | `FF`                     |
| `%%`      | Prints a literal percent sign                   | `ft_printf("%%");`                | `%`                      |

Every conversion returns the **exact number of characters printed**, mirroring the real `printf`'s return contract — verified character-by-character against libc in the test suite below.

---

## ⚙️ Compilation & Usage

### Build the library

The project ships with a `Makefile` that compiles every source file with strict warnings and archives the result into a static library. It only builds the library — no test artifacts ever touch the project root.

```bash
make        # compiles ft_printf.c and all helpers, builds libftprintf.a
make clean  # removes all .o object files
make fclean # removes .o files AND libftprintf.a
make re     # fclean + make, full rebuild from scratch
```

Under the hood, each `.c` file is compiled with `-Wall -Wextra -Werror` and archived with `ar rc`, producing a single linkable artifact: **`libftprintf.a`**.

### Use it in your own project

Drop `ft_printf.h` and `libftprintf.a` next to your source, `#include` the header, and link against the archive at compile time.

**`main.c`**
```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello, %s! You are %d years old.\n", "42", 21);
	ft_printf("Characters printed: %d\n", len);
	return (0);
}
```

**Compile & link:**

```bash
gcc main.c -L. -lftprintf -o my_program
./my_program
```

- `-L.` tells the linker to look for libraries in the current directory.
- `-lftprintf` links against `libftprintf.a`.

---

## 🧪 Testing

Correctness was validated on two fronts: a **self-written differential test suite** comparing output and return values against the real `printf`, and a **community-maintained tester** for edge-case coverage.

### 1. Differential testing against libc

All test sources live in **[`tests/`](tests/)**, with their own dedicated `Makefile` — kept fully separate from the library so the project root stays clean and `ft_printf`'s own `Makefile` only ever builds `libftprintf.a`. The suite calls `ft_printf` and `printf` side by side on every conversion, and checks that both the **output** and the **return value** match exactly.

```bash
cd tests
make run    # builds libftprintf.a (if needed), compiles the suite, and runs it
```

Every line is checked for:
- ✅ Identical printed output
- ✅ Identical return value (character count)
- ✅ Correct handling of edge cases: `NULL` strings (`(null)`), `NULL` pointers (`(nil)`), `INT_MAX`, and `0`

### 2. Community stress-testing

For broader edge-case coverage (empty format strings, malformed inputs, extreme values), the project was additionally run against **[Tripouille's printfTester](https://github.com/Tripouille/printfTester)**, one of the most widely used community test suites for this project:

```bash
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
# follow the tester's README to drop in ft_printf.c/.h and run its suite
```

> 💡 Other popular testers such as `ft_printf_tester` suites can be run the same way — clone, drop in the source files, and diff the output against libc.

---

## 📁 Project Structure

```
ft_printf/
├── ft_printf.c              # Core parser: reads the format string, dispatches by specifier
├── ft_putchar.c             # %c — single character
├── ft_putstr.c              # %s — strings (NULL-safe)
├── ft_putnbr.c              # %d / %i — signed integers
├── ft_putunbr.c             # %u — unsigned integers
├── ft_puthex.c              # %x / %X — hexadecimal
├── ft_putaddr.c             # %p — pointer addresses (NULL-safe)
├── ft_printf.h              # Public API + prototypes
├── tests/                   # Differential test suite, fully self-contained
│   ├── test_main.c
│   ├── test_main.h
│   ├── test_main_utils1.c
│   ├── test_main_utils2.c
│   └── Makefile             # Builds & runs the test suite (calls ../Makefile for the lib)
└── Makefile                 # Build rules for libftprintf.a only
```

---

## 🎯 Key Takeaways

- Deepened understanding of **variadic functions** and the C calling convention.
- Practiced **recursive algorithm design** for number-to-string conversion without buffers.
- Enforced **strict code discipline** under the 42 Norminette across every file.
- Built and validated a **static library** consumable by any external C project.
