ATMEL_BOARDS="arduino_zero cplay_m0_flash feather_m0_basic feather_m0_adalogger feather_m0_flash metro_m0_flash trinket_m0 gemma_m0"
UF2_CONV=~/repos/uf2/utils/uf2conv.py

version=$1

for board in $ATMEL_BOARDS; do
    $UF2_CONV -c -o bin/adafruit-circuitpython-$board-$version.uf2 bin/adafruit-circuitpython-$board-$version.bin
done
