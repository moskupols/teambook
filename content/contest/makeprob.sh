#!/usr/bin/bash
prob = $1
mkdir $prob && cp template/Makefile $1 && cp template/template.cpp $1/$1.cpp && mkdir $1/tests
