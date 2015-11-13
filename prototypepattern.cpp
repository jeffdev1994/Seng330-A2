#include <iostream>
#include <fstream>

// virtual prototype
class Machine{
	public:
		virtual Machine* clone() = 0;
		
		virtual void help() = 0;
		virtual void SaveMachine() = 0;
};

// concrete machine class
class Treadmill : public Machine{
	public:
		Machine* clone(){
			return new Treadmill;
		}
		
		void help(){
			std::cout << "-press start, and begin running-\n"; 
		}
		
		void SaveMachine(){
			std::cout << "Treadmill has not been saved because not implemented yet\n"; 
		}
};

// concrete machine class
class Row : public Machine{
	public:
		Machine* clone(){
			return new Row;
		}
		
		void help(){
			std::cout << "-pull on the handle, using legs, back, and arms-\n"; 
		}
		
		void SaveMachine(){
			std::cout << "Row has not been saved because not implemented yet\n"; 
		}
};

class MachineFactory {
	public:
		static Machine* make_machine(int selection);
	private:
		static Machine* machine_prototypes[2];
};


int main(){
	int selection;
	
	Machine* machine;
	
	std::cout << "Welcome to the gym prototypePattern application\n";
	while(1){
		std::cout << "\nselect a number corresponding to the command\n0) create Treadmill \n1) create Row machine\n2) exit\n";
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
		else{
			std::cout << "unknown command, try again\n";
		}
		
	}
}

Machine* MachineFactory::machine_prototypes[] = {new Treadmill, new Row};

Machine* MachineFactory::make_machine(int selection){
	return machine_prototypes[selection]->clone();
}