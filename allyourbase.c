#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long pow_longlong(int digit, int raiseto)
{
	if (raiseto == 0) return 1;
	else return digit * pow_longlong(digit, raiseto - 1);
}

long long base10_with_map(int base, char* instr, char* digits)
{
	if (base < 2) base = 2;
	long long result = 0;
	int len = strlen(instr);
	int i = 0;
	while (len--)
		result += digits[instr[len]] * pow_longlong(base, i++);
	return result;
}

long long test(char* in)
{
	char appear[256];
	int i;
	int len = strlen(in);
	int hold = 0;
	for (i = 0; i < 256; i++) appear[i] = '\xFF';
	for (i = 0; i < len; i++)
		if (appear[in[i]] == '\xFF')
		{
			if (hold == 0) { appear[in[i]] = 1; hold++; }
			else if (hold == 1) { appear[in[i]] = 0; hold++; }
			else appear[in[i]] = hold++;
		}
	return base10_with_map(hold, in, appear);
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("allyourbase: Usage: %s <input-file> \n", argv[0]);
        return 1;
	}
	char buf[100];
	int a, i;
	FILE* f = fopen(argv[1], "r");
	fscanf(f, "%d", &a);
	long long result;
	for (i = 1; i <= a; i++)
	{
		fscanf(f, "%s", buf);
		result = test(buf);
		printf("Case #%d: %lld\n", i, result);
	}
	return 0;
}

