#include "PageRank.hpp"

int main() {
	using std::cout;	
	using std::endl;
	Matrix ab = Matrix("c:\\test.txt");
	PageRank a = PageRank("c:\\test.txt");
	a.importance();
	a.print_prob_matrix();
	system("pause");
	
}