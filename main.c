#include "crypt.h"
#include "stdio.h"
#include "stdlib.h"

void crypt(FILE* src, FILE* otp, FILE* dst);

int main()
{

	char srcfilename[16];
	char otpfilename[16];
	char dstfilename[16];
	FILE* src;
	FILE* otp;
	FILE* dst;


	printf("%s", "Please enter a source file, one-time-pad file, and an destination file.\n");
	
	printf("%s", "Source File: ");
	scanf("%s", srcfilename);
	if(!(src = fopen(srcfilename, "r"))){
		printf("%s", "Failed to open file. \n");
		exit(-1);
	}
	printf("\n");

	printf("%s", "One-time-pad file: ");
	scanf("%s", otpfilename);
	if(!(otp = fopen(otpfilename, "r"))){
		printf("%s", "Failed to open file. \n");
		exit(-1);
	}
	printf("\n");

	printf("%s", "Destination file: ");
	scanf("%s", dstfilename);
	if(!(dst = fopen(dstfilename, "w"))){
		printf("%s", "Failed to open file. \n");
		exit(-1);
	}
	printf("\n");

	crypt(src, otp, dst);
	
	fclose(src);
	fclose(otp);
	fclose(dst);
}
