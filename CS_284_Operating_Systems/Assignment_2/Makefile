# James Anderson 
# My first make file
# Some reminders:
# Commands start with TAB not spaces
# $@ is the name of the target
# $< is the first dependancy
# $? is all dependancys more recent than the target

CXX = g++

all: page_sim

page_sim: page_sim.cpp page_sim.h
	$(CXX) $< -o $@ 


clean:
	rm -f page_sim

