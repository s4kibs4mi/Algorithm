#!/usr/bin/env python
# -*- coding: utf-8 -*-
import random
import time
N = 10000

def InsertionSort(a):
	i = 1;
	while i<N:
		key = a[i];
		j = i-1;
		while j >= 0 and a[j] > key:
			a[j+1] = a[j];
			j-=1;
		a[j+1] = key;
		i+=1;

def main():
	a = [];
	i = 0;
	while i<N:
		a.append(random.randint(0,500));
		i+=1;
	i = 0;
	#while i<N:
	#	print a[i],' ',
	#	i+=1
	start = time.clock();
	InsertionSort(a);
	stop = time.clock();
	print '\n';
	i = 0;
	#while i<N:
	#	print a[i],' ',
	#	i+=1
	print "\n\n","Algorithm Run Time :",stop-start;
	
main();
