#include <cstdint>
#include <iostream>
#include <bitset>

int main()
{
	constexpr std::bitset<8> mask0{ 0b0000'0001 }; // represents bit 0
	constexpr std::bitset<8> mask1{ 0b0000'0010 }; // represents bit 1
	constexpr std::bitset<8> mask2{ 0b0000'0100 }; // represents bit 2 
	constexpr std::bitset<8> mask3{ 0b0000'1000 }; // represents bit 3
	constexpr std::bitset<8> mask4{ 0b0001'0000 }; // represents bit 4
	constexpr std::bitset<8> mask5{ 0b0010'0000 }; // represents bit 5
	constexpr std::bitset<8> mask6{ 0b0100'0000 }; // represents bit 6
	constexpr std::bitset<8> mask7{ 0b1000'0000 }; // represents bit 7

	std::bitset<8> flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
	flags ^= (mask1 | mask2); // flip bits 1 and 2

	flags ^= mask3;

	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
	flags |= (mask1 | mask2); // turn bits 1 and 2 on

	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
	flags &= ~(mask1 | mask2); // turn bits 1 and 2 off

	std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
	std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

	if ((flags & mask0) == 0)
		std::cout << "mask0 is NOT set" << std::endl;
	else
		std::cout << "mask0 is set" << std::endl;

	return 0;
}