#include "PageRank.hpp"

int main() {
	using std::cout;	
	using std::endl;

	PageRank a = PageRank("c:\\test.txt");
	a.importance();
	a.print_prob_matrix();
	a.generateQ();
	cout << "\n";
	a.print_matrix_Q(); 
	a.transition();
	a.multiply();
	a.print_dynamical();
	a.print_percent();
	cout << "\nExpected Values: \n " << 0.3175 << "\n" << 0.3175 << "\n" << 0.3175 << "\n" << 0.476 << endl;

	PageRank b = PageRank("c:\\test2.txt");
	b.importance();
	b.print_prob_matrix();
	b.generateQ();
	cout << "\n";
	b.print_matrix_Q();
	b.transition();
	b.multiply();
	b.print_dynamical();
	b.print_percent();
	cout << "\nExpected Values: \n " << 0.130816 << "\n" << 0.268108 << "\n" << 0.018188 << "\n" << 0.054727 << "\n" << 0.108890
		<< "\n" << 0.079365 << "\n" << 0.128962 << "\n" << 0.015000 << "\n" << 0.123972 << "\n" << 0.071973 << "\n" << endl;
	system("pause");
}