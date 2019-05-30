#! /bin/bash
if [ ! -d "reatrix/build/mac" ]; then
    mkdir -p reatrix/build/mac
fi
cmake reatrix/ -G "Xcode" -B reatrix/build/mac
open examples/mac/ReatrixDemo/ReatrixDemo.xcworkspace
