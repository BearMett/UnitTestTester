TARGET_EXEC := sum_runner

BUILD_DIR  := ./bin
OBJ_DIR := ./obj
SRC_DIRS := ./src


INC_DIRS := ./include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LIB_DIRS := 
LDFALGS := 

CPPFLAGS := $(INC_FLAGS) -MMD -MP

CXX = g++
CXXFLAGS = -g

SRC := src/main.cpp \
src/sum.cpp

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(BUILD_DIR)/$(TARGET_EXEC)

$(OBJS): $(OBJ_DIR)/%.o: %.cpp
	echo $(OBJS)
	echo --------
	echo $(SRC)
	echo --------
	$(CXX) -c $(CXXFLAGS) $(INC_FLAGS) $< -MD -o $@ $(LDFALGS)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) $(INC_FLAGS) -o $@ $(LDFALGS) 


.PHONY: clean
clean:
	rm -f $(OBJS) $(BUILD_DIR)/$(TARGET_EXEC) $(DEPS)

-include $(DEPS)