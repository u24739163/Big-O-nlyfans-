
filesToDelete = main pizzaComponent pizza
filesToCompile = main.cpp pizzaComponent.cpp pizza.cpp
filesInCoverageReport = main pizzaComponent pizza

main:
	g++ -g -std=c++11 ${filesToCompile} -o main

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt -f ${filesToDelete}

coverage:
	make clean
	g++ -g --coverage -dumpbase '' ${filesToCompile} -o main
	./main > outputXD.txt
	gcov -f -m -r -j ${filesInCoverageReport} > coverage.txt 
	gcovr --html-details output.html
	#make clean

valgrind:
	make clean
	make
	valgrind --track-origins=yes --leak-check=full --keep-stacktraces=alloc-and-free --error-exitcode=1 --log-file=valgrind.txt ./main > output.txt
