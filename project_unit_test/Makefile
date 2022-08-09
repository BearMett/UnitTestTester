TARGET_EXEC := sum_runner

BUILD_DIR  := ./bin
OBJ_DIR := ./obj
SRC_DIRS := ./src


INC_DIRS := ./include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LIB_DIRS := 
LDFALGS := 

CPPFLAGS := $(INC_FLAGS) -MMD -MP

TEST_DIR := ./test
TEST_INC_DIR := $(INC_DIRS) $(TEST_DIR)/include
TEST_INC_FLAGS := $(addprefix -I,$(TEST_INC_DIR))
TEST_CC := $(TEST_DIR)/sum_test.cc
TEST_CC_OBJ := $(TEST_CC:.cc=.o)
TEST_CC_DEPS := $(TEST_CC_OBJ:.o=.d)
TEST_SRC := src/sum.cpp
TEST_OBJ :=  $(TEST_SRC:.cpp=.o)
TEST_DEPS = $(TEST_OBJ:.o=.d)
TEST_LIB_DIR := $(TEST_DIR)/lib/
TEST_LIB := -lgtest -lpthread
TEST_TARGET_EXEC := sum_test_run

CXX = g++
CXXFLAGS = -g

SRC := src/main.cpp \
src/sum.cpp

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) $(INC_FLAGS) -o $@ $(LDFALGS) 

$(OBJS): $(OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INC_FLAGS) $< -MD -o $@ $(LDFALGS)

test: $(TEST_DIR)/$(TEST_TARGET_EXEC)

$(TEST_DIR)/$(TEST_TARGET_EXEC): $(TEST_OBJ) $(TEST_CC_OBJ)
	$(CXX) $(TEST_CC_OBJ) $(TEST_OBJ) $(TEST_INC_FLAGS) -L$(TEST_LIB_DIR) $(TEST_LIB) $(LDFALGS) -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CXX) -c -g $(CXXFLAGS) $(TEST_INC_FLAGS) $< -MD -o $@ $(LDFALGS)

$(TEST_CC_OBJ): $(TEST_CC)
	$(CXX) -c -g $(CXXFLAGS) $(TEST_INC_FLAGS) $< -MD -o $@ $(LDFALGS)


.PHONY: clean
clean:
	rm -f $(OBJS) $(BUILD_DIR)/$(TARGET_EXEC) $(DEPS) $(TEST_DIR)/$(TEST_TARGET_EXEC) $(TEST_OBJ) $(TEST_DEPS) $(TEST_CC_OBJ) $(TEST_CC_DEPS)

-include $(DEPS)
