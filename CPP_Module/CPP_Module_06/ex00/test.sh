#! /bin/bash

### echo -e "\n\033[31m""출력할 문자""\033[0m"
### 31(빨강), 32(초록), 33(노랑), 34(파랑), 35(보라), 36(하늘)

## default
echo -e "\033[31m""[ default Test ]""\033[0m"
echo -e "\033[36m""./convert 0""\033[0m"
./convert 0
echo -e "\033[36m""./convert -inff""\033[0m"
./convert -inff
echo -e "\033[36m""./convert +inff""\033[0m"
./convert +inff
echo -e "\033[36m""./convert nanf""\033[0m"
./convert nanf
echo -e "\033[36m""./convert -inf""\033[0m"
./convert -inf
echo -e "\033[36m""./convert +inf""\033[0m"
./convert +inf
echo -e "\033[36m""./convert nan""\033[0m"
./convert nan
echo -e "\033[36m""./convert 42.0f""\033[0m"
./convert 42.0f

# zero
echo -e "\033[31m""[ zero Test ]""\033[0m"
echo -e "\033[36m""./convert 0""\033[0m"
./convert 0
echo -e "\033[36m""./convert 0.""\033[0m"
./convert 0.
echo -e "\033[36m""./convert 0.f""\033[0m"
./convert 0.f
echo -e "\033[36m""./convert 0.0f""\033[0m"
./convert 0.0f
echo -e "\033[36m""./convert .0""\033[0m"
./convert .0
echo -e "\033[36m""./convert .0f""\033[0m"
./convert .0f

## max min
echo -e "\033[31m""[ min max Test ]""\033[0m"
echo -e "\033[36m""./convert -129""\033[0m"
./convert -129
echo -e "\033[36m""./convert -128""\033[0m"
./convert -128
echo -e "\033[36m""./convert 127""\033[0m"
./convert 127
echo -e "\033[36m""./convert 128""\033[0m"
./convert 128
echo -e "\033[36m""./convert -2147483649""\033[0m"
./convert -2147483649
echo -e "\033[36m""./convert -2147483648""\033[0m"
./convert -2147483648
echo -e "\033[36m""./convert 2147483647""\033[0m"
./convert 2147483647
echo -e "\033[36m""./convert 2147483648""\033[0m"
./convert 2147483648


## remain
echo -e "\033[31m""[ remain Test ]""\033[0m"
echo -e "\033[36m""./convert -123asafs""\033[0m"
./convert -123asafs
echo -e "\033[36m""./convert -123.12312312312""\033[0m"
./convert -123.12312312312
echo -e "\033[36m""./convert 123.12312312312""\033[0m"
./convert 123.12312312312
echo -e "\033[36m""./convert 123123.12312312312""\033[0m"
./convert 123123.12312312312
echo -e "\033[36m""./convert 1231231.12312312312""\033[0m"
./convert 1231231.12312312312
echo -e "\033[36m""./convert 0.12312312312""\033[0m"
./convert 0.12312312312
echo -e "\033[36m""./convert 12.12312312312""\033[0m"
./convert 12.12312312312
echo -e "\033[36m""./convert 96.12312312312""\033[0m"
./convert 96.12312312312


# ## ascii
echo -e "\033[31m""[ ascii Test ]""\033[0m"
for var in {0..127}
do
	echo -e "\033[36m""./convert $var""\033[0m"
	./convert $var
done