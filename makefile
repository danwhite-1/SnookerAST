# Setting $PYTHONPATH
export PYTHONPATH = $PWD

# Object files to either reference or create                          
OBJECTS =  snooker.cpp          

# The execuoable file that will be created at the end                 
EXEC = ast.out                                                      

# The flags to use for compilation                                    
FLAGS = -Wall -lpython3.6m                                                         
# The code compiler to use for compilation                            
CC = g++                                                              

# Perform action on all object files (May or may not exist)           
all: $(OBJECTS)                                                       
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)
