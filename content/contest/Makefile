CXXFLAGS = -Wall -Wextra -Wformat=2 -Dmypity
CXXFLAGS += -fsanitize=address,undefined -g
# CXXFLAGS += -ggdb
# CXXFLAGS += -O3 -march=native

%.exe: %.cpp
	g++ $< -o $@ ${CXXFLAGS}
