#include <iostream>
#include "fixedPoint.h"
#include "fixedPoint-iostream.h"

int main() {
	std::cout << "\ntest1\n";
	{
		fixedPoint::Value<0> value1;
		fixedPoint::Value<0> value2(10);
		fixedPoint::Value<0> value3(7);
		fixedPoint::Value<0> value4(-7);

		std::cout << value1 << "\n";
		std::cout << value2 << "\n";
		std::cout << value3 << "\n";
		std::cout << value4 << "\n";
		std::cout << value2+value3 << "\n";
		std::cout << value2+10 << "\n";
		std::cout << 10+value3 << "\n";

		std::cout << value2+value4 << "\n";
		std::cout << value4-10 << "\n";
		std::cout << 10+value4 << "\n";

	}
	std::cout << "\ntest2\n";
	{
		fixedPoint::Value<1> value1;
		fixedPoint::Value<1> value2(10);
		fixedPoint::Value<1> value3(7);

		std::cout << value1 << "\n";
		std::cout << value2 << "\n";
		std::cout << value2+value3 << "\n";
		std::cout << value2+10 << "\n";
		std::cout << 10+value3 << "\n";

		std::cout << value2-value3 << "\n";
		std::cout << value2-10 << "\n";
		std::cout << 10-value3 << "\n";
		std::cout << -value2 << "\n";

	}
	std::cout << "\ntest3\n";
	{
		fixedPoint::Value<1> value1(10);
		std::cout << value1 / 2 << "\n";

		fixedPoint::Value<1> value2(11);
		std::cout << value2 / 2 << "\n";

		fixedPoint::Value<2> value3(11);
		std::cout << value3 / 4 << "\n";

		fixedPoint::Value<20> value4(11);
		std::cout << value4 / 5 << "\n";
	}

	std::cout << "\ntest4\n";
	{
		fixedPoint::Value<1> value1(10), value1_d(2);
		std::cout << value1 * value1_d << "\n";

		fixedPoint::Value<1> value2(11), value2_d(2);
		std::cout << value2 * value2_d << "\n";

		fixedPoint::Value<2> value3(11), value3_d(4), value3_d2(2);
		std::cout << value3 * value3_d << "\n";
		std::cout << value3 * (value3_d2 / 4) << "\n";


		fixedPoint::Value<20> value4(11), value4_d(5);
		std::cout << value4 * value4_d << "\n";
	}


	std::cout << "\ntest5\n";
	{
		fixedPoint::Value<1> value1(10), value1_d(2);
		std::cout << value1 / value1_d << "\n";

		fixedPoint::Value<1> value2(11), value2_d(2);
		std::cout << value2 / value2_d << "\n";

		fixedPoint::Value<2> value3(11), value3_d(4), value3_d2(2);
		std::cout << value3 / value3_d << "\n";
		std::cout << value3 / (value3_d2 / 4) << "\n";


		fixedPoint::Value<20> value4(11), value4_d(5);
		std::cout << value4 / value4_d << "\n";
	}

	std::cout << "\ntest6\n";

	double meanErrorDiv = 0.;
	double meanErrorMul = 0.;
	int ct = 0;
	for (int i(0); i< 100; ++i) {
		float d1 = (rand() / double(RAND_MAX) - 0.5) * 2.;
		float d2 = (rand() / double(RAND_MAX) - 0.5) * 2.;

		constexpr int P = 24;

		auto v1 = fixedPoint::Value<P>::make(d1);
		auto v2 = fixedPoint::Value<P>::make(d2);

//		std::cout << d1 << " " << v1 << "\n";
		auto e1 = d1 * d2;
		auto e2 = v1*v2;
		meanErrorDiv += std::abs(e1 - e2.getValue());
//		std::cout << e1 << " - " << e2 << " " << e1 - e2.getValue() << "\n";

		auto e3 = d1 / d2;
		auto e4 = v1/v2;
		meanErrorMul += std::abs(e3 - e4.getValue());
//		std::cout << e3 << " - " << e4 << " " << e3 - e4.getValue() << "\n";
		ct += 1;
	}
	std::cout << "meanErrorDiv: " << meanErrorDiv / ct << ", meanErrorMul: " << meanErrorMul / ct << "\n";



}
