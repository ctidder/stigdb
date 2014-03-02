# Stig C++ Best Practices

This document covers the Stig C++ Best Practices.

## Nota Bene!

This document is currently a work in progress. If you have a question about anything which isn't covered here, **please ask**. We love questions.

For now the formatting of this document may be a little haphazard. We welcome help in cleaning it up, organizing it, and otherwise enhancing it.

## General Rules

In no particular order (yet)…

* Please don't declare multiple variables in a single declaration.
* The above goes double if you're declaring pointers.
* `using NAMESPACE` is strictly forbidden from headers or above any includes.
* Use [RAII](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization).
* Use exceptions.
* Write exception-safe code.
* A class should only ever do one thing.
* In general, it is usually better to use aggregation rather than inheritance (though we're currently re-thinking our position on this).
* If you use the `bool` operator and it's not explicit, a certain member of the community may seek you out and say something rather rude in a very loud voice.
* Use `const` liberally.
* Never use raw pointers. Instead, use `unique_ptr` or `shared_ptr`.
* However, if your pointer _must_ be raw, please wrap it (usually in a class) in order to control the resource.
* Use invasive containment when appropriate.
* Exit early. Don't just hang around in the body of an `if` for the entire function.
* Pass by reference (generally). And by `const` reference whenever possible.
* Only copy if necessary, avoid excessive copies.
* Please use C++11s new `for each` loop instead of `for`.
* Leverage the compiler: make things into compiler errors rather than runtime errors. Your users will thank you.
* Build tools to help make redundant/repetitive code less so and enforce good rules/hygiene

-----

best_practices.md (c) by Tagged, Inc.

best_practices.md is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.

You should have received a copy of the license along with this work. If not, see <http://creativecommons.org/licenses/by-sa/4.0/>.

