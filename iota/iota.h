#pragma once

// iota.h
//
// iterators that act like values
//

namespace epicyclism
{
	template<typename V> class iotum_base
	{
	public:
		using value_type = V;
	private:
		V val_;
	public:
		constexpr iotum_base ( V v) : val_(v)
		{}
		constexpr V& operator++()
		{
			++val_;
			return val_;
		}
		constexpr V operator++(int)
		{
			V v(val_);
			++val_;
			return v;
		}
		constexpr V& operator--()
		{
			--val_;
			return val_;
		}
		constexpr V operator--(int)
		{
			V v(val_);
			--val_;
			return v;
		}
		constexpr V operator*() const
		{
			return val_;
		}
		constexpr operator V() const
		{
			return val_;
		}
	};
	template<typename V> constexpr bool operator != (iotum_base<V> const& l, iotum_base<V> const& r)
	{
		return static_cast<V>(l) != static_cast<V>(r);
	}
	template<typename V> constexpr bool operator < (iotum_base<V> const& l, iotum_base<V> const& r)
	{
		return static_cast<V>(l) < static_cast<V>(r);
	}
	template<typename V> class iota_base
	{
	public:
		using value_type = V;
	private:
		iotum_base<V> begin_;
		iotum_base<V> end_;
	public:
		iota_base ( V begin, V end) : begin_(begin), end_(end)
		{}
		constexpr iotum_base<V> begin() const
		{
			return begin_;
		}
		constexpr iotum_base<V> end() const
		{
			return end_;
		}
	};

	using iotum = iotum_base<int>;
	using iota = iota_base<int>;
}