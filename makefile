CXX := g++
CPPFLAGS :=
CXXFLAGS := -std=c++17 -Wall -Og -g

SRCS := ku.cc main.cc
OBJS := $(SRCS:.cc=.o)
DEPS := $(SRCS:.cc=.d)

all: ku

%.o: %.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $< -MT $@ > $*.d

ku: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o ku

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

distclean: clean
	rm -rf ku


