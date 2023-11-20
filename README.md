# Lab 41: Hybrid Sort

In this lab we will look at situations where quick sort is not so quick, and what to do about it.

## Quadratic Time vs. Log-Linear Time

First, recall the time complexities of insertion sort and quick sort: Insertion sort is `O(n^2)` while quick sort is, on average, `O(n log n)`. But what about the constant factors in those expressions? Big-O notation can hide the true cost of an algorithm, at least for smaller values of `n`.

To observe this mathematically, plot `x^2` and `x*log(x)` using a graphing tool such as [Desmos](https://www.desmos.com/calculator). For the x-range, use [1..1000] and for the y-range, use [1..10000]. (Remember that most tools don't support base-2 logarithms, but you can easily convert a log of any base to any other. For example: `log2(x)=log10(x)/log10(2)`.) You should see that `O(n log n)` is clearly better than `O(n^2)` in terms of growth rate.

But what happens if we add in some constant factors? Change your graph to plot `2*x^2` and `20*x*log(x)`. Keep the y-range the same, but zoom the x-range to [1..100]. What do you see? Is the `O(n^2)` growth always better?

## Insertion Sort Performance

Now let's look at a case where quadratic time beats log-linear time in real benchmarks. Run the provided benchmarks of insertion sort and quick sort for small values of _n_. You should find that insertion sort, an `O(n^2)` algorithm, is actually quicker than quick sort, an `O(n log n)` algorithm, until _n_ reaches 512 or so. Why is this? (Hint: The reason is _not_ due to poor pivoting, as this implementation of quick sort selects each pivot randomly.)

## Hybrid Sort

Both the theory and the benchmarks indicate that insertion sort is faster than quick sort for small values of _n_. Let's use that knowledge to write a _hybrid_ sort that is quicker than quick sort! It should work exactly like quick sort, but if the number of elements to be sorted is "small", it should switch to insertion sort. The definition of "small" depends on the performance characteristcs of your computer and the values to be sorted, but a size between 5 and 20 usually works best.

Add your implementation to the `hybridSort` template. Simply write `hybridSort` as if you are writing quick sort, but before doing the paritioning and recursion, check the number of elements to be sorted. If it is less than some small number (try 16), then run insertion sort instead. Note that you do not need to re-write nor copy-paste the partition algorithm; you can invoke it directly from your `hybridSort` code.

Uncomment the hybrid sort unit tests and run them to make sure your code works. Next, uncomment both the quick sort and hybrid sort "large vector" benchmarks and run them to make sure your code performs faster than quick sort for all sizes of _n_.

## STL Sort

Did you know that the `std::sort` function provided by the STL is also a hybrid sort? Most implementations are a _three-way_ hybrid:

1. Quick sort by default.
2. Insertion sort when the partitions get small.
3. Heap sort if the quick sort takes too long due to poor pivoting. (This is called an [_introspective_ sort](https://en.wikipedia.org/wiki/Introsort).)
