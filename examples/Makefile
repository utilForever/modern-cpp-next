LDFLAGS		= -lc++
CXXFLAGS	= -std=c++2a -fmodules-ts

m1.ifc: modules_p1_2.cpp
	clang $(CXXFLAGS) -x c++-module \
		 --precompile -o m1.ifc $?

m1_impl_1.o: m1.ifc modules_p1_3.cpp
	clang $(CXXFLAGS) \
		-fprebuilt-module-path=/usr/local/include \
		-fprebuilt-module-path=. \
		-fmodule-file=m1.ifc -o m1_impl_1.o -c modules_p1_3.cpp

m1_usage: m1_impl_1.o modules_p1_5.cpp
	clang $(CXXFLAGS) $(LDFLAGS) \
		-fmodule-file=m1.ifc $?


