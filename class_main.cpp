#include "./parseJSON.h"

int main(int argc, char *argv[])
{
	parseJSON sample;

	sample.readFile(fopen(argv[1], "r"));
	sample.print_all();
	sample.fill_all();
	sample.print_root_vector();
}