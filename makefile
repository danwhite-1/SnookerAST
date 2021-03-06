# Object files to either reference or create                          
OBJECTS =  main.cpp snookerUtils.cpp snookerMatch.cpp        

# The execuoable file that will be created at the end                 
EXEC = ast.out                                                      

# The flags to use for compilation                                    

FLAGS = -Wall -I/usr/include/python3.8                                                        
# The code compiler to use for compilation                            
CC = g++                                                              

# Perform action on all object files (May or may not exist)           
all: $(OBJECTS)                                                       
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS) -lpython3.8
