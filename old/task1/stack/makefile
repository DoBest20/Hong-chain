CC=../../../AFLplusplus/afl-clang++
FZ=../../../AFLplusplus/afl-fuzz


# variables
INCLUDE_PATH ?= 
LIB_PATH ?= 
LIB_NAME ?= 
STUDENT_PATH ?= 


# make solution execution file
solution:
ifeq ($(INCLUDE_PATH),)	# INCLUDE_PATH is empty
ifeq ($(LIB_NAME),)	# LIB_NAME is also empty
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp solution.cpp -o solution.out
else	# INCLUDE_PATH is empty, but LIB_NAME is defiend
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp solution.cpp -L$(LIB_PATH) -l$(patsubst lib%.a,%,$(LIB_NAME)) -o solution.out
endif
else ifeq ($(LIB_NAME),)	# INCLUDE_PATH is defiend, but LIB_NAME is empty
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp solution.cpp -I$(INCLUDE_PATH) -o solution.out
else	# INCLUDE_PATH and LIB_NAME are defiend
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp solution.cpp -I$(INCLUDE_PATH) -L$(LIB_PATH) -l$(patsubst lib%.a,%,$(LIB_NAME)) -o solution.out
endif

#	$(CC) -std=c++11 test_driver.cpp solution.cpp -I../include -L../lib -lnowic_linux -o solution
# make solution INCLUDE_PATH=../include LIB_PATH=../lib LIB_NAME=libnowic_db.a 


# make submission execution file
submission:
ifeq ($(INCLUDE_PATH),)	# INCLUDE_PATH is empty
ifeq ($(LIB_NAME),)	# LIB_NAME is also empty
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp $(STUDENT_PATH)/submission.cpp -o $(STUDENT_PATH)/submission
else	# INCLUDE_PATH is empty, but LIB_NAME is defiend
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp $(STUDENT_PATH)/submission.cpp -L$(LIB_PATH) -l$(patsubst lib%.a,%,$(LIB_NAME)) -o $(STUDENT_PATH)/submission
endif
else ifeq ($(LIB_NAME),)	# INCLUDE_PATH is defiend, but LIB_NAME is empty
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp  $(STUDENT_PATH)/submission.cpp -I$(INCLUDE_PATH) -o $(STUDENT_PATH)/submission
else	# INCLUDE_PATH and LIB_NAME are defiend
	AFL_USE_ASAN=1 $(CC) -std=c++11 test_driver.cpp  $(STUDENT_PATH)/submission.cppp -I$(INCLUDE_PATH) -L$(LIB_PATH) -l$(patsubst lib%.a,%,$(LIB_NAME)) -o $(STUDENT_PATH)/submission
endif

# $(CC) -std=c++11 test_driver.cpp submission.cpp -I../include -L../lib -lnowic_linux -o submission
# make submission INCLUDE_PATH=../include LIB_PATH=../lib LIB_NAME=libnowic_db.a 


# solution file fuzzing
f_solution: 
	mkdir -p outputs/solution
	$(FZ) -i $(SEED_DIR) -o outputs/solution ./solution

# AFL_NO_AFFINITY=1 make f_solution SEED_DIR=inputs -a text


# submission file fuzzing
f_submission: 
	mkdir -p outputs/submission
	$(FZ) -i $(SEED_DIR) -o outputs/submission ./submission

# AFL_NO_AFFINITY=1 make f_submission SEED_DIR=inputs	


clean:
	rm -rf outputs
	rm submission solution 



