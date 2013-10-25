#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random,time

N = 10000 # amount of data to be sort
a = []

def swap(x,y):
	return y,x

def partition(a,p,r):
	x = a[r]
	i = p-1
	j = p
	while j<r:
		if a[j] <= x:
			i+=1
			a[i],a[j] = swap(a[i],a[j])
		j+=1
	a[i+1],a[r] = swap(a[i+1],a[r])
	return i+1

def quick_sort(a,p,r):
	if p < r:
		q = partition(a,p,r)
		quick_sort(a,p,q-1)
		quick_sort(a,q+1,r)

def gen_value():
	i=0
	while i<N:
		a.append(random.randint(0,100))
		i+=1

def Display():
	i=0
	while i<N:
		print a[i],' ',
		i+=1
	print '\n'

gen_value()
# Display()
start = time.clock()
quick_sort(a,0,N-1)
stop = time.clock()
# Display()

print 'Required time to sort : ',(stop - start)
