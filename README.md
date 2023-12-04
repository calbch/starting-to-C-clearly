# C'ing clearly

I'm learning the basics of C and I'm using this repository to store my projects
and to track my progress.

Following **The C Programming Language** by _Brian W. Kernighan_
and _Dennis M. Ritchie_ in the 2nd edition for now.

Currently at: **Chapter 2**

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

