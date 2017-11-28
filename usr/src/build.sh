#!/bin/sh
command="make buildkernel -j`sysctl hw.ncpu | awk '{print $2*2}'` -DKERNFAST"
echo ${command}
exec ${command}
