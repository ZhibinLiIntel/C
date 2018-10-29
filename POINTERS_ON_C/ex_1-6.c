/* The statments
 * if (num % 2 != 0) {
 * 	...
 * }
 * in function read_column_numbers are removed.
 * And function rearrange is modified as below:
 */

void rearrange(char *output, const char *input,
	       int n_columns, /* const */ int columns[])
{
	int col;
	int output_col;
	int len;

	len = strlen(input);
	output_col = 0;

	if (n_columns % 2 != 0) {
		columns[n_columns] = len;
	}

	/* The following codes are remained unmodified. */
	/* ... */
}
