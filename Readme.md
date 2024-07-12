# readme for ft_printf

## a rule-set for printf conversions shall be defined!

1) any '-' invalidates any '0' and any ' '
2) you can wildly mix -, + and 0's. but, rule No.1, 0's will be ignored
   alongside -'s. still - and + will count!
3) after **any (positive) number** there can **only** be a single '.' and
   eventually **another number** but nothing else (except the conversion char)!
4) also the mighty '#' + conv_char cannot be after the 
5) so it seems, there can be any wild mix of the flags '+', '-', ' ', '#' and
   '0' ('+' and '#x' is a bit special..) followed by a number a dot and a
   number. that's it. so for example: "%+--  0#0 + -x" is perfectly valid
   **this means:** we can simply test valid compl_convs based on this ruleset!
6) the '#' rules:
    - only is supposed to work with 'x', 'X'

## conversions & flags i have to deal with

- conversions:
 • %c Prints a single character.
 • %s Prints a string (as defined by the common C convention).
 • %p The void * pointer argument has to be printed in hexadecimal format.
 • %d Prints a decimal (base 10) number.
 • %i Prints an integer in base 10.
 • %u Prints an unsigned decimal (base 10) number.
 • %x Prints a number in hexadecimal (base 16) lowercase format.
 • %X Prints a number in hexadecimal (base 16) uppercase format.

- flags:
 • Manage any combination of the following flags: ’-0.’ and the field minimum width
   under all conversions.
 • Manage all the following flags: ’# +’ (Yes, one of them is a space)

**Question** what is the meaning of '.' when there is no float conversion?

## another approach for parsing conversions

from manpage:
    the overall syntax for conversion specification is:
    %[$][flags][width][.precision][length modifier]conversion

so maybe, straight from the beginning i should use a variadic function for
parsing conversions, something like
parse_conversions()...

ah!! no. The idea was different. I use a chain of functions for parsing.

1) `is_conversion()` checks for % and maybe just handles %% by printing %, else
it gives control to
2) `detect_conversion()`: detect wether we have a
2) `simple_conversion()`: which handles all simple stuff like %c and %d
3) `flag_conversion()`: which could also handle %010d or %.3lf

`flag_conversion` should detect specs to be handled. f.ex. the most complex
case: %+010d -> analyses this string like

char *p = "%+010d";

if (*p == '+') {
    flags++;
    flagspresent.plus = 1;
}
if (*p == '0') {
    flags++;
    flagspresent.zero = 1;
}

how to use this to call a variadic function?
something like:

if (flag1 && flag2)
    print_conversion(2, flag1, flag2);

if (flag1)
    print_conversion(1, flag1);

this means: `print_conversion(int n, ...)`

## conversion notes:

* '-': overrides 0 if present, left justification in field boundary. this means
       everything right of number is filled with whitespaces. 
       **can have multiple '-'** but this does not have any effect.
* '0': if also '-' is given '0' is ignored. pads d, i, o, u, x, X, a, A, e, E,
       f, F, g, and G with zeros
* '.': usually this is for precision with floats... for i, u, x, X this also
       pads by zero even in the presence of '-'
* 'x' and 'X': can only convert up to unsigned int.
* width: there **must not** be any flag between the conversion specifier and the
         width.

so, '-.10d' works. '-010d' only left justifies without padding by zero.

so a algorithm for deciding if we have valid, usable flags would be:

1) check if first char after % is a '-'
2) if next few digits are a valid unsigned int 

...
