# iota
Lazy generation of an integer sequence with almost no effort. Very basic.

In essence you can write,

	for (int i : iota{ 0, 10 })
		std::cout << i << " ";

and get,

  0 1 2 3 4 5 6 7 8 9

or,

	auto res = std::accumulate(iotum{ 0 }, iotum{ 10 }, 0, [](auto l, auto r) { return l + r; });

and get

   45

etc.

iotum is a single pseudo-iterator, iota is a range, a pair of pseudo iterators. They contain ints, but the contained value is a templated type so anything that it makes sense to use can be used. The key is that the dereferenced value is the value, and the increment operator increments that value. At present going backwards, initialising a range to stupid, any other wrongness is not explicitly detected.
