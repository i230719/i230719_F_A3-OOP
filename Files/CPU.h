
/*
Name:		Muhammad Fawad Hussain Awan
Roll#		23i0719
Section:	F
Instructer: Marrium Hida
TA:			Ariyan Chaudhary
*/
#pragma once
#include<iostream>
#include"Components.h"
using namespace std;


// ALU
class ALU {
private:
	int NoOfAdders;
	int NoOfSubtractor;
	int NoOfRegisters;
	int sizeOfRegisters;
public:
	//constructers
	ALU() : NoOfAdders(0), NoOfSubtractor(0), NoOfRegisters(0), sizeOfRegisters(0) {}
	ALU(int a=0,int s=0,int r=0,int sr=0): NoOfAdders(a),NoOfSubtractor(s),NoOfRegisters(r),sizeOfRegisters(sr) {}
	ALU(ALU& alu){
		NoOfAdders = alu.NoOfAdders;
		NoOfSubtractor = (alu.NoOfSubtractor);
		NoOfRegisters = (alu.NoOfRegisters);
		sizeOfRegisters = (alu.sizeOfRegisters);
	}
	void operator =(ALU& alu) {
		NoOfAdders = alu.NoOfAdders;
		NoOfSubtractor = (alu.NoOfSubtractor);
		NoOfRegisters = (alu.NoOfRegisters);
		sizeOfRegisters = (alu.sizeOfRegisters);
	}
	//setters
	void set_NoOfAdders(int n) {
		NoOfAdders = n;
	}
	void set_NoOfSubtractor(int n) {
		NoOfSubtractor = n;
	}
	void set_NoOfRegisters(int n) {
		NoOfRegisters = n;
	}
	void set_sizeOfRegisters(int n) {
		sizeOfRegisters = n;
	}
	//getters 
	int get_NoOfAdders() const{
		return NoOfAdders;
	}
	int get_NoOfSubtractor() const {
		return NoOfSubtractor;
	}
	int get_NoOfRegisters() const {
		return NoOfRegisters;
	}
	int get_sizeOfRegisters() const {
		return sizeOfRegisters;
	}
};

//CU
class ControlUnit {
private:
	float clock;
public:
	//constructer
	ControlUnit():clock(0.0){}
	ControlUnit(float c):clock(c){}
	ControlUnit(ControlUnit&cu){
		clock = (cu.clock);
	}
	//getter
	float getClock()const {
		return clock;
	}
	//setter
	void setClock(float c) {
		clock = c;
	}
};
//CPU
class CPU {
private:
	ALU alu;
	ControlUnit cu;
public:
	//constructers
	CPU():alu(0,0,0,0),cu(0.0){}
	CPU(ALU&a,ControlUnit&c):alu(a),cu(c){}

	void operator =(CPU& c){
		alu = c.alu;
		cu = c.cu;
	}
	//Getter
	ALU& getALU() {
		return alu;
	}
	ControlUnit& getCU() {
		return cu;
	}
	//setters
	void setALU(ALU& a) {
		alu = a;
	}
	void setCU(ControlUnit& c) {
		cu = c;
	}
};

//graphics card

class GraphicsCard {
private:
	string brand;
	int memorySize;
	double price;
public:
	//constructers
	GraphicsCard() :brand("\0"), memorySize(0), price(0.0) {}
	GraphicsCard(string str, int mm, double p) :brand(str), memorySize(mm), price(p) {}
	GraphicsCard(GraphicsCard& gc) {
		brand = gc.brand;
		memorySize = gc.memorySize;
		price = gc.price;
	}
	void operator=(GraphicsCard& gc) {
		brand = gc.brand;
		memorySize = gc.memorySize;
		price = gc.price;
	}
	//getters
	string getBrand()const { return brand; }
	int getMemorySize()const { return memorySize; }
	double getPrice()const { return price; }
	//setters
	void setBrand(string str) {
		brand = str;
	}
	void setMemorySize(int n) {
		memorySize = n;
	}
	void setPrice(double p) {
		price = p;
	}

};

