#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define BYTE_LENGTH CHAR_BIT
#define FLT_LENGTH (sizeof(float) * BYTE_LENGTH)
#define DBL_LENGTH (sizeof(double) * BYTE_LENGTH)

#define Bit unsigned char
#define Byte unsigned char

void toBitArray(void* buffer, unsigned int length, void* dest)
{
	Byte* p_buffer = (Byte*)buffer;
	Bit* p_dest = (Bit*)dest;
	int c = 0, i = 0;
	for (c = (int)length - 1; c >= 0; c--)
	{
		for (i = (int)BYTE_LENGTH - 1; i >= 0; i--)
		{
			p_dest[(length - c) * BYTE_LENGTH - i - 1] = ((p_buffer[c] >> i) & 0x1);
		}
	}
}

#define printBinary(value, type) \
{ \
	const unsigned int LENGHT = sizeof(type) * BYTE_LENGTH; \
	Byte* bits = (Byte*)malloc(LENGHT); \
	type v = (value); \
	toBitArray((void*)& v, sizeof(type), (void*)bits); \
	unsigned int i = 0; \
	for (i = 0; i < LENGHT; i++) \
	{ \
		if (i % 4 == 0 && i != 0) printf(" "); \
		printf("%u", bits[i]); \
	} \
	printf("\n"); \
	free(bits); \
}

int main(void) // `void` shouldn't be omitted!
{
	printBinary(1.0 / 8.0, float);
	printBinary(-1.0 / 8.0, float);
	printBinary(0.375, float);
	printBinary(-11.625, float);
	printBinary(-11.625, double);

	system("pause");

	return 0;
}

// At the end of a file, leave an empty line PLEASE!
