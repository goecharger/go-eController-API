This program automatically fixes table column widths and counts modbus register numbers up, uses the right number of modbus registers for each datatype, allows to skip modbus registers.

# How to use
```
git clone git@github.com:goecharger/go-eController-API.git
mkdir build
cd build/
qmake ../docshelper/
make -j4
cd ..
build/docshelper modbus-de.md
build/docshelper modbus-en.md
```

Do not move existing register numbers, always add new registers in reserved spaces or at the end.
