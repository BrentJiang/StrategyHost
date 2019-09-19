#!/usr/bin/env python


from __future__ import print_function

import sys
import h5py

# python hdf5csv.py /mnt/e/dataFile/HDF5File/FuturesTick/20190919.h5 au1912
def main():
    if sys.argv == None or len(sys.argv) < 2:
        print('Usage: <program> h5file filter')
        return
    filter = None
    input = sys.argv[1]
    output = input+'.csv'
    if len(sys.argv) == 3:
        filter = sys.argv[2]
        output = input + '.' + filter + '.csv'
    print('write to ' + output)
    print('open ' + input)
    f = h5py.File(input, 'r')
    with open(output, 'w') as of:
        for fkey in f.keys():
            print(fkey) #Names of the groups in HDF5 file.
            group = f[fkey]
            for gkey in group.keys():
                print('group:' + gkey)
                data = group[gkey]
                print(type(data))
                for i in range(len(data)):
                    line = None
                    if (i+1)%8001 == 0:
                        print('processing ' + str(i+1))
                    a = str(data[i])
                    if filter is not None:
                        place = a.find(filter)
                        if place >= 0:
                            line = a
                            place += len(filter)+3
                            # time 205900500: 
                            # 90000500
                            place2 = place + line[place:].find(',')
                            time = int(line[place:place2])
                            print(time)
                            # if time > ''
                    else:
                        line = a

                    if line is not None:
                        line = line.replace('(','').replace(')','\n')
                        of.write(line)


if __name__ == '__main__':
    main()