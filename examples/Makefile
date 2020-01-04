CFLAGS 	= -std=c++2a -fmodules-ts
LDFLAGS	= -lstdc++

next_part_1: module_part_1.cpp
	clang-9 $(CFLAGS) $(LDFLAGS) \
		-o module_part_1.o -c $?

next_impl_1: module_impl_1.cpp
	clang-9 $(CFLAGS) $(LDFLAGS) \
		-o next_impl.o -c $?

next.pcm:
	clang-9 $(LDFLAGS) $(CFLAGS) \
		-o next.pcm \
		--precompile -x c++-module module_ifc.cpp

next_impl_2: module_impl_2.cpp
	make next.pcm
	clang-9 $(CFLAGS) $(LDFLAGS) \
	 	-fmodule-file=next.pcm \
		-o next_impl_2.o -c $?
	nm ./next_impl_2.o

	clang-9 $(CFLAGS) $(LDFLAGS) \
		-o main.o -c main.cpp \
		-fprebuilt-module-path=. \
		-fmodule-file=next.pcm
	clang-9 $(CFLAGS) $(LDFLAGS) \
		-o main main.o next_impl_2.o
	nm --demangle ./main | grep endpoint_t 

# main: next.o
# 	clang-9 -o main.o $(CFLAGS) $(LDFLAGS) \
# 		-fprebuilt-module-path=. \
# 		-fmodule-file=next.pcm \
# 		-c main.cpp 
# 	clang-9 -o $@ $(LDFLAGS) \
# 		main.o $? 

clean:
	rm next_impl.o || true
	rm next.pcm next_impl_2.o  || true
	rm main main.o  || true
