
/*
Name:		Muhammad Fawad Hussain Awan
Roll#		23i0719
Section:	F
Instructer: Marrium Hida
TA:			Ariyan Chaudhary
*/
#pragma once
#include"CPU.h"
#include<iostream>

#include"Computer.h"
using namespace std;
//this file contains basic classes to aggregate in computer and its assembly
//memory
class MainMemory {
private:
	int capacity;
	string technologyType;
public:
	//constructers
	MainMemory() :capacity(0), technologyType("\0"){}
	MainMemory(int c,string str):capacity(c),technologyType(str){}
	MainMemory(MainMemory& m) {
		capacity = m.capacity;
		technologyType = m.technologyType;
	}
	//getter
	int getCapacity()const {
		return capacity;
	}
	string getTechnologyType()const {
		return technologyType;
	}
	//setters
	void setCapacity(int n) {
		capacity = n;
	}
	void setTechnologyType(string str) {
		technologyType = str;
	}
};
//Physical memory
class PhysicalMemory {
private:
	int capacity;
public:
	//constructer
	PhysicalMemory() :capacity(0) {}
	PhysicalMemory(int n):capacity(n){}
	PhysicalMemory(PhysicalMemory& p):capacity(p.capacity){}
	//getter
	int getCapacity()const { return capacity; }
	//setter
	void setCapacity(int c) { capacity = c; }

};

// port
class Port {
private:
	int baud_rate;
	string type;
public:
	//constructers
	Port() :baud_rate(0), type("\0") {}
	Port(int c,string str):baud_rate(c),type(str){}
	Port(Port& p) {
		baud_rate = p.baud_rate;
		type = p.type;
	}
	//getters
	int get_BaudRate()const { return baud_rate; }
	string getType()const { return type; }
	//setters
	void set_BaudRate(int b) { baud_rate = b; }
	void setType(string str) { type = str; }
};


// Mother Board
class MotherBoard {
private:
	MainMemory mm;
	Port* ports;
	int noOfPorts;
public:
	//constructers
	MotherBoard():mm(),ports(nullptr),noOfPorts(0){}
	MotherBoard(MainMemory& m,Port*p,int n):mm(m),ports(p),noOfPorts(n){}
	MotherBoard(MainMemory& m, int n) :mm(m), noOfPorts(n) { ports = new Port[noOfPorts]; }
	//copy
	MotherBoard(MotherBoard& Board) {
		mm = Board.mm;
		if (ports != nullptr)
			delete[]ports;
		noOfPorts = Board.noOfPorts;
		ports = new Port[noOfPorts];
		for (int i = 0; i < noOfPorts; i++) {
			ports[i] = Board.ports[i];
		}
	}
	void operator = (MotherBoard& Board){
		mm = Board.mm;
		if (ports != nullptr)
			delete[]ports;
		noOfPorts = Board.noOfPorts;
		ports = new Port[noOfPorts];
		for (int i = 0; i < noOfPorts; i++) {
			ports[i] = Board.ports[i];
		}
	}
	//getter
	MainMemory& getMemory() {
		return mm;
	}
	Port* getPorts()const {
		return ports;
	}
	int getNoOfPorts()const {
		return noOfPorts;
	}
	//setter
	void setMemory(MainMemory& m) {
		mm = m;
	}
	void setPorts(Port* p, int n) {
		if (ports != nullptr)
			delete[]ports;
		noOfPorts =n;
		ports = new Port[noOfPorts];
		for (int i = 0; i < noOfPorts; i++) {
			ports[i] = p[i];
		}
	}
	//destructers
	~MotherBoard() {
		delete[]ports;
		ports = nullptr;
	}
};


//storage device
class StorageDevice {
private:
	string type;
	int capacity;
	double price;
public:
	//constructers
	StorageDevice() :type("\0"), capacity(0), price(0.0) {}
	StorageDevice(string str, int c, double p) : type(str), capacity(c), price(p) {}
	StorageDevice(StorageDevice& sd) { type = sd.type; capacity = sd.capacity; price = sd.price; }
	//getters
	string getType()const { return type; }
	int getCapacity()const { return capacity; }
	double getPrice()const { return price; }
	//setter
	void setType(string str) {
		type = str;
	}
	void setCapacity(int n) {
		capacity = n;
	}
	void setPrice(double p) {
		price = p;
	}
};
//nework card
class NetworkCard {
private:
	string type;
	int speed;
	double price;
public:
	NetworkCard() :type("\0"), speed(0), price(0.0) {}
	NetworkCard(string str, int s, double p) : type(str), speed(s), price(p) {}
	NetworkCard(NetworkCard& c) { type = c.type; speed = c.speed; price = c.price; }
	void operator=(NetworkCard& c) { type = c.type; speed = c.speed; price = c.price; }
	//getter
	string getType()const { return type; }
	int getSpeed()const { return speed; }
	double getPrice()const { return price; }
	//setter
	void setType(string str) { type = str; }
	void setSpeed(int n) { speed = n; }
	void setPrice(double d) { price = d; }
};

//PowerSupply
class PowerSupply {
private:
	int wattage;
	string efficiencyRate;
	double price;
public:
	PowerSupply() :wattage(0), efficiencyRate("\0"), price(0.0) {}
	PowerSupply(int w, string er, double d) :wattage(w), efficiencyRate(er), price(d) {}
	PowerSupply(PowerSupply& pow) { wattage = pow.wattage; efficiencyRate = pow.efficiencyRate; price = pow.price; }
	//getters
	int getWattage()const { return wattage; }
	string getEfficiencyRate()const { return efficiencyRate; }
	double getPrice()const { return price; }
	//setters
	void setWattage(int w) { wattage = w; }
	void setEfficiencyRate(string er) { efficiencyRate = er; }
	void setPrice(double p) { price = p; }

};

//battery
class Battery {
private:
	int Capacity;
public:
	Battery(int c = 0) :Capacity(c) {}
	Battery(Battery& b) { Capacity = b.Capacity; }
	//getter
	int getCapacity()const { return Capacity; }
	//setter
	void setCapacity(int c) { Capacity = c; }
};

