# Setting $PYTHONPATH
export PYTHONPATH=/home/daniel/Documents/snookerAST/

# Object files to either reference or create                          
OBJECTS =  main.cpp snooker.cpp         

# The execuoable file that will be created at the end                 
EXEC = ast.out                                                      

# The flags to use for compilation                                    
FLAGS = -Wall -lpython3.6m -Irapidjson                                                         
# The code compiler to use for compilation                            
CC = g++                                                              

# Perform action on all object files (May or may not exist)           
all: $(OBJECTS)                                                       
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)
