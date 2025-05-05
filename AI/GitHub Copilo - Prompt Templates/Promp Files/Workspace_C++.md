# Project coding guideline
## Code quality
- Code must not contain any compilation warning.
- Code should be clean:
	+ Function / method should do only one thing.
	+ Explain yourself in code, not in comments.

## Naming convention
- Use PascalCase for interface, class, function, class method.
- Use cammelCase for local variables.
- Prefix "m_" for member variables of classes. For example: use "m_height" instead of "height".
- Prefix "p" for variables of pointer type. For example: use "pMyPointer" instead of "myPointer".
- Prefix "s_" for static variables. For example: use "s_height" instead of "height".

## MISRA C++ 2008 rules
- Code must not contain any MISRA C++ 2008 defect:
	+ Rule 0-1-1: A project shall not contain unreachable code
	+ Rule 0-1-3: A project shall not contain unused variables
	+ Rule 0-1-4: A project shall not contain non-volatile POD variables having only one use
	+ Rule 0-1-6: A project shall not contain instances of non-volatile variables being given values that are never subsequently used
	+ Rule 0-1-11: There shall be no unused parameters (named or unnamed) in non-virtual functions
	+ Rule 0-1-12: There shall be no unused parameters (named or unnamed) in the set of parameters for a virtual function and all the functions that override it
	+ Rule 2-7-1: The character sequence /* shall not be used within a C-style comment
	+ Rule 2-7-2: Sections of code shall not be "commented out" using C-style comments
	+ Rule 2-7-3: Sections of code should not be "commented out" using C++ comments
	+ Rule 2-13-3: A "U" suffix shall be applied to all octal or hexadecimal integer literals of unsigned type
	+ Rule 2-13-4: Literal suffixes shall be upper case
	+ Rule 3-1-1: It shall be possible to include any header file in multiple translation units without violating the One Definition Rule
	+ Rule 3-4-1: An identifier declared to be an object or type shall be defined in a block that minimizes its visibility
	+ Rule 3-9-1: The types used for an object, a function return type, or a function parameter shall be token-for-token identical in all declarations and re-declarations
	+ Rule 3-9-2: typedefs that indicate size and signedness should be used in place of the basic numerical types
	+ Rule 5-0-13: The condition of an if-statement and the condition of an iteration-statement shall have type bool
	+ Rule 5-0-15: Array indexing shall be the only form of pointer arithmetic
	+ Rule 5-0-21: Bitwise operators shall only be applied to operands of unsigned underlying type
	+ Rule 5-2-1: Each operand of a logical && or || shall be a postfix-expression
	+ Rule 5-2-4: C-style casts (other than void casts) and functional notation casts (other than explicit constructor calls) shall not be used
	+ Rule 5-3-1: Each operand of the ! operator, the logical && or the logical || operators shall have type bool
	+ Rule 6-2-2: Floating-point expressions shall not be directly or indirectly tested for equality or inequality
	+ Rule 6-6-4: For any iteration statement there shall be no more than one break or goto statement used for loop termination
	+ Rule 6-6-5: A function shall have a single point of exit at the end of the function
	+ Rule 7-1-2: A pointer or reference parameter in a function shall be declared as pointer to const or reference to const if the corresponding object is not modified
	+ Rule 7-3-1: The global namespace shall only contain main, namespace declarations and extern "C" declarations
	+ Rule 7-3-4: The using-directives shall not be used. Use the using-declaration instead
	+ Rule 7-5-4: Functions should not call themselves, either directly or indirectly
	+ Rule 8-5-1: All variables shall have a defined value before they are used
	+ Rule 9-5-1: Unions shall not be used
	+ Rule 11-0-1: Member data in non-POD class types shall be private
	+ Rule 16-2-1: The pre-processor shall only be used for file inclusion and include guards
	+ Rule 18-0-2: The library functions atof, atoi and atol from library <cstdlib> shall not be used
	+ Rule 18-4-1: Dynamic heap memory allocation shall not be used
	+ Avoid unneccessary type castings.
