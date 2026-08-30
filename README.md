# <img align="middle" height="115" src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/ft_printfe.png" alt="ft_printf badge"/> <picture><source media="(prefers-color-scheme: dark)" srcset="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=58A6FF&vCenter=true&width=400&height=80&lines=ft_printf"><source media="(prefers-color-scheme: light)" srcset="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=0366D6&vCenter=true&width=400&height=80&lines=ft_printf"><img align="middle" src="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=0366D6&vCenter=true&width=400&height=80&lines=ft_printf" alt="ft_printf"/></picture>

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

Every conversion returns the **exact number of characters printed**, mirroring the real `printf`'s return contract.

---

## ⚙️ Compilation & Usage

### Step 1 — Build the library

> **You must run `make` first.** The library (`libftprintf.a`) must exist before you can compile any program that uses `ft_printf`. Without this step the linker will not find the archive and compilation will fail.

```bash
make        # compiles all .c files and archives them into libftprintf.a
make clean  # removes all .o object files
make fclean # removes .o files AND libftprintf.a
make re     # fclean + make, full rebuild from scratch
```

Under the hood, each `.c` file is compiled with `-Wall -Wextra -Werror` and archived with `ar rc`, producing a single linkable artifact: **`libftprintf.a`**.

---

### Step 2 — Write your `main.c`

Copy and paste the file below as-is — it already includes the header, tests every supported specifier, and checks return values.

**`main.c`** *(copy-paste ready)*
```c
#include "ft_printf.h"

int	main(void)
{
	int		ret;
	char	*null_str;
	void	*null_ptr;
	int		n;

	null_str = NULL;
	null_ptr = NULL;
	n = 42;

	/* %c — single character */
	ret = ft_printf("%%c  -> [%c]\n", 'A');
	ft_printf("       return: %d\n", ret);

	/* %s — string, including NULL */
	ret = ft_printf("%%s  -> [%s]\n", "hello 42");
	ft_printf("       return: %d\n", ret);
	ret = ft_printf("%%s  -> [%s]  (NULL string)\n", null_str);
	ft_printf("       return: %d\n", ret);

	/* %p — pointer, including NULL */
	ret = ft_printf("%%p  -> [%p]\n", &n);
	ft_printf("       return: %d\n", ret);
	ret = ft_printf("%%p  -> [%p]  (NULL pointer)\n", null_ptr);
	ft_printf("       return: %d\n", ret);

	/* %d / %i — signed integers */
	ret = ft_printf("%%d  -> [%d]\n", -2147483648);
	ft_printf("       return: %d\n", ret);
	ret = ft_printf("%%i  -> [%i]\n", 2147483647);
	ft_printf("       return: %d\n", ret);

	/* %u — unsigned integer */
	ret = ft_printf("%%u  -> [%u]\n", 4294967295u);
	ft_printf("       return: %d\n", ret);

	/* %x / %X — hexadecimal */
	ret = ft_printf("%%x  -> [%x]\n", 255);
	ft_printf("       return: %d\n", ret);
	ret = ft_printf("%%X  -> [%X]\n", 255);
	ft_printf("       return: %d\n", ret);

	/* %% — literal percent sign */
	ret = ft_printf("%%%%  -> [%%]\n");
	ft_printf("       return: %d\n", ret);

	return (0);
}
```

---

### Step 3 — Compile and run

Place `main.c` in the **same directory** as `libftprintf.a` and `ft_printf.h`, then:

```bash
gcc main.c -L. -lftprintf -o my_program
./my_program
```

| Flag | Meaning |
|------|---------|
| `-L.` | tells the linker to look for libraries in the current directory (`.`) |
| `-lftprintf` | links against `libftprintf.a` (the `lib` prefix and `.a` extension are implicit) |

If `libftprintf.a` is in a different folder, replace `-L.` with `-L/path/to/folder`.

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
└── Makefile                 # Build rules for libftprintf.a only
```

---

## 🎯 Key Takeaways

- Deepened understanding of **variadic functions** and the C calling convention.
- Practiced **recursive algorithm design** for number-to-string conversion without buffers.
- Enforced **strict code discipline** under the 42 Norminette across every file.
- Built and validated a **static library** consumable by any external C project.
