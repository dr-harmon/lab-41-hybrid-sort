#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "insertion_sort.h"
#include "quick_sort.h"
#include "hybrid_sort.h"

#include <algorithm>

using namespace std;

// Generates a sequence of integers (1..size) in reverse order
vector<int> makeReverseVector(int size)
{
	vector<int> v(size);
	generate(v.begin(), v.end(), [&size]{ return size--;});
	return v;
}

// Generates a sequence of integers (1..size) in sorted order
vector<int> makeSortedVector(int size)
{
	vector<int> v(size);
    int i = 1;
	generate(v.begin(), v.end(), [&i]{ return i++;});
	return v;
}

TEST_CASE("Insertion sort")
{
	vector<int> v;
	
	v = {};
	insertionSort(v);
	REQUIRE(v == vector<int> {});

	v = {1};
	insertionSort(v);
	REQUIRE(v == vector<int> {1});

	v = {4, 3, 2, 1};
	insertionSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4});

	v = {5, 4, 3, 2, 1};
	insertionSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

	v = {1, 2, 3, 4, 5};
	insertionSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

    // SMALL VECTORS

    BENCHMARK_ADVANCED("Insertion sort (8)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(8);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (16)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(16);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (32)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(32);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (64)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(64);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (128)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(128);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (256)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(256);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (512)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(512);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

/*
    // LARGE VECTORS

    BENCHMARK_ADVANCED("Insertion sort (1k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(1000);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (2k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(2000);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (3k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(3000);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (4k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(4000);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Insertion sort (5k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(5000);
        meter.measure([&v] {
            insertionSort(v);
			return v;
        });
    };
*/
}

TEST_CASE("Quick sort")
{
	vector<int> v;
	
	v = {};
	quickSort(v);
	REQUIRE(v == vector<int> {});

	v = {1};
	quickSort(v);
	REQUIRE(v == vector<int> {1});

	v = {4, 3, 2, 1};
	quickSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4});

	v = {5, 4, 3, 2, 1};
	quickSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

	v = {1, 2, 3, 4, 5};
	quickSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

    // SMALL VECTORS

    BENCHMARK_ADVANCED("Quick sort (8)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(8);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (16)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(16);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (32)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(32);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (64)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(64);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (128)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(128);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (256)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(256);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (512)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(512);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

/*
    // LARGE VECTORS

    BENCHMARK_ADVANCED("Quick sort (1k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(1000);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (2k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(2000);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (3k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(3000);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (4k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(4000);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (5k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(5000);
        meter.measure([&v] {
            quickSort(v);
			return v;
        });
    };
*/
}

/*
TEST_CASE("Hybrid sort")
{
	vector<int> v;
	
	v = {};
	hybridSort(v);
	REQUIRE(v == vector<int> {});

	v = {1};
	hybridSort(v);
	REQUIRE(v == vector<int> {1});

	v = {4, 3, 2, 1};
	hybridSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4});

	v = {5, 4, 3, 2, 1};
	hybridSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

	v = {1, 2, 3, 4, 5};
	hybridSort(v);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

    v = makeReverseVector(1000);
    hybridSort(v);
    REQUIRE(v == makeSortedVector(1000));

    // LARGE VECTORS

    BENCHMARK_ADVANCED("Hybrid sort (1k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(1000);
        meter.measure([&v] {
            hybridSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Hybrid sort (2k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(2000);
        meter.measure([&v] {
            hybridSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Hybrid sort (3k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(3000);
        meter.measure([&v] {
            hybridSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Hybrid sort (4k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(4000);
        meter.measure([&v] {
            hybridSort(v);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Hybrid sort (5k)")(Catch::Benchmark::Chronometer meter) {
        vector<int> v = makeReverseVector(5000);
        meter.measure([&v] {
            hybridSort(v);
			return v;
        });
    };
}
*/
