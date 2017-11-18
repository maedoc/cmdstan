#include <math.h>
#include <stdio.h>
#include <unistd.h>

int scan_one(char *fmt, FILE *out) {
	double num = NAN;
	int c = scanf(fmt, &num);
	if (c > 0) fwrite(&num, sizeof(double), 1, out);
	return c;
}

int main () {
	FILE *const out = fdopen(dup(fileno(stdout)), "wb");
	if (scan_one("%lf", out))
		while (scan_one(",%lf", out)) { }
	fclose(out);
	return 0;
}
