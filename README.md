# Priority-based Scheduler for Xv6
# Part 1: Setting up xv6
1. Download the tar file from here: https://campus.fsu.edu/bbcswebdav/pid-8463098-dt-content-rid-50739172_2/xid-50739172_2
2. Extract the tar file
    - `tar -xvf xv6-rev9.tar.gz`
3. scp the executed files to linprog
    - `scp -r xv6-public-xv6-rev9 'username'@linprog.cs.fsu.edu:/home/majors/'username'/'project directory'`
4. ssh into linprog and navigate to /'project directory'
5. Run `make` to create xv6.img
6. Run `make` qemu-nox' to run xv6 on linprog

# Part 2: Setting up GDB
1. Modify Makefile
    - Comment out the CFLAGS entry on line 77
    - Uncomment CFLAGS entry on line 78
2. `make clean`
3. `make`
4. `make qemu-nox-gdb`
5. Open another terminal session and run gdb

# Helpful tips
- Quitting xv6 shell:
    - `Ctrl-a x`

- Quitting gdb session:
    - First kill the terminal running `make qemu-nox-gdb`
    - Then kill gdb terminal with `q` then hit the `Enter` key