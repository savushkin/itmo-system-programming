#!/bin/sh
command="make installkernel -j`sysctl hw.ncpu | awk '{print $2*2}'`"
echo ${command}
exec ${command}
