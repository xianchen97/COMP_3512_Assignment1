#include "PageRank.hpp"

int main() {
	using std::cout;	
	using std::endl;
	Matrix ab = Matrix("c:\\test.txt");
	PageRank a = PageRank("c:\\test.txt");
	a.importance();
	a.print_prob_matrix();
	a.generateQ();
	cout << "\n";
	a.print_matrix_Q(); 
	a.transition();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();

	a.multiply();
	a.multiply();
	a.multiply();

	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	a.multiply();
	system("pause");
	a.multiply();
}