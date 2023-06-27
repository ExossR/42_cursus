#!/bin/bash

gcc -c *c
ar cr libft.a *.o
ranlib libft.a
