#include <iostream>
#include <fstream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
//
// virtual prototype
//
class Machine{
	public:
		virtual Machine* clone() = 0;
		// prints a message to help the user use the machine properly
		virtual int help() = 0;
		// allows user to serialize the machine
		virtual int SaveMachine() = 0;
};
//
// concrete machine class - treadmill
//
class Treadmill : public Machine{
	public:
		Machine* clone(){
			return new Treadmill;
		}
		//
		//helps user by printing message on how to use machine
		//
		int help(){
			std::cout << "-press start, and begin running-\n"; 
			return 1;
		}
		//
		//serializes the machine, this function is not completed
		//
		int  SaveMachine(){
			std::cout << "Treadmill has not been saved because not implemented yet\n"; 
			return 0;
		}
};

// concrete machine class - rower
class Row : public Machine{
	public:
		Machine* clone(){
			return new Row;
		}
		//
		//helps user by printing message on how to use machine
		//
		int help(){
			std::cout << "-pull on the handle, using legs, back, and arms-\n"; 
			return 1;
		}
		//
		//serializes the machine, this function is not completed
		//
		int SaveMachine(){
			std::cout << "Row has not been saved because not implemented yet\n"; 
			return 0;
		}
};

// takes in a number, and returns the concrete machine
class MachineFactory {
	public:
		static Machine* make_machine(int selection);
	private:
		static Machine* machine_prototypes[2];
};

// tests return values of the concrete machines
void runTests(){
	// test the treadmill machine
	Machine* machine1;
	machine1 = MachineFactory::make_machine(0);
	if(machine1->help() == 1){
		printf("machine1->help(): " ANSI_COLOR_GREEN "worked" ANSI_COLOR_RESET "\n\n");
	}
	else{
		printf("machine1->help(): " ANSI_COLOR_RED "error" ANSI_COLOR_RESET "\n\n");
	}

	if(machine1->SaveMachine() == 1){
		printf("machine1->SaveMachine(): " ANSI_COLOR_GREEN "worked" ANSI_COLOR_RESET "\n\n");
	}
	else{
		printf("machine1->SaveMachine(): " ANSI_COLOR_RED "error" ANSI_COLOR_RESET "\n\n");
	}

	// test the row machine
	Machine* machine2;
	machine2 = MachineFactory::make_machine(0);
	if(machine2->help() == 1){
		printf("machine2->help(): " ANSI_COLOR_GREEN "worked" ANSI_COLOR_RESET "\n\n");
	}
	else{
		printf("machine2->help(): " ANSI_COLOR_RED "error" ANSI_COLOR_RESET "\n\n");
	}

	if(machine2->SaveMachine() == 1){
		printf("machine2->SaveMachine(): " ANSI_COLOR_GREEN "worked" ANSI_COLOR_RESET "\n\n");
	}
	else{
		printf("machine2->SaveMachine(): " ANSI_COLOR_RED "error" ANSI_COLOR_RESET "\n\n");
	}
}


int main(){
	int selection;
	
	Machine* machine;
	
	std::cout << "Welcome to the gym prototypePattern application\n";
	while(1){
		// ask user for their choice
		std::cout << "\nselect a number corresponding to the command\n0) create Treadmill \n1) create Row machine\n2) exit\n3) run tests and exit\n";
		std::cin >> selection;
		std::cout << "\n";
		
		if(selection == 0){
			machine = MachineFactory::make_machine(selection);
			machine->help();
		}
		else if(selection == 1){
			machine = MachineFactory::make_machine(selection);
			machine->help();
		}
		else if(selection == 2){
			break;
		}
		else if(selection == 3){
			runTests();
			return 1;
		}
		else{
			std::cout << "unknown command, try again\n";
		}
		
	}
}

Machine* MachineFactory::machine_prototypes[] = {new Treadmill, new Row};

Machine* MachineFactory::make_machine(int selection){
	return machine_prototypes[selection]->clone();
}