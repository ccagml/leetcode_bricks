default:
	g++ -std=c++11 quick_start.cpp -o quick_start
	echo "========================================="
	./quick_start
	echo "========================================="
	rm -rf quick_start
