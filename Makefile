# Fill in two variables

# Name for project
program_NAME := project5
# Files needed for webcat
webcat_files := Date.h Date.cpp ToDo.h ToDo.cpp ToDoList.h ToDoList.cpp


program_CXX_SRCS := $(wildcard *.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
CXX = clang++

CXXFLAGS += -g -O0 -Wall -Wextra

.PHONY: all clean webcat debug

all: $(program_NAME)

$(program_NAME): $(program_CXX_OBJS)
	$(CXX) $(CXXFLAGS) $(program_CXX_OBJS) -o $(program_NAME)

clean:
	@- rm -f $(program_NAME)
	@- rm -f $(program_CXX_OBJS)
	@- rm -f $(program_NAME)*.zip
	@- rm -rf $(program_NAME).dSYM

webcat: $(program_NAME)
	zip -X -r $(program_NAME).zip $(webcat_files)
	
debug: $(program_NAME)
	dsymutil $(program_NAME)

