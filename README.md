# C'ing clearly

I'm learning the basics of C and I'm using this repository to store my projects
and to track my progress.

Following **The C Programming Language** by _Brian W. Kernighan_
and _Dennis M. Ritchie_ in the 2nd edition for now.

**Currently at:** Chapter 3.

---

Next Session:

- Exercises 3
- Chapter 4

## Notes

- integer division _truncates_

- _null statements_ satisfy statement body constraints:

  ```c
  for (c = 0; getchar() != EOF; ++c)
    ;
  ```

- _character constants_ are numerical values of character: `'a'` is 97 in ASCII

- because assignments are left associating expressions you can do:

  ```c
  nl = nw = nc = isSeq = 0
  ```
- return value `0` implies normal termination

- all function arguments are passed _by value_
    * if variable outside of the function scope needs to be altered a *pointer* is used
    * arrays are passed by reference; address of the beginning of the array

- string is character array with termination char: "foo" = `[f, o, o, \0]`

- declaring an object `const` prevents it from being changed

- lower case variable names are used; snake case

- library variables often start with `_`

- enum `enum boolean { NO, YES }`
    * unspecified values progress from the last specified one `enum foo { bar = 1, baz }` (baz is 2)
    * names in different enumb must be distinct, values don't need to be

- use `const` with array arguments, to indicate that it's not changed by the function

- `%` cannot be applied to `fload` or `double`

### Precedence

- Precedence: **unary +** - then **\* / %** then **binary + -**

- relational operators have the same precedence

- equality operators are below that

- && higher than ||

### Type Conversion

- only narrowing is automatic

- `<ctype.h>` provides tests & conversions independet of character set

- char -> int can produce negative integer
    * every char in a machines standard printing character set will never be negative
    * arbitrary bit patterns stored in `char` can be

- _true_ in test part of `if, while, for,...` just means _non-zero_

- lower type is promoted before arithmetic binary opperator proceeds

Informal rule-set for `signed` operands
- either one `long double` -> `long double`
- `double` -> `double`
- `float` -> `float`
- `long` -> `long`

! `floats` are not automatically converted to `double` !

- functions in `<math.h>` use double precision

- comparison between `unsigned` operands are machine-dependant

- longer int -> int / int -> char: dropping excess high-order bits

- `float` -> `int` causes trunctation of fractional part

- `double` -> `float`: rounded or truncated

- type conversions take place on passed arguments

#### default argument promotion

In the absence of a _function prototype_ the compiler has to make assumptions about passed arguments.

- `char`, `short` -> `int` (integer promotion)
- `float` -> `double`

### end

- type coercion using _cast_: `(type) expression`
    * the expression is not altered

- argument declaration in function prototype causes _automatic coercion_

- prefix increment/decrement sets value before it is used

- postfix increment/decremnt sets the value after it's used

- if no value is wanted postfix and prefix are the same

- bitwise operators: & | ^ << >> ~

- >> `signed` quantity fills with either sign bits or 0-bits

- `assignment operators` _op=_: expr1 op = expr2 is equivalent to expr1 = expr1 op expr2
    * +
    * _
    * *
    * /
    * %
    * <<
    * >>
    * &
    * ^
    * |

- ternary _expression_ exists: `expr1 ? expr2 : expr3`

- evaluation order of operands is not specified: In cases like `x = f() + g()` using temporary variables makes sense if either `f` or `g` alters a variable used by the other.

- function argument evaluation order also is implementation specific
    ```c
    printf("%d %d\n", ++n, power(2, n)); /* WRONG */

    ---

    ++n;
    printf("%d %d\n", n, power(2, n));
    ```

- **DON't WRITE CODE THAT DEPENDS ON THE ORDER OF EVALUATION**

## Interesting

Function declaration previous to ANSI C

```c
foo(bar, bar)
int bar, baz;
{
    ...
}
```

- `-1` flips bits starting from the rightmost 1-bit to the LSB
- `x &= (x - 1)` clears the rightmost 1-bit
