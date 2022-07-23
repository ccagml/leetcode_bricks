default:
	g++ -std=c++11 cpp_guide.cpp -o cpp_guide
	echo "========================================="
	./cpp_guide
	echo "========================================="
	rm -rf cpp_guide
