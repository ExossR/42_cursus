#!/bin/bash

find . -type f -iname "*.sh" | awk -F/ '{print $NF}' | sed "s/\.sh$//g"
