#include <iostream>

int main(int argc, char * argv[])
{
	uint32_t first = 1, second = 2, fibonacci = 0, sum = 2;
	
	while (fibonacci < 4000000)
	{
		fibonacci = first + second;
		if (fibonacci % 2 == 0) sum += fibonacci;
		first = second;
		second = fibonacci;
	}
	std::cout << "Sum = " << sum << std::endl;
	
	return 0;
}