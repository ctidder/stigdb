# Coding Conventions

This document covers the Stig C++ coding conventions.

## Nota Bene!

This document is currently a work in progress. If you have a question about anything which isn't covered here, **please ask**. We love questions.

In general this coding convention follows [Google C++ Style guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml)

## Indentation

### General rules

* This is a **TWO** space tab stop house.
* Please use spaces rather than tab characters.
* Empty lines are **empty**, i.e.: contain no space characters.

### Line wraps

If you must wrap a line, please intent it **two** levels from where the subsequent line begins.

For example:

```
    class TCompilerConfig : public Base::TCmd {
      public:
      TCompilerConfig(int argc, char **argv)
          : DebugOutput(false), InfoReport(false), MachineForm(false), SemanticOnly(false),
            SkipTests(false), VerboseTests(false) {

      Parse(argc, argv, TMeta());
    }
```

## Whitespace

### General rules

* This is a **TWO** space tab stop house.
* Please use spaces rather than tab characters.
* Please do not have trailing whitespace.
* Empty lines are **empty**, i.e.: contain no space characters.
* Please do not use spaces between an operator and its arguments.

## Naming and Namespaces

### Namespace usage

When you use a namespace, please indent it one level from the surrounding code.

When closing a curly brace, follow it with a `//` comment declaring which namespace has just been closed. For example:

    class TExprError
        : public TSourceError, public Base::TFinalError<TExprError> {
     public:

     TExprError(
         const Base::TCodeLocation &code_location,
         const TPosRange &pos_range,
         const char *message = "This expression is invalid.")
           : TSourceError(pos_range) {
       PostCtor(code_location, message);
     }

    };  // TExprError


### Getters and setters

Getter and setter names start with `Get` and `Set` (respectively).

### Local variables

All local variables are lowercased. Spaces are represented by an underscore (`_`).

### Member variables

All member variables use title casing. (ThisIsAMemberVariable)

If something is abbreviated, so title case makes it look like a macro because it's all caps, capitalize the first letter only:

"TASM" should be "TAsm"

### Pointers

Attach the `*` for pointers to whatever is on the right hand side. E.g.:

    const char *foo;

### Staters

Stater (functions/methods which return a state) names start with `Is` or `Has`. For instance, `bool IsEmpty() const` would
be a function to check if something is empty, rather than `empty()` which is ambiguous in whether it empties the class or
tells if the class is empty.

Occasionally we will have a stater name which starts with `Do`, but this is rare and not standard practice. Try to avoid it.

### Type names

All type names start with a capital `T`. These use title casing (e.g. `TCompilerConfig`).

    EXCEPTION:
    Sometimes you'll see a struct with a name which doesn't start with a T.
    This indicates that it's a holder for public static functions.

## Curly braces

### General rules

* Please place the open brace on the same line as the statement which begins the block.
* Please place the closed brace on a new line at the end of the block.
* Braces should be indented to the same level as the thing to which they're attached.

### With conditionals

* An `if` block should still have curly braces if it's only one line.
* For an `else` block, the closing and opening braces should be placed directly on either side of the `else`, separated from it by a single space.

## Parentheses

### General rules

* Please use a space between an `if` and the `(` of the conditional.
* Please use a space between the `)` of a conditional and the opening bracket of the block which follows.
* Please use parentheses around grouping expressions if there is a complex expression in the conditional.
* Please do not put a space between the function name and the opening parenthesis.

## Classes

### General rules

* In general, Stig prefers aggregation to deep class hierarchies.
* Class definitions should be indented one level from the surrounding code.
* Classes should be as self-contained as possible.
* Classes should initialize everything within it using a member initializer list on the constructor.
* All implementations of the class should be private and explicitly specify how people may interact with the class.
* Classes should almost always be defined using the keyword `class`. Only use `struct` if the class is just a collection of functions.
* Classes should not be able to enter a "bad state." Please follow the [RAII](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization) idiom. If you have to check something in a class
* Throw in constructors to indicate errors
* Never throw in a destructor (There is one exception to this). The current C++ standard actually mandates this terminates your program unless special care is taken.
* Use the `no construction` and `no copy` macros whenever necessary. (or = delete)
* Base classes should have virtual destructors.
* Use '= delete' and '= default' when possible to delegate to standard constructors/destructors which would otherwise be deleted
* Base classes must have virtual destructors

### Declaration order

* Public things should be declared first, followed by protected, and then private.
* Local typedefs should be at the top of the class.

### Functions and methods

* Functions which only access data within the class should be `const`.

## Includes

### General rules

* Please do not put a `using NAMESPACE` before the includes.
* All includes should be placed within angle brackets: `< >`
* Program-specific includes should always be declared with relative paths, including the top level path.
* Please do not include unnecessarily and clean up your includes if you no longer need them.
* Please try to move the includes to the .cc file instead of headers wherever possible.

### Ordering

* Includes should be organized in three different groupings:
    1. header file (if this is a .cc file)
    1. system includes
    1. program-specific includes
* Within each grouping, the includes should be listed alphabetically.
* There should be a blank line between each of these groupings.

## Unit Testing

The Stig team very strongly believes in unit tests.

That said, this section is currently TBD.

## Documentation

You cannot RTFM without TFM.

### General rules

* Inline documentation should be done using `//`.
* Any time you do anything even approaching moderately complex, **add a comment**.
* And if you want to add comments for things which are less complex, we will be glad to see them.

### Top of every file

At the top of every file there should be a large comment which includes:

* The name of the file
* The license statement
* The copyright statement
* What the classes can do
* How the classes interact
* An example of how to use the class in practice

If the file is a .cc, please put this comment into its .h file.

### Before every function

Before each function there should be a large comment which includes:

* What the function does
* Input parameters for the function
* Output range for the function

-----

coding.md (c) by Tagged, Inc.

coding.md is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.

You should have received a copy of the license along with this work. If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.

