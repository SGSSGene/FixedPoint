#pragma once

#include <iostream>

namespace fixedPoint {

template <int point, typename T>
std::ostream& operator<< (std::ostream& stream, Value<point, T> const& value) {
	stream << value.getValue();
	return stream;
}

}
