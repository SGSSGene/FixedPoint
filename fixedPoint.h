#pragma once

#include <cstdint>
#include <complex>

namespace fixedPoint {
	template <int shift, typename T = int32_t, typename T2 = int64_t>
	class Value {
		T value{0};

		template<int _shift2, typename _T, typename _T2>
		friend class Value;
	public:
		Value() {}

		Value(T v) {
			value = (v << shift);
		}


		template <typename RT>
		static auto make(RT _v) -> Value {
			Value v;
			v.value = _v * (1<<shift);
			return v;
		}

		auto operator+(Value const& _other) const -> Value {
			Value v;
			v.value = value + _other.value;
			return v;
		}
		auto operator-(Value const& _other) const -> Value {
			Value v;
			v.value = value - _other.value;
			return v;
		}

		auto operator+=(Value const& _other) -> Value& {
			value += _other.value;
			return *this;
		}
		auto operator-=(Value const& _other) -> Value& {
			value -= _other.value;
			return *this;
		}
		auto operator-() -> Value {
			Value v;
			v.value = -value;
			return v;
		}

		auto operator*(Value const& _other) const -> Value {
			Value v;
			v.value = (T2(value) * T2(_other.value)) >> shift;
			return v;
		}
		auto operator*(T _other) const -> Value {
			Value v;
			v.value = value * _other;
			return v;
		}

		auto operator/(Value const& _other) const -> Value {
			Value v;
			v.value = (T2(value)<<shift) / T2(_other.value);
			return v;
		}

		auto operator/(T _other) const -> Value {
			Value v;
			v.value = value / _other;
			return v;
		}

		auto getValue() const -> float {
			return double(value) / (1<<shift);
		}
	};

	template <int shift, typename T>
	auto operator+(int _a, Value<shift, T> _b) -> Value<shift, T> {
		return _b + _a;
	}
	template <int shift, typename T>
	auto operator-(int _a, Value<shift, T> _b) -> Value<shift, T> {
		return -_b + _a;
	}


}
