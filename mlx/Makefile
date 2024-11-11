##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script


all	: do_configure

do_configure :
	@echo "Running ./configure"
	@(./configure > configure.log 2>&1; exit 0)
	@tail -n +2 configure.log

clean	:
	./configure clean

re	: clean all
