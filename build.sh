#!/bin/bash

os_name=$(uname)

if [[ $os_name == *"Darwin"* ]]; then
  # additional_flags="-I../lib \
  # -I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib -lopenal.1.23.1"
  additional_flags="-I../lib"
else
  additional_flags="-I../lib"
  # export BUILD_PKG_CONFIG_MODULES='openal'
fi

../lib/Core/build.sh aoc "$1" "${additional_flags[@]}"

# Capture the exit code of Core/build.sh
exit_code=$?

if [ $exit_code -ne 0 ]; then
  echo "Core/build.sh failed with exit code $exit_code"
  exit $exit_code
fi

### Post-Build Actions ###

# mkdir -p bin/fonts/
# cp ../../lib/Termin8or/fonts/* bin/fonts/

# cp deck_the_halls.ct bin/
# cp silent_night.ct bin/
# cp jingle_bells.ct bin/
# cp nigh_bethlehem.ct bin/
