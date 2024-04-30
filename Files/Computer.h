
/*
Name:		Muhammad Fawad Hussain Awan
Roll#		23i0719
Section:	F
Instructer: Marrium Hida
TA:			Ariyan Chaudhary
*/
#pragma once
#include"CPU.h"
#include"Components.h"
#include <string>
#include <iostream>

using namespace std;
// this file contains main assembly functions
class Computer {
private:
	PhysicalMemory pm;
	MotherBoard mb;
	CPU cpu;
public:
	//consructers
	Computer():pm(),mb(),cpu(){}
	Computer(PhysicalMemory& p,MotherBoard& m,CPU& c):pm(p),mb(m),cpu(c){}
	Computer(Computer& comp) { pm = comp.pm; mb = comp.mb; cpu = comp.cpu; }
	//getters
	PhysicalMemory& getPM() {
		return pm;
	}
	MotherBoard& getMB() {
		return mb;
	}
	CPU& getCPU() {
		return cpu;
	}
	//setter
	void setPM(PhysicalMemory& p) {
		pm = p;
	}
	void setMB(MotherBoard& m) {
		mb = m;
	}
	void setCPU(CPU& c) {
		cpu = c;
	}
};

//case
class Case {
private:
	string formFactor;
	string color;
public:
	Case(string f="\0",string c="\0"):formFactor(f),color(c){}
	Case(Case& c) { formFactor = c.formFactor; color = c.color; }
	//getter
	string getFormFactor()const { return formFactor; }
	string getColor()const { return color; }
	//setter
	void setFormFactor(string str) { formFactor = str; }
	void setColor(string str) { color = str; }
};



//assembly
class ComputerAssembly:public Computer {
public:
	string details;
	double totalPrice;
	

	ComputerAssembly():totalPrice(0.0),Computer() {}
	//ComputerAssembly(double p = 0.0,MotherBoard m,CPU c,PhysicalMemory P) :totalPrice(p), Computer(P,m,c) {}
	//ComputerAssembly(ComputerAssembly& c) { totalPrice = c.totalPrice; }
	//getter
	double getTotalPrice()const { return totalPrice; }
	string getDetails()const { return details; }
	//setter
	void setTotalPrice(double p) { totalPrice = p; }
	
	~ComputerAssembly() {
		
	}
};

class PCAssembly :public ComputerAssembly {
private:
	Case* body;
	GraphicsCard* gpu;
	StorageDevice* drive;
	NetworkCard* net;
	PowerSupply* pow;
	Battery* bat;
public:
	PCAssembly():gpu(nullptr), pow(nullptr), bat(nullptr), body(nullptr), net(nullptr), drive(nullptr),ComputerAssembly(){}

	

	//assembly
	//Functions for Assembling computer
	bool AssemblePC(int ch) {// this function will take inputs from user and assemble PC also will reurn 1 when pc is assembled
		int choice;
		details += "\t Type: PC";
		if (ch == 1)
			details += " Desktop\n";
		if (ch == 2)
			details += " Laptop\n";
		if (ch == 3)
			details += " Tablet\n";
		//CPU
		cout << "\nSelect Type of CPU:";
		cout << "\n1.Intel\n2.AMD\n";
		cin >> choice;
		if (choice == 1) {
			details += "\nCPU: Intel\n";
			totalPrice += 2000;//tax
		}
		else if (choice == 2) {
			details += "\nCPU: AMD\n";
			totalPrice += 3500;//tax
		}
		else
			return 0;
		//components of CPU
		int n;
		float f;
		cout << "\nEnter no.of Adders\\Subtracters:";
		cin >> n;
		getCPU().getALU().set_NoOfAdders(n);
		totalPrice += n * 50 + 500;
		details += "\tAdders: " + to_string(n) + "units\n" + "\tSutracters:" + to_string(n) + "units\n";

		cout << "\nEnter no.of Registers:";
		cin >> n;
		getCPU().getALU().set_NoOfRegisters(n);
		totalPrice += n * 5 + 50;

		cout << "\nEnter  size of Registers:";
		cin >> n;
		//to bring in multiple of 32
		int nearest_multiple = (n / 32) * 32;

		// If num is closer to the next multiple
		if (n - nearest_multiple > 16)
			nearest_multiple += 32;
		getCPU().getALU().set_sizeOfRegisters(n);

		totalPrice += getCPU().getALU().get_NoOfRegisters() * getCPU().getALU().get_sizeOfRegisters() / 32;

		details += "\tRegisters: " + to_string(getCPU().getALU().get_NoOfRegisters()) + "units of size " + to_string(getCPU().getALU().get_sizeOfRegisters()) + " bits\n";

		cout << "Enter clock speed of CPU: ";
		cin >> f;
		getCPU().getCU().setClock(f);
		totalPrice += f * 5000.25;
		details += "\tClock Speed: " + to_string(f) + " GHZ\n\n";

		details += "\tPrice: Rs. " + to_string(totalPrice) + "\n\n";

		double prv = totalPrice;
		// Physical Memory
		cout << "\nEnter Capacity of Physical Memory: ";
		cin >> n;
		getPM().setCapacity(n);
		totalPrice += n * 500.25;
		details += "\nPhysicalMemory: " + to_string(n) + " GB\n\tPrice: RS. " + to_string(totalPrice - prv) + "\n";
		prv = totalPrice;
		//MotherBoard
		cout << "Give type of Main Memory:\n1.DDR3\n2.DDR4\n3.DDR5\n";
		cin >> choice;
		if (choice == 1)
			getMB().getMemory().setTechnologyType("DDR3");
		else if (choice == 2)
			getMB().getMemory().setTechnologyType("DDR4");
		else if (choice == 3)
			getMB().getMemory().setTechnologyType("DDR5");
		else
			return 0;
		cout << "\nEnter Capacity:";
		cin >> n;
		totalPrice += n * choice * 587.758;
		details += "Motherboard:\n\t Memory: " + getMB().getMemory().getTechnologyType() + " " + to_string(n) + " GB\n";

		details += "\tPorts:\n";
		cout << "Enter no. of ports:";
		cin >> n;
		Port* p = new Port[n];
		for (int i = 0; i < n; i++) {
			int k; string t;
			cout << "Enter BaudRate:";
			cin >> k;
			p->set_BaudRate(k);
			cout << "Enter port Type:";
			cin >> t;
			p->setType(t);
			totalPrice += k * 0.25;
			details += "\t\t" + t + " Port " + to_string(k) + " bps\n";
		}
		getMB().setPorts(p, n);
		delete[]p; p = nullptr;

		details += "\t Price: RS. " + to_string(totalPrice - prv) + "\n";
		prv = totalPrice;
		//for GPU
		cout << "DO you want to integerate Graphics Card(1=yes):";
		cin >> choice;
		if (choice == 1) {
			gpu = new GraphicsCard;
			cout << "Brand:\t1.NVIDIA\t2.AMD\n";
			cin >> choice;
			string t = (choice == 1) ? "NVIDIA" : "AMD";
			gpu->setBrand(t);


			cout << "Enter Memory of Card:";
			cin >> n;
			gpu->setMemorySize(n);
			gpu->setPrice(choice * 5500 + n * 700.25);
			details += "\nGraphics Card: " + to_string(n) + " GB " + t + " graphics card\n\tPrice:" + to_string(gpu->getPrice()) + "\n";
			totalPrice += gpu->getPrice();
			prv = totalPrice;
		}
		//Storage Device

		drive = new StorageDevice;
		cout << "\nStorage Type: 1.Consumer HDD\t2.SSD\t3.NAS HDD\nchoice:";
		cin >> choice;
		string t;
		if (choice == 2)
			t = "SSD";
		else if (choice == 1)
			t = "Consumer HDD";
		else if (choice == 3)
			t = "NAS HDD";
		drive->setType(t);
		cout << "Enter capacity:";
		cin >> n;
		drive->setCapacity(n);
		drive->setPrice(choice * 1000 + n * 20);
		totalPrice += drive->getPrice();
		details += "\nStorage Device: " + to_string(n) + " GB " + t + "\n\tPrice: Rs. " + to_string(drive->getPrice()) + "\n";
		//networkcard
		net = new NetworkCard;
		cout << "Enter type of network card:";
		cin >> t;
		cout << "Eneter speed of network card:";
		cin >> n;
		net->setType(t);
		net->setSpeed(n);
		net->setPrice(5.5 * 273 + t.length() * n);
		totalPrice += net->getPrice();
		details += "\nNetwork Card: " + to_string(n) + " MBPS " + t + "\n\tPrice: Rs. " + to_string(net->getPrice()) + "\n";
		//PowerSupply
		pow = new PowerSupply;
		cout << "Enter Wattage of Power Supply:";
		cin >> n;
		cout << "Enter Effiiency Rating:";
		cin >> t;
		pow->setEfficiencyRate(t);
		pow->setWattage(n);
		pow->setPrice(500.5 + n * (t.length() - 8));
		totalPrice += pow->getPrice();
		details += "\nPower Supply: " + to_string(n) + " W " + t + "\n\tPrice: Rs. " + to_string(pow->getPrice()) + "\n";
		prv = totalPrice;
		//battery
		if (ch != 1) {
			bat = new Battery;
			cout << "Enter Battery Capacity:";
			cin >> n;
			bat->setCapacity(n);
			totalPrice += n * 5.7506;
			details += "\nBattery: " + to_string(n) + " mAh  Rs. " + to_string(totalPrice - prv) + "\n";
		}
		prv = totalPrice;
		//case
		if (ch == 1) {
			body = new Case;
			cout << "Enter form factor of case:";
			cin >> t;
			body->setFormFactor(t);
			cout << "Case color:";
			cin >> t;
			body->setColor(t);
			totalPrice += (body->getColor().length() + body->getFormFactor().length()) * 100;
			details += "\n" + body->getColor() + " coloured" + body->getFormFactor() + "Case :Rs. " + to_string(totalPrice - prv) + "\n";
		}
		//returns true if build is successfull
		return 1;
	}
	~PCAssembly() {
		if (gpu != nullptr)
			delete gpu;
		if (body != nullptr)
			delete body;
		if (drive != nullptr)
			delete drive;
		if (net != nullptr)
			delete net;
		if (pow != nullptr)
			delete pow;
		if (bat != nullptr)
			delete bat;
	}
};

class MACAssembly:public ComputerAssembly {
private:
	Case* body;
	GraphicsCard* gpu;
	StorageDevice* drive;
	NetworkCard* net;
	PowerSupply* pow;
	Battery* bat;
public:
	MACAssembly() :gpu(nullptr), pow(nullptr), bat(nullptr), body(nullptr), net(nullptr), drive(nullptr) {}

	//assembly
	//Functions for Assembling computer
	bool AssembleMAC(int ch) {
		int choice;
		details += "\t Type: MAC";
		if (ch == 1)
			details += " Desktop\n";
		if (ch == 2)
			details += " Laptop\n";
		if (ch == 3)
			details += " Tablet\n";
		//CPU
		cout << "\nSelect Type of CPU:";
		cout << "\n1.AppleSillicon\n";
		cin >> choice;
		if (choice == 1) {
			details += "\nCPU: Intel\n";
			totalPrice += 5000;//tax
		}
		else
			return 0;
		//components of CPU
		int n;
		float f;
		cout << "\nEnter no.of Adders/Subtracters:";
		cin >> n;
		getCPU().getALU().set_NoOfAdders(n);
		totalPrice += n * 50 + 500;
		details += "\tAdders: " + to_string(n) + "units\n" + "\tSutracters:" + to_string(n) + "units\n";

		cout << "\nEnter no.of Registers:";
		cin >> n;
		getCPU().getALU().set_NoOfRegisters(n);
		totalPrice += n * 5 + 50;

		cout << "\nEnter  size of Registers:";
		cin >> n;
		//to bring in multiple of 32
		int nearest_multiple = (n / 32) * 32;

		// If num is closer to the next multiple
		if (n - nearest_multiple > 16)
			nearest_multiple += 32;
		getCPU().getALU().set_sizeOfRegisters(n);

		totalPrice += getCPU().getALU().get_NoOfRegisters() * getCPU().getALU().get_sizeOfRegisters() / 32;

		details += "\tRegisters: " + to_string(getCPU().getALU().get_NoOfRegisters()) + "units of size " + to_string(getCPU().getALU().get_sizeOfRegisters()) + " bits\n";

		cout << "Enter clock speed of CPU: ";
		cin >> f;
		getCPU().getCU().setClock(f);
		totalPrice += f * 5000.25;
		details += "\tClock Speed: " + to_string(f) + " GHZ\n\n";
		//for GPU

		gpu = new GraphicsCard;
		string t = "AppleGPU";
		gpu->setBrand(t);


		cout << "Enter Memory for Graphics:";
		cin >> n;
		gpu->setMemorySize(n);
		gpu->setPrice( 15000 + n * 800.25);
		details += "\n\t"+ to_string(n) + " GB " + t + " graphics card\n";
		totalPrice += gpu->getPrice();
		

		details += "\tPrice: Rs. " + to_string(totalPrice) + "\n\n";

		double prv = totalPrice;
		// Physical Memory
		cout << "\nEnter Capacity of Physical Memory: ";
		cin >> n;
		getPM().setCapacity(n);
		totalPrice += n * 500.25;
		details += "\nPhysicalMemory: " + to_string(n) + " GB\n\tPrice: RS. " + to_string(totalPrice - prv) + "\n";
		prv = totalPrice;
		//MotherBoard
		cout << "Give type of Main Memory:\n1.LPDDR3\n2.LPDDR4\n3.LPDDR5\n";
		cin >> choice;
		if (choice == 1)
			getMB().getMemory().setTechnologyType("LPDDR3");
		else if (choice == 2)
			getMB().getMemory().setTechnologyType("LPDDR4");
		else if (choice == 3)
			getMB().getMemory().setTechnologyType("LPDDR5");
		else
			return 0;
		cout << "\nEnter Capacity:";
		cin >> n;
		totalPrice += n * choice * 387.758;
		details += "Motherboard:\n\t Memory: " + getMB().getMemory().getTechnologyType() + " " + to_string(n) + " GB\n";

		details += "\tPorts:\n";
		cout << "Enter no. of ports:";
		cin >> n;
		Port* p = new Port[n];
		for (int i = 0; i < n; i++) {
			int k; string t;
			cout << "Enter BaudRate:";
			cin >> k;
			p->set_BaudRate(k);
			cout << "Enter port Type:";
			cin >> t;
			p->setType(t);
			totalPrice += k * 0.25;
			details += "\t\t" + t + " Port " + to_string(k) + " bps\n";
		}
		getMB().setPorts(p, n);
		delete[]p; p = nullptr;

		details += "\t Price: RS. " + to_string(totalPrice - prv) + "\n";
		prv = totalPrice;
		
		//Storage Device

		drive = new StorageDevice;
		cout << "\nStorage Type: 1.Consumer HDD\t2.SSD\t3.NAS HDD\nchoice:";
		cin >> choice;
		//string t;
		if (choice == 2)
			t = "SSD";
		else if (choice == 1)
			t = "Consumer HDD";
		else if (choice == 3)
			t = "NAS HDD";
		drive->setType(t);
		cout << "Enter capacity:";
		cin >> n;
		drive->setCapacity(n);
		drive->setPrice(choice * 1000 + n * 20);
		totalPrice += drive->getPrice();
		details += "\nStorage Device: " + to_string(n) + " GB " + t + "\n\tPrice: Rs. " + to_string(drive->getPrice()) + "\n";
		//networkcard
		net = new NetworkCard;
		cout << "Enter type of network card:";
		cin >> t;
		cout << "Eneter speed of network card:";
		cin >> n;
		net->setType(t);
		net->setSpeed(n);
		net->setPrice(5.5 * 273 + t.length() * n);
		totalPrice += net->getPrice();
		details += "\nNetwork Card: " + to_string(n) + " MBPS " + t + "\n\tPrice: Rs. " + to_string(net->getPrice()) + "\n";
		//PowerSupply
		pow = new PowerSupply;
		cout << "Enter Wattage of Power Supply:";
		cin >> n;
		cout << "Enter Effiiency Rating:";
		cin >> t;
		pow->setEfficiencyRate(t);
		pow->setWattage(n);
		pow->setPrice(500 + n * (t.length() - 8));
		totalPrice += pow->getPrice();
		details += "\nPower Supply: " + to_string(n) + " W " + t + "\n\tPrice: Rs. " + to_string(pow->getPrice()) + "\n";
		prv = totalPrice;
		//battery
		if (ch != 1) {
			bat = new Battery;
			cout << "Enter Battery Capacity:";
			cin >> n;
			bat->setCapacity(n);
			totalPrice += n * 5.7506;
			details += "\nBattery: " + to_string(n) + " mAh  Rs. " + to_string(totalPrice - prv) + "\n";
		}
		prv = totalPrice;
		//case
		if (ch == 1) {
			body = new Case;
			cout << "Enter form factor of case:";
			cin >> t;
			body->setFormFactor(t);
			cout << "Case color:";
			cin >> t;
			body->setColor(t);
			totalPrice += (body->getColor().length() + body->getFormFactor().length()) * 100;
			details += "\n" + body->getColor() + " coloured" + body->getFormFactor() + "Case :Rs. " + to_string(totalPrice - prv) + "\n";
		}
		//returns true if build is successfull
		return 1;
	}
	~MACAssembly() {
		if (gpu != nullptr)
			delete gpu;
		if (body != nullptr)
			delete body;
		if (drive != nullptr)
			delete drive;
		if (net != nullptr)
			delete net;
		if (pow != nullptr)
			delete pow;
		if (bat != nullptr)
			delete bat;
	}
};