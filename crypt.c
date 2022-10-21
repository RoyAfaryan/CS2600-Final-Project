#include "crypt.h"
#include "stdio.h"

void crypt(FILE* src, FILE* otp, FILE* dst)
{
	unsigned char srcbuffer[4096];
	unsigned char otpbuffer[4096];
	char* dstbuffer = srcbuffer;

	int qty1;
	int qty2;
	qty1 = fread(srcbuffer, 1, 4096, src);
	qty2 = fread(otpbuffer, 1, 4096, otp);

		for(int i = 0; i < qty1; i++)
		{
			dstbuffer[i] = (srcbuffer[i] ^ otpbuffer[i]);
		}
			fwrite(dstbuffer, 1, qty1, dst);

}          

