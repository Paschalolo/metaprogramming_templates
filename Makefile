MFILE = $(FILE).cpp
GCC = g++-14
GCCFLAGS = -Wall -Wextra -Werror -Wpedantic -Wnull-dereference  -Wshadow -Wconversion -Wduplicated-branches -Wlogical-op -O3  -Wformat=2   -pthread 
C23 = -std=c++23
INCLUDES = -I includes -I src 
COMPILE.c = $(GCC) $(GCCFLAGS) $(INCLUDES) $(C23)
OBJ_DIR = src
OBJS = $(wildcard $(OBJ_DIR)/*.o)
vpath %.c src 
vpath %.cc src 
vpath %.cpp src 
vpath %.h includes 

run : $(MFILE) $(HARGS)
	$(COMPILE.c) $<  -o bin && ./bin 
exec : $(OBJS) 
	$(COMPILE.c) $(OBJS)  -o bin && ./bin  	
object : $(MFILE) $(HARGS)
	$(COMPILE.c) -c  $< -o ./src/$(FILE).o

oshared: $(MFILE) $(HARGS)
	$(COMPILE.c) -fPIC -c  $< -o ./src/$(FILE).o
create: 
	touch src/$(MFILE)
push : 
	git add . && git commit -m"message " && git push origin main 
