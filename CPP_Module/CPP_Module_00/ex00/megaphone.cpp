#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < argc; i++)
		{
			for (j = 0; argv[i][j]; j++)
				std::cout << static_cast<char>(toupper(argv[i][j]));
		}
		std::cout << std::endl;
	}
}
