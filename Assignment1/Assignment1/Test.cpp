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
	system("pause");
	cout << "\nExpected Values: \n " << 0.3175 << "\n" << 0.3175 << "\n" << 0.3175 << "\n" << 0.476 << endl;
}